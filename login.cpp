#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);

    if(!connOpen())
        ui->label->setText("Disconnected");
    else
        ui->label->setText("Connected");
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString username, password;
    username=ui->lineEdit_username->text();
    password=ui->lineEdit_password->text();

    if(!connOpen()){
        qDebug()<<"Failed to open database";
        return;
    }

    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from admininfo where name='"+username+"' and password='"+password+"'");


    if(qry.exec( )){
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if (count==1){
            ui->label->setText("username and password is correct");
            connClose();
            this->hide();
            MainWindow *mainwindow = new MainWindow();
            mainwindow->show();

        }
        if (count>1)
            ui->label->setText("duplicate username and password");
        if (count<1)
            ui->label->setText("wrong password or username");
    }


}

