#include "chartview.h"

ChartView::ChartView(QWidget *parent) : QWidget(parent)
{
    barList=QList<QRect*>();
}

void ChartView::ref(ChartDoc *ref)
{
    reference=ref;
}

void ChartView::onChartDataChanged()
{
    repaint();
}

void ChartView::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    int numberOfBars=reference->m_points.size();
    float space=10; //razmak izmedju stubova

    //QPen l(Qt::red);
    //l.setWidth(5);

    float w=width();
    float h=height();

    p.drawLine(30,40,30,h-30);
    p.drawLine(30, h-30, w-30, h-30);
    float lengthY=h-70; //uzeto je da je y-osa udaljena od gornje ivice 40, a od donje 30 => h-70
    float lengthX=w-60; //x-osa je udaljena od obe ivice po 30 => w-60
    float temp=lengthY/10.0;

    for(int i=0;i<11;i++)
    {
        p.drawLine(30,h-30-i*temp,30-5,h-30-i*temp);
        p.drawText(30-25, h-30-i*temp+5, QString::number(i*10) ); //+5 da ne bi bilo odmah uz liniju

    }

    if(numberOfBars!=0)
    {
        if(!barList.isEmpty())
        {
            for(int i=0;i<barList.size();i++)
            {
                if(barList[i]!=nullptr)
                    delete barList[i];
            }
            barList.clear();
        }
        float barWidth=(lengthX-space*numberOfBars)/numberOfBars;
        for(int i=0;i<numberOfBars;i++)
        {
            float value=reference->m_points[i]->getValue();
            p.setBrush(reference->m_points[i]->getColor());

            QRect* bar=new QRect(30+i*barWidth+i*space,h-30-value/10.0*temp, barWidth, value/10.0*temp);
            p.drawRect(*bar);
            barList.append(bar);

            QRect text(30+i*barWidth+i*space, h-20, barWidth, 15);
            p.drawText(text, Qt::AlignCenter,reference->m_points[i]->getLabel());

        }
    }



}

void ChartView::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        float x=event->x();
        float y=event->y();

        if(!barList.isEmpty())
        {

            for(int i=0;i<barList.size();i++)
            {
                if(barList[i]->contains(x,y))
                {
                    QString cpdLabel=reference->m_points[i]->getLabel();
                    float cpdValue=reference->m_points[i]->getValue();
                    QColor cpdColor=reference->m_points[i]->getColor();

                    ChartPointDialog cpd;
                    cpd.setColor(cpdColor);
                    cpd.setLabel(cpdLabel);
                    cpd.setValue(cpdValue);

                    if(cpd.exec()==QDialog::Accepted)
                    {
                        reference->m_points[i]->setLabel(cpd.getLabel());
                        reference->m_points[i]->setColor(cpd.getColor());
                        reference->m_points[i]->setValue(cpd.getValue());
                    }
                }
            }
             emit reference->chartDataChanged();
        }


    }
}
