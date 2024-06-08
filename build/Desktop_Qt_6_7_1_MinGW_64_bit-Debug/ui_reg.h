/********************************************************************************
** Form generated from reading UI file 'reg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REG_H
#define UI_REG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reg
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_upid;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QLabel *label_3;
    QLineEdit *lineEdit_seat;
    QLabel *label_4;
    QLineEdit *lineEdit_credit;
    QTableWidget *tableWidget;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *submitButton;
    QPushButton *updateButton;
    QPushButton *deleteButton;
    QLabel *label_status;

    void setupUi(QDialog *reg)
    {
        if (reg->objectName().isEmpty())
            reg->setObjectName("reg");
        reg->resize(499, 395);
        layoutWidget = new QWidget(reg);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 25, 231, 120));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(15);
        gridLayout->setVerticalSpacing(7);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_upid = new QLineEdit(layoutWidget);
        lineEdit_upid->setObjectName("lineEdit_upid");
        lineEdit_upid->setClearButtonEnabled(false);

        gridLayout->addWidget(lineEdit_upid, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName("lineEdit_name");

        gridLayout->addWidget(lineEdit_name, 1, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_seat = new QLineEdit(layoutWidget);
        lineEdit_seat->setObjectName("lineEdit_seat");
        lineEdit_seat->setMinimumSize(QSize(0, 22));
        lineEdit_seat->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color: rgb(225, 225, 225);\n"
"	border: 1px solid rgb(173, 173, 173);\n"
"\n"
"}"));
        lineEdit_seat->setReadOnly(false);

        gridLayout->addWidget(lineEdit_seat, 2, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_credit = new QLineEdit(layoutWidget);
        lineEdit_credit->setObjectName("lineEdit_credit");

        gridLayout->addWidget(lineEdit_credit, 3, 1, 1, 1);

        tableWidget = new QTableWidget(reg);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(30, 175, 441, 192));
        layoutWidget1 = new QWidget(reg);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(390, 20, 81, 128));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        submitButton = new QPushButton(layoutWidget1);
        submitButton->setObjectName("submitButton");
        submitButton->setMaximumSize(QSize(78, 16777215));

        verticalLayout->addWidget(submitButton);

        updateButton = new QPushButton(layoutWidget1);
        updateButton->setObjectName("updateButton");
        updateButton->setMaximumSize(QSize(78, 16777215));

        verticalLayout->addWidget(updateButton);

        deleteButton = new QPushButton(layoutWidget1);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setMaximumSize(QSize(78, 16777215));

        verticalLayout->addWidget(deleteButton);

        label_status = new QLabel(layoutWidget1);
        label_status->setObjectName("label_status");
        label_status->setMinimumSize(QSize(0, 24));
        label_status->setMaximumSize(QSize(78, 24));
        QFont font;
        font.setPointSize(7);
        label_status->setFont(font);
        label_status->setFrameShape(QFrame::Panel);
        label_status->setFrameShadow(QFrame::Sunken);
        label_status->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_status);


        retranslateUi(reg);

        QMetaObject::connectSlotsByName(reg);
    } // setupUi

    void retranslateUi(QDialog *reg)
    {
        reg->setWindowTitle(QCoreApplication::translate("reg", "Registration", nullptr));
        label->setText(QCoreApplication::translate("reg", "UPID", nullptr));
        label_2->setText(QCoreApplication::translate("reg", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("reg", "Seat", nullptr));
        label_4->setText(QCoreApplication::translate("reg", "Credit", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("reg", "UPID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("reg", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("reg", "Seat", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("reg", "Credit", nullptr));
        submitButton->setText(QCoreApplication::translate("reg", "Insert", nullptr));
        updateButton->setText(QCoreApplication::translate("reg", "Update", nullptr));
        deleteButton->setText(QCoreApplication::translate("reg", "Delete", nullptr));
        label_status->setText(QCoreApplication::translate("reg", "Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reg: public Ui_reg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REG_H
