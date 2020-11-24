#include "chartdoc.h"


ChartDoc::ChartDoc(QObject *parent) : QObject(parent)
{
    m_points=QList<ChartPoint*>();
}

void ChartDoc::loadChartFromFile(QString file)
{

    QFile f(file);
    if(!f.open(QFile::ReadOnly))
        return;
    if(!m_points.isEmpty())
    {
        for(int i=0;i<m_points.size();i++)
        {
            if(m_points[i]!=nullptr)
                delete m_points[i];
        }
        m_points.clear();
    }
    QTextStream stream(&f);
    while(!stream.atEnd())
    {
        ChartPoint* cp=new ChartPoint();
        cp->load(stream);

        m_points.append(cp);
    }
    f.close();
    emit chartDataChanged();

}

void ChartDoc::saveChartToFile(QString file)
{
    QFile f(file);
    if(!f.open(QFile::WriteOnly))
        return;

    QTextStream stream(&f);
    for(int i=0;i<m_points.size();i++)
    {
        m_points[i]->save(stream);
    }

}
