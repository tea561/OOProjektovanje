#include "chartpoint.h"

ChartPoint::ChartPoint(QObject *parent) : QObject(parent)
{
    label="";
    value=0.0;
    color.setRgb(0,0,0);
}

void ChartPoint::load(QTextStream &stream)
{
    QString line= stream.readLine();
    QStringList sl=line.split(",");
    this->label=sl[0];
    this->value=sl[1].toFloat();
  //  this->color.setNamedColor(sl[2]);
    this->color=sl[2];
}

void ChartPoint::save(QTextStream &stream)
{
    stream << this->label << "," << this->value << "," << this->color.name() << "\n";
}

void ChartPoint::setLabel(QString label)
{
    this->label=label;
}

void ChartPoint::setValue(float value)
{
    this->value=value;
}

void ChartPoint::setColor(QColor color)
{
    this->color=color;
}

