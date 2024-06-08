/********************************************************************************
** Form generated from reading UI file 'book.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOK_H
#define UI_BOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_book
{
public:
    QPushButton *btnBook;
    QComboBox *cmbSeats;
    QLabel *label;
    QLabel *lblInfo;
    QLineEdit *lineEdit;
    QLabel *label_2;

    void setupUi(QDialog *book)
    {
        if (book->objectName().isEmpty())
            book->setObjectName("book");
        book->setWindowModality(Qt::WindowModal);
        book->resize(304, 147);
        btnBook = new QPushButton(book);
        btnBook->setObjectName("btnBook");
        btnBook->setGeometry(QRect(110, 90, 75, 23));
        cmbSeats = new QComboBox(book);
        cmbSeats->setObjectName("cmbSeats");
        cmbSeats->setGeometry(QRect(140, 10, 121, 22));
        label = new QLabel(book);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 10, 101, 21));
        lblInfo = new QLabel(book);
        lblInfo->setObjectName("lblInfo");
        lblInfo->setGeometry(QRect(60, 100, 151, 16));
        lineEdit = new QLineEdit(book);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(140, 40, 121, 22));
        label_2 = new QLabel(book);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 40, 49, 16));

        retranslateUi(book);

        QMetaObject::connectSlotsByName(book);
    } // setupUi

    void retranslateUi(QDialog *book)
    {
        book->setWindowTitle(QCoreApplication::translate("book", "Book a Ticket", nullptr));
        btnBook->setText(QCoreApplication::translate("book", "Book", nullptr));
        label->setText(QCoreApplication::translate("book", "Select Seat", nullptr));
        lblInfo->setText(QString());
        label_2->setText(QCoreApplication::translate("book", "UPID no.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class book: public Ui_book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOK_H
