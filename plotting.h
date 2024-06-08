#ifndef PLOTTING_H
#define PLOTTING_H

#include <QDialog>
#include "mydb.h"

namespace Ui {
class plotting;
}

class plotting : public QDialog
{
    Q_OBJECT

public:
    explicit plotting(QWidget *parent = nullptr);
    ~plotting();
    void showEvent(QShowEvent *event);
    void updateUI();

private slots:
    void makePlot();

private:
    Ui::plotting *ui;

signals:
    void mysignal3();
};



#endif // PLOTTING_H
