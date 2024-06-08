#include "plotting.h"
#include "ui_plotting.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QVector>
#include <QSharedPointer>
#include <algorithm>
#include <QDebug>

plotting::plotting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::plotting)
{
    ui->setupUi(this);
}

plotting::~plotting()
{
    delete ui;
}

void plotting::updateUI()
{
    qDebug() << "plotting::updateUI() called";
    // Refresh the data model
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("bookings");
    model->select();
    ui->tableView->setModel(model);

    ui->customPlot->xAxis->setLabel("time");
    ui->customPlot->yAxis->setLabel("count");
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("hh:mm");

    // Set the desired number of ticks on the x-axis
    dateTicker->setTickCount(10); // Change this number according to your preference

    ui->customPlot->xAxis->setTicker(dateTicker);

    // Update the plot
    QVector<QCPGraphData> timeData(model->rowCount());

    for (int i = 0; i < model->rowCount(); ++i) {
        timeData[i].key = QDateTime(QDate::currentDate(), model->index(i, model->fieldIndex("time")).data().toTime()).toSecsSinceEpoch();
        timeData[i].value = model->index(i, model->fieldIndex("count")).data().toDouble();
    }

    double Tmin = (*std::min_element(timeData.begin(), timeData.end(),
                                     [](const QCPGraphData &x, const QCPGraphData &y)
                                     { return x.key < y.key; }))
                      .key;
    double Tmax = (*std::max_element(timeData.begin(), timeData.end(),
                                     [](const QCPGraphData &x, const QCPGraphData &y)
                                     { return x.key < y.key; }))
                      .key;

    double Ymin = (*std::min_element(timeData.begin(), timeData.end(),
                                     [](const QCPGraphData &x, const QCPGraphData &y)
                                     { return x.value < y.value; }))
                      .value;

    double Ymax = (*std::max_element(timeData.begin(), timeData.end(),
                                     [](const QCPGraphData &x, const QCPGraphData &y)
                                     { return x.value < y.value; }))
                      .value;

    // Ensure a graph exists before setting its data
    if (ui->customPlot->graphCount() == 0)
        ui->customPlot->addGraph();

    ui->customPlot->xAxis->setRange(Tmin, Tmax);
    ui->customPlot->yAxis->setRange(Ymin, Ymax);
    ui->customPlot->graph(0)->data()->set(timeData);
    ui->customPlot->replot();
}

void plotting::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    updateUI();
}
