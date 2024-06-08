#ifndef REG_H
#define REG_H

#include <QDialog>
#include <QtSql>
#include "mydb.h"

namespace Ui {
class reg;
}

class reg : public QDialog
{
    Q_OBJECT

public:
    explicit reg(QWidget *parent = nullptr);
    ~reg();
    void updateUI();

private slots:
    void onTextChanged();

    void on_submitButton_clicked();

    void on_updateButton_clicked();

    void on_deleteButton_clicked();

    void on_showButton_clicked();

    void onCreditTextChanged();

    void on_upidTextChanged(const QString &upid);

    void clearTextFields();

private:
    Ui::reg *ui;
    bool areAllLineEditsFilled() const;
    bool isUPIDFilled() const;
    QSqlDatabase DB_Connection;

signals:
void mysignal2();

};

#endif // REG_H
