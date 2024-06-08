/********************************************************************************
** Form generated from reading UI file 'plotting.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTTING_H
#define UI_PLOTTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_plotting
{
public:
    QTableView *tableView;
    QFrame *frame;
    QCustomPlot *customPlot;

    void setupUi(QDialog *plotting)
    {
        if (plotting->objectName().isEmpty())
            plotting->setObjectName("plotting");
        plotting->resize(719, 266);
        tableView = new QTableView(plotting);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(480, 20, 221, 221));
        frame = new QFrame(plotting);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(20, 20, 441, 221));
        frame->setStyleSheet(QString::fromUtf8("background-color: white;"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Plain);
        customPlot = new QCustomPlot(frame);
        customPlot->setObjectName("customPlot");
        customPlot->setGeometry(QRect(10, 10, 421, 201));

        retranslateUi(plotting);

        QMetaObject::connectSlotsByName(plotting);
    } // setupUi

    void retranslateUi(QDialog *plotting)
    {
        plotting->setWindowTitle(QCoreApplication::translate("plotting", "Plotting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class plotting: public Ui_plotting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTTING_H
