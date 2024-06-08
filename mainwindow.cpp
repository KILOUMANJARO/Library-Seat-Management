#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ptrBook  = new book(this);
    ptrCancel = new cancel(this);
    ptrReg = new reg(this);
    ptrPlotting = new plotting(this);

    connect(ptrBook, &book::mysignal, this, &MainWindow::updateUI);
    connect(ptrCancel, &cancel::mysignal1, this, &MainWindow::updateUI);
    connect(ptrReg, &reg::mysignal2, this, &MainWindow::updateUI);
    connect(ptrPlotting, &plotting::mysignal3, this, &MainWindow::updateUI);

    updateUI();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrBook;
    delete ptrCancel;
    delete ptrReg;
    delete ptrPlotting;
}

void MainWindow::updateUI()
{
    qDebug() << "in updateUI()";

    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("select Seat, Available from cppbuzz_movie_ticket_booking");

    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        //ui->lblInfo->setText(query.lastError().text());
    }
    else{
        qDebug() << "read was successful " << query.lastQuery();
    }

    while(query.next())
    {
        QString sLabel = "lbl" + query.value(0).toString();
        qDebug() << "label is : " << sLabel;
        QLabel * ptr = this->findChild<QLabel*>(sLabel);
        if(ptr != nullptr)
        {
            qDebug() << "label found " << sLabel;
            if(query.value(1).toString().compare("N") == 0)
            {
                QPixmap pm(":/assets/img/booked.jpg");
                ptr->setPixmap(pm);
                ptr->setScaledContents(true);
                ptr->setToolTip("Seat " + query.value(0).toString() + " is booked");
                qDebug() << query.value(0).toString() << " : is booked";
            }
            else
            {
                QPixmap pm(":/assets/img/available.jpg");
                ptr->setPixmap(pm);
                ptr->setScaledContents(true);
                ptr->setToolTip("Seat " + query.value(0).toString() + " is available");
                qDebug() << query.value(0).toString() << " : is Available";
            }
        }
    }
}

void MainWindow::on_btnBook_clicked()
{
    ptrBook->updateUI();
    ptrBook->show();
}

void MainWindow::on_btnCancel_clicked()
{
    ptrCancel->updateUI();
    ptrCancel->show();
}

void MainWindow::on_pushButton_clicked()
{
    ptrReg->updateUI();
    ptrReg->show();
}

void MainWindow::on_btnReset_clicked()
{
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("UPDATE cppbuzz_movie_ticket_booking SET Available = 'Y'");

    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
    }
    else
    {
        if(query.numRowsAffected() > 0)
        {
            qDebug() << "Update was successful. " << query.lastQuery();
        }
        else
        {
            qDebug() << "Update Failed. " << query.lastQuery();
        }
    }

    query.prepare("UPDATE profiles SET seat = ''");

    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        //ui->lblInfo->setText(query.lastError().text());
    }
    else
    {
        if(query.numRowsAffected() > 0)
        {
            qDebug() << "Update was successful. " << query.lastQuery();
        }
        else
        {
            qDebug() << "Update Failed. " << query.lastQuery();
        }
    }

    updateUI();
}


void MainWindow::on_btnPlot_clicked()
{
    ptrPlotting->updateUI();
    ptrPlotting->exec(); // exec() instead of show() to make it a modal dialog
}
