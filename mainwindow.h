#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mydb.h"
#include "book.h"
#include "cancel.h"
#include "reg.h"
#include "login.h"
#include "plotting.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateUI();
private slots:
    void on_btnBook_clicked();

    void on_btnCancel_clicked();

    void on_btnReset_clicked();

    void on_pushButton_clicked();

    void on_btnPlot_clicked();

private:
    Ui::MainWindow *ui;
    book *ptrBook;
    cancel *ptrCancel;
    reg *ptrReg;
    plotting *ptrPlotting;
};

#endif // MAINWINDOW_H
