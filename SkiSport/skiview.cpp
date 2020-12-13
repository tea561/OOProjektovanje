#include "skiview.h"

SkiView::SkiView(QWidget *parent) : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    skiGame=new SkiGame();
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    timer->start(500);

}

SkiView::~SkiView()
{
    if(skiGame!=nullptr)
    {
        delete skiGame;
        skiGame=nullptr;
    }
}

void SkiView::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Right)
    {
        skiGame->moveSanta(15);
    }
    else if(event->key()==Qt::Key_Left)
    {
        skiGame->moveSanta(-15);
    }
    else
        QWidget::keyPressEvent(event);
    repaint();
}

void SkiView::paintEvent(QPaintEvent *event)
{
    QPainter p(this);


    skiGame->draw(p);

}

void SkiView::tick()
{
    skiGame->tick();
    repaint();
}
