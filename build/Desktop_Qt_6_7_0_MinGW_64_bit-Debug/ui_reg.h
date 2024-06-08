/********************************************************************************
** Form generated from reading UI file 'reg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reg
{
public:
    QPushButton *submitButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_upid;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QLabel *label_3;
    QLineEdit *lineEdit_program;
    QLabel *label_4;
    QLineEdit *lineEdit_credit;
    QPushButton *updateButton;
    QPushButton *deleteButton;
    QTableWidget *tableWidget;

    void setupUi(QDialog *reg)
    {
        if (reg->objectName().isEmpty())
            reg->setObjectName("reg");
        reg->resize(523, 368);
        submitButton = new QPushButton(reg);
        submitButton->setObjectName("submitButton");
        submitButton->setGeometry(QRect(260, 20, 75, 24));
        layoutWidget = new QWidget(reg);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 20, 188, 108));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_upid = new QLineEdit(layoutWidget);
        lineEdit_upid->setObjectName("lineEdit_upid");

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

        lineEdit_program = new QLineEdit(layoutWidget);
        lineEdit_program->setObjectName("lineEdit_program");

        gridLayout->addWidget(lineEdit_program, 2, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_credit = new QLineEdit(layoutWidget);
        lineEdit_credit->setObjectName("lineEdit_credit");

        gridLayout->addWidget(lineEdit_credit, 3, 1, 1, 1);

        updateButton = new QPushButton(reg);
        updateButton->setObjectName("updateButton");
        updateButton->setGeometry(QRect(260, 50, 75, 24));
        deleteButton = new QPushButton(reg);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(260, 80, 75, 24));
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
        tableWidget->setGeometry(QRect(20, 150, 481, 192));

        retranslateUi(reg);

        QMetaObject::connectSlotsByName(reg);
    } // setupUi

    void retranslateUi(QDialog *reg)
    {
        reg->setWindowTitle(QCoreApplication::translate("reg", "Dialog", nullptr));
        submitButton->setText(QCoreApplication::translate("reg", "Insert", nullptr));
        label->setText(QCoreApplication::translate("reg", "UPID", nullptr));
        label_2->setText(QCoreApplication::translate("reg", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("reg", "Program", nullptr));
        label_4->setText(QCoreApplication::translate("reg", "Credit Score", nullptr));
        updateButton->setText(QCoreApplication::translate("reg", "Update", nullptr));
        deleteButton->setText(QCoreApplication::translate("reg", "Delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("reg", "UPID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("reg", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("reg", "Program", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("reg", "Credit Score", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reg: public Ui_reg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REG_H
