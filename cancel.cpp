#include "cancel.h"
#include "ui_cancel.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTimer> // Include QTimer header

cancel::cancel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cancel)
{
    ui->setupUi(this);

    connect(ui->btnCancel, &QPushButton::clicked, this, &cancel::on_btnCancel_clicked);
    connect(ui->cmbSeats, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &cancel::updateUPID); // Corrected
    // Initially disable the button if there are no seats to cancel
    ui->btnCancel->setEnabled(false);

    // Make lineEdit_upid read-only to prevent user input
    ui->lineEdit_upid->setReadOnly(true);

    // Call updateUI to populate seats and fetch upid for initially selected seat
    updateUI();

    // Set the upid for the initially selected seat
    QString initialSeat = ui->cmbSeats->currentText();
    setUPID(initialSeat);
}

cancel::~cancel()
{
    delete ui;
}

void cancel::updateUI()
{
    ui->cmbSeats->clear();
    //ui->lblInfo->setText("");

    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("select Seat from cppbuzz_movie_ticket_booking where Available='N'");

    if (!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText(query.lastError().text());
    }
    else
    {
        qDebug() << "read was successful " << query.lastQuery();
    }

    while (query.next())
    {
        ui->cmbSeats->addItem(query.value(0).toString());
    }

    if (ui->cmbSeats->count() <= 0) {
        ui->btnCancel->setEnabled(false);
        // If there are no seats available, clear the combo box selection
        ui->cmbSeats->setCurrentIndex(-1);
    }
    else {
        ui->btnCancel->setEnabled(true);
    }
}

void cancel::setUPID(const QString &sSeat)
{
    QString upid;

    QSqlQuery query(MyDB::getInstance()->getDBInstance());

    // Find the upid associated with the seat
    query.prepare("SELECT upid FROM profiles WHERE seat = :sSeat");
    query.bindValue(":sSeat", sSeat);

    if (!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText(query.lastError().text());
        return;
    }

    if (query.next())
    {
        upid = query.value(0).toString();
        // Display the upid in the lineEdit_upid
        ui->lineEdit_upid->setText(upid);
    }
    else
    {
        ui->lblInfo->setText("Unclaimed");
        return;
    }
}

void cancel::updateUPID(int newIndex) // Corrected signature
{
    Q_UNUSED(newIndex);
    QString newSeat = ui->cmbSeats->currentText();
    // Update the upid when the seat is changed
    setUPID(newSeat);

}

void cancel::on_btnCancel_clicked()
{
    QString sSeat = ui->cmbSeats->currentText();
    QString upid;

    QSqlQuery query(MyDB::getInstance()->getDBInstance());

    // First, find the upid associated with the seat being cancelled
    query.prepare("SELECT upid FROM profiles WHERE seat = :sSeat");
    query.bindValue(":sSeat", sSeat);

    if (!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText(query.lastError().text());
        return;
    }

    if (query.next())
    {
        upid = query.value(0).toString();
        // Display the upid in the lineEdit_upid
        ui->lineEdit_upid->setText(upid);
    }
    else
    {
        ui->lblInfo->setText("Unclaimed");
        return;
    }

    // Now clear the seat assignment in the profiles table
    query.prepare("UPDATE profiles SET seat = '' WHERE upid = :upid");
    query.bindValue(":upid", upid);

    if (!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText(query.lastError().text());
        return;
    }

    // Update the profiles table to add 12 credits to the upid
    query.prepare("UPDATE profiles SET credit = credit + 12 WHERE upid = :upid");
    query.bindValue(":upid", upid);

    if (!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText(query.lastError().text());
        return;
    }

    // Now, cancel the seat by updating the booking table
    query.prepare("UPDATE cppbuzz_movie_ticket_booking SET Available = 'Y' WHERE Seat = :sSeat");
    query.bindValue(":sSeat", sSeat);

    if (!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText(query.lastError().text());
    }
    else
    {
        if (query.numRowsAffected() > 0)
        {
            ui->lblInfo->setText("Success!");
            qDebug() << "Update successful " << query.lastQuery();
        }
        else
        {
            ui->lblInfo->setText("Unable to update data");
        }
    }

    emit mysignal1();

    // Add a 3-second cooldown
    QTimer::singleShot(3000, this, [=](){
        // Additional code to execute after 3 seconds
        // For example, enable the cancel button again
        // ui->btnCancel->setEnabled(true);
    });
}
