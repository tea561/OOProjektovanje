#ifndef CHARTDOC_H
#define CHARTDOC_H

#include <QFile>
#include <QTextStream>
#include <QList>
#include <QObject>
#include "chartpoint.h"

class ChartDoc : public QObject
{
    Q_OBJECT
public:
    explicit ChartDoc(QObject *parent = nullptr);

    QList<ChartPoint*> m_points;

    void loadChartFromFile(QString file);
    void saveChartToFile(QString file);

signals:
    void chartDataChanged();

};

#endif // CHARTDOC_H
