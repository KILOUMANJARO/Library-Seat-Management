#include "reg.h"
#include "ui_reg.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QSqlDatabase>
#include <QRegularExpressionValidator>

reg::reg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::reg)
{
    ui->setupUi(this);

    // Set lineEdit_seat to read-only
    ui->lineEdit_seat->setReadOnly(true);

    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName("c:/Users/klbor/Downloads/cppbuzz_movie_ticket_booking.sqlite");

    if (QFile::exists("c:/Users/klbor/Downloads/cppbuzz_movie_ticket_booking.sqlite"))
        qDebug() << "DB file exists";
    else
        qDebug() << "DB file doesn't exist";

    if (!DB_Connection.open()) {
        qDebug() << "Failed to open database: " << DB_Connection.lastError().text();
    } else {
        qDebug() << "Database connected";
    }

    connect(ui->lineEdit_upid, &QLineEdit::textChanged, this, &reg::on_upidTextChanged);
    connect(ui->lineEdit_name, &QLineEdit::textChanged, this, &reg::onTextChanged);
    connect(ui->lineEdit_seat, &QLineEdit::textChanged, this, &reg::onTextChanged);
    connect(ui->lineEdit_credit, &QLineEdit::textChanged, this, &reg::onTextChanged);
    connect(ui->lineEdit_credit, &QLineEdit::textChanged, this, &reg::onCreditTextChanged);

    connect(ui->submitButton, &QPushButton::clicked, this, &reg::on_submitButton_clicked);
    connect(ui->updateButton, &QPushButton::clicked, this, &reg::on_updateButton_clicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &reg::on_deleteButton_clicked);

    ui->submitButton->setEnabled(areAllLineEditsFilled());
    ui->updateButton->setEnabled(isUPIDFilled());
    ui->deleteButton->setEnabled(isUPIDFilled());

// Set up validator for lineEdit_upid (Use the appropriate one for your Qt version)
#if QT_VERSION >= QT_VERSION_CHECK(5, 15, 0)
    QRegularExpression rx("^[0-9-]+$");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
#else
    QRegExp rx("^[0-9-]+$");
    QValidator *validator = new QRegExpValidator(rx, this);
#endif
    ui->lineEdit_upid->setValidator(validator);
}

void reg::onCreditTextChanged()
{
    bool ok;
    int value = ui->lineEdit_credit->text().toInt(&ok);
    if (ok) {
        if (value > 100) {
            ui->lineEdit_credit->setText("100");
        } else if (value < 0) {
            ui->lineEdit_credit->setText("0");
        }
    }
}
reg::~reg()
{
    if (DB_Connection.isOpen()) {
        DB_Connection.close();
    }
    delete ui;
}

void reg::updateUI()
{
    on_showButton_clicked();
}

void reg::onTextChanged()
{
    ui->submitButton->setEnabled(areAllLineEditsFilled());
    ui->updateButton->setEnabled(isUPIDFilled());
    ui->deleteButton->setEnabled(isUPIDFilled());
}

bool reg::areAllLineEditsFilled() const
{
    return !ui->lineEdit_upid->text().isEmpty() &&
           !ui->lineEdit_name->text().isEmpty() &&
           !ui->lineEdit_credit->text().isEmpty();
}

bool reg::isUPIDFilled() const
{
    return !ui->lineEdit_upid->text().isEmpty();
}

void reg::clearTextFields()
{
    ui->lineEdit_upid->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_seat->clear();
    ui->lineEdit_credit->clear();
}

void reg::on_submitButton_clicked()
{
    ui->submitButton->setEnabled(false); // Disable the button to prevent double clicks
    DB_Connection.open();
    QSqlDatabase::database().transaction();

    QSqlQuery QueryCheckExistence(DB_Connection);
    QueryCheckExistence.prepare("SELECT COUNT(*) FROM profiles WHERE upid = :upid");
    QueryCheckExistence.bindValue(":upid", ui->lineEdit_upid->text());
    QueryCheckExistence.exec();
    QueryCheckExistence.next();

    int count = QueryCheckExistence.value(0).toInt();
    if (count > 0) {
        qDebug() << "Entry with upid" << ui->lineEdit_upid->text() << "already exists.";
        ui->label_status->setText("Existing");
        // You can display an error message or take appropriate action here
        DB_Connection.rollback();
        DB_Connection.close();
        ui->submitButton->setEnabled(true); // Re-enable the button after operation
        return;
    }

    QSqlQuery QueryInsertData(DB_Connection);
    QueryInsertData.prepare("INSERT INTO profiles (upid, name, seat, credit) VALUES (:upid, :name, :seat, :credit)");
    QueryInsertData.bindValue(":upid", ui->lineEdit_upid->text());
    QueryInsertData.bindValue(":name", ui->lineEdit_name->text());
    QueryInsertData.bindValue(":seat", ui->lineEdit_seat->text());
    QueryInsertData.bindValue(":credit", ui->lineEdit_credit->text());

    if (!QueryInsertData.exec()) {
        qDebug() << "Insert query failed: " << QueryInsertData.lastError().text();
        ui->label_status->setText("Failed");
        DB_Connection.rollback();
    } else {
        DB_Connection.commit();
        qDebug() << "Data inserted successfully";
        ui->label_status->setText("Existing");
        clearTextFields();
    }

    DB_Connection.close();
    ui->submitButton->setEnabled(true); // Re-enable the button after operation
    updateUI();
}

