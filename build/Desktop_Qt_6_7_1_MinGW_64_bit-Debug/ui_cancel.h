/********************************************************************************
** Form generated from reading UI file 'cancel.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANCEL_H
#define UI_CANCEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cancel
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QComboBox *cmbSeats;
    QLineEdit *lineEdit_upid;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblInfo;
    QPushButton *btnCancel;

    void setupUi(QDialog *cancel)
    {
        if (cancel->objectName().isEmpty())
            cancel->setObjectName("cancel");
        cancel->setWindowModality(Qt::WindowModal);
        cancel->resize(304, 154);
        widget = new QWidget(cancel);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 30, 211, 54));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        cmbSeats = new QComboBox(widget);
        cmbSeats->setObjectName("cmbSeats");

        verticalLayout_2->addWidget(cmbSeats);

        lineEdit_upid = new QLineEdit(widget);
        lineEdit_upid->setObjectName("lineEdit_upid");

        verticalLayout_2->addWidget(lineEdit_upid);


        horizontalLayout->addLayout(verticalLayout_2);

        widget1 = new QWidget(cancel);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(48, 100, 211, 26));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(60);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lblInfo = new QLabel(widget1);
        lblInfo->setObjectName("lblInfo");
        lblInfo->setMinimumSize(QSize(74, 0));
        QFont font;
        font.setPointSize(7);
        lblInfo->setFont(font);
        lblInfo->setFrameShape(QFrame::Box);
        lblInfo->setFrameShadow(QFrame::Raised);
        lblInfo->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lblInfo);

        btnCancel = new QPushButton(widget1);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout_2->addWidget(btnCancel);


        retranslateUi(cancel);

        QMetaObject::connectSlotsByName(cancel);
    } // setupUi

    void retranslateUi(QDialog *cancel)
    {
        cancel->setWindowTitle(QCoreApplication::translate("cancel", "Unclaim", nullptr));
        label->setText(QCoreApplication::translate("cancel", "Seat", nullptr));
        label_2->setText(QCoreApplication::translate("cancel", "UPID", nullptr));
        lblInfo->setText(QString());
        btnCancel->setText(QCoreApplication::translate("cancel", "Unclaim", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cancel: public Ui_cancel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANCEL_H
