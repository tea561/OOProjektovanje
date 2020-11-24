#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QWidget>
#include <QMouseEvent>
#include "chartdoc.h"
#include "chartpointdialog.h"
#include <QPainter>
#include <QList>
#include <QRect>



class ChartView : public QWidget
{
    Q_OBJECT
public:
    ChartDoc* reference;

    explicit ChartView(QWidget *parent = nullptr);
    void ref(ChartDoc* ref);

signals:

public slots:
    void onChartDataChanged();

protected:
    void paintEvent(QPaintEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);
private:
    QList<QRect*> barList;
};

#endif // CHARTVIEW_H
