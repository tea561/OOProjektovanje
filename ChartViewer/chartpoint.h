#ifndef CHARTPOINT_H
#define CHARTPOINT_H

#include <QObject>
#include <QColor>
#include <QTextStream>

class ChartPoint : public QObject
{
    Q_OBJECT
private:
    QString label;
    float value;
    QColor color;
public:
    explicit ChartPoint(QObject *parent = nullptr);

    void load(QTextStream& stream);
    void save(QTextStream& stream);

    void setLabel(QString label);
    void setValue(float value);
    void setColor(QColor color);

    QString getLabel() {return label;}
    float getValue(){return value;}
    QColor getColor(){return color;}







};

#endif // CHARTPOINT_H