void reg::on_updateButton_clicked()
{
    DB_Connection.open();
    if (!DB_Connection.isOpen()) {
        qDebug() << "Failed to open database for update operation";
        return;
    }

    QSqlDatabase::database().transaction();

    QSqlQuery QueryUpdateData(DB_Connection);
    QueryUpdateData.prepare("UPDATE profiles SET name=:name, seat=:seat, credit=:credit WHERE upid=:upid");
    QueryUpdateData.bindValue(":name", ui->lineEdit_name->text());
    QueryUpdateData.bindValue(":seat", ui->lineEdit_seat->text());
    QueryUpdateData.bindValue(":credit", ui->lineEdit_credit->text());
    QueryUpdateData.bindValue(":upid", ui->lineEdit_upid->text());

    if (!QueryUpdateData.exec()) {
        qDebug() << "Update query failed: " << QueryUpdateData.lastError().text();
        ui->label_status->setText("Failed");
        DB_Connection.rollback();
    } else {
        DB_Connection.commit();
        qDebug() << "Data updated successfully";
        ui->label_status->setText("Updated");
        clearTextFields();
    }

    DB_Connection.close();
    updateUI();
}


void reg::on_deleteButton_clicked()
{
    DB_Connection.open();
    if (!DB_Connection.isOpen()) {
        qDebug() << "Failed to open database for delete operation";
        return;
    }

    QSqlQuery QueryDeleteData(DB_Connection);
    QueryDeleteData.prepare("DELETE FROM profiles WHERE upid=:upid");
    QueryDeleteData.bindValue(":upid", ui->lineEdit_upid->text());

    if (!QueryDeleteData.exec()) {
        qDebug() << "Delete query failed: " << QueryDeleteData.lastError().text();
        ui->label_status->setText("Failed");
        DB_Connection.rollback();
    } else {
        DB_Connection.commit();
        qDebug() << "Data deleted successfully";
        ui->label_status->setText("Deleted");
        clearTextFields();
    }

    DB_Connection.close();
    updateUI();
}

void reg::on_showButton_clicked()
{
    DB_Connection.open();
    if (!DB_Connection.isOpen()) {
        qDebug() << "Failed to open database for show operation";
        return;
    }

    QSqlQuery QueryShowData(DB_Connection);
    QueryShowData.prepare("SELECT * FROM profiles");

    if (!QueryShowData.exec()) {
        qDebug() << "Show query failed: " << QueryShowData.lastError().text();
        DB_Connection.rollback();
    } else {
        ui->tableWidget->setRowCount(0); // Clear the table before adding new data
        int RowNumber = 0;
        while(QueryShowData.next()) {
            ui->tableWidget->insertRow(RowNumber);
            QTableWidgetItem* upidItem = new QTableWidgetItem(QueryShowData.value("upid").toString());
            upidItem->setFlags(upidItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(RowNumber, 0, upidItem);

            QTableWidgetItem* nameItem = new QTableWidgetItem(QueryShowData.value("name").toString());
            nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(RowNumber, 1, nameItem);

            QTableWidgetItem* seatItem = new QTableWidgetItem(QueryShowData.value("seat").toString());
            seatItem->setFlags(seatItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(RowNumber, 2, seatItem);

            QTableWidgetItem* creditItem = new QTableWidgetItem(QueryShowData.value("credit").toString());
            creditItem->setFlags(creditItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(RowNumber, 3, creditItem);

            RowNumber++;
        }
    }

    DB_Connection.close();
}

void reg::on_upidTextChanged(const QString &upid)
{
    if (upid.isEmpty()) {
        ui->lineEdit_name->clear();
        ui->lineEdit_seat->clear();
        ui->lineEdit_credit->clear();
        return;
    }

    DB_Connection.open();
    if (!DB_Connection.isOpen()) {
        qDebug() << "Failed to open database for UPID check";
        return;
    }

    QSqlQuery QueryCheckUPID(DB_Connection);
    QueryCheckUPID.prepare("SELECT name, seat, credit FROM profiles WHERE upid = :upid");
    QueryCheckUPID.bindValue(":upid", upid);

    if (!QueryCheckUPID.exec()) {
        qDebug() << "UPID query failed: " << QueryCheckUPID.lastError().text();
    } else {
        if (QueryCheckUPID.next()) {
            ui->lineEdit_name->setText(QueryCheckUPID.value("name").toString());
            ui->lineEdit_seat->setText(QueryCheckUPID.value("seat").toString());
            ui->lineEdit_credit->setText(QueryCheckUPID.value("credit").toString());
        } else {
            ui->lineEdit_name->clear();
            ui->lineEdit_seat->clear();
            ui->lineEdit_credit->clear();
        }

    }

    DB_Connection.close();
}
