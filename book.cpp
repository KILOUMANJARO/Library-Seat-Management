#include "book.h"
#include "ui_book.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QRegularExpressionValidator> // For Qt 5.15 and newer
#include <ctime>

book::book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::book)
{
    ui->setupUi(this);
// Set up validator for lineEdit (Use the appropriate one for your Qt version)
#if QT_VERSION >= QT_VERSION_CHECK(5, 15, 0)
    QRegularExpression rx("^[0-9-]+$");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
#else
    QRegExp rx("^[0-9-]+$");
    QValidator *validator = new QRegExpValidator(rx, this);
#endif
    ui->lineEdit->setValidator(validator);

    connect(ui->lineEdit, &QLineEdit::textChanged, this, &book::onTextChanged);
    connect(ui->btnBook, &QPushButton::clicked, this, &book::on_btnBook_clicked);

    // Initially disable the button if the QLineEdit is empty
    ui->btnBook->setEnabled(false);

    // Clear the input when the dialog is constructed
    clearInputs();
}

book::~book()
{
    delete ui;
}

void book::clearInputs()
{
    ui->lineEdit->clear();
    ui->lblInfo->clear();
    ui->btnBook->setEnabled(false);
}

void book::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    clearInputs();
    updateUI();
}

void book::updateUI()
{
    ui->cmbSeats->clear();

    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("select Seat from cppbuzz_movie_ticket_booking where Available='Y'");

    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText(query.lastError().text());
    }
    else{
        qDebug() << "read was successful "<< query.lastQuery();
    }

    while(query.next())
    {
        ui->cmbSeats->addItem(query.value(0).toString());
    }

    if(ui->cmbSeats->count()<=0)
        ui->btnBook->setEnabled(false);
}

void book::on_btnBook_clicked()
{
    QString sSeat = ui->cmbSeats->currentText();
    QString upid = ui->lineEdit->text();

    // Check if UPID already has a seat assigned
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("SELECT seat FROM profiles WHERE upid = :upid");
    query.bindValue(":upid", upid);

    if (!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText(query.lastError().text());
        return;
    }

    if (query.next() && !query.value(0).toString().isEmpty())
    {
        return;
    }

    // Check user credit
    query.prepare("SELECT credit FROM profiles WHERE upid = :upid");
    query.bindValue(":upid", upid);
    if (!query.exec() || !query.next()) {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText(query.lastError().text());
        return;
    }

    int credit = query.value(0).toInt();
    if (credit < 60) {
        ui->lblInfo->setText("Low Credit");
        return;
    }

    // Update seat availability
    query.prepare("update cppbuzz_movie_ticket_booking set Available='N' where Seat= :sSeat");
    query.bindValue(":sSeat", sSeat);

    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText(query.lastError().text());
        return;
    }

    // Deduct credit
    query.prepare("UPDATE profiles SET credit = credit - 10 WHERE upid = :upid");
    query.bindValue(":upid", upid);
    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText(query.lastError().text());
        return;
    }

    // Assign seat to UPID
    query.prepare("UPDATE profiles SET seat = :sSeat WHERE upid = :upid");
    query.bindValue(":sSeat", sSeat);
    query.bindValue(":upid", upid);
    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText(query.lastError().text());
        return;
    }

    // Increment booking count for the current 15-minute interval
    incrementBookingCount();

    ui->lblInfo->setText("Success");
    qDebug() << "Update successful";

    updateUI();
    emit mysignal();
}

void book::checkUpidValidity(const QString &upid)
{
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("SELECT * FROM profiles WHERE upid = :upid");
    query.bindValue(":upid", upid);

    if (!query.exec() || !query.next()) {
        ui->lblInfo->setText("Invalid");
        ui->btnBook->setEnabled(false);
    } else {
        ui->lblInfo->setText("Valid");
        ui->btnBook->setEnabled(true);
    }
}

void book::onTextChanged(const QString &text)
{
    // Enable the button only if the QLineEdit is not empty
    ui->btnBook->setEnabled(!text.isEmpty());

    // Call the function to check upid validity
    checkUpidValidity(text);
}

void book::incrementBookingCount()
{
    QSqlQuery query(MyDB::getInstance()->getDBInstance());

    // Get the current time
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int hour = ltm->tm_hour;
    int minute = ltm->tm_min;

    // Round to the nearest 15-minute interval
    if (minute < 15)
    {
        minute = 0;
    }
    else
    {
        minute = 15;
    }

    QString currentTime = QString::number(hour).rightJustified(2, '0') + ":" +
                          QString::number(minute).rightJustified(2, '0');

    // Check if there's an entry for the current time interval
    query.prepare("SELECT count FROM bookings WHERE time = :currentTime");
    query.bindValue(":currentTime", currentTime);

    if (!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        return;
    }

    if (query.next())
    {
        // Update the count if the entry exists
        int count = query.value(0).toInt();
        query.prepare("UPDATE bookings SET count = :count WHERE time = :currentTime");
        query.bindValue(":count", count + 1);
        query.bindValue(":currentTime", currentTime);
    }
    else
    {
        // Insert a new entry if it doesn't exist
        query.prepare("INSERT INTO bookings (count, time) VALUES (1, :currentTime)");
        query.bindValue(":currentTime", currentTime);
    }

    if (!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
    }
}
