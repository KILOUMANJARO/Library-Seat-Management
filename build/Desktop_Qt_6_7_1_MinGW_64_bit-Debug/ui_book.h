/********************************************************************************
** Form generated from reading UI file 'book.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOK_H
#define UI_BOOK_H

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

class Ui_book
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblInfo;
    QPushButton *btnBook;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QComboBox *cmbSeats;
    QLineEdit *lineEdit;

    void setupUi(QDialog *book)
    {
        if (book->objectName().isEmpty())
            book->setObjectName("book");
        book->setWindowModality(Qt::WindowModal);
        book->resize(304, 154);
        widget = new QWidget(book);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 100, 211, 26));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(60);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lblInfo = new QLabel(widget);
        lblInfo->setObjectName("lblInfo");
        lblInfo->setMinimumSize(QSize(60, 0));
        lblInfo->setMaximumSize(QSize(16777215, 23));
        QFont font;
        font.setPointSize(7);
        lblInfo->setFont(font);
        lblInfo->setFrameShape(QFrame::Panel);
        lblInfo->setFrameShadow(QFrame::Sunken);
        lblInfo->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lblInfo);

        btnBook = new QPushButton(widget);
        btnBook->setObjectName("btnBook");

        horizontalLayout_2->addWidget(btnBook);

        widget1 = new QWidget(book);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(50, 30, 211, 54));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(widget1);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        cmbSeats = new QComboBox(widget1);
        cmbSeats->setObjectName("cmbSeats");

        verticalLayout->addWidget(cmbSeats);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(book);

        QMetaObject::connectSlotsByName(book);
    } // setupUi

    void retranslateUi(QDialog *book)
    {
        book->setWindowTitle(QCoreApplication::translate("book", "Booking", nullptr));
        lblInfo->setText(QCoreApplication::translate("book", "Status", nullptr));
        btnBook->setText(QCoreApplication::translate("book", "Book", nullptr));
        label->setText(QCoreApplication::translate("book", "Seat", nullptr));
        label_2->setText(QCoreApplication::translate("book", "UPID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class book: public Ui_book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOK_H
