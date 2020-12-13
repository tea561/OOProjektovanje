#ifndef SKIVIEW_H
#define SKIVIEW_H

#include <QWidget>
#include "skigame.h"
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>


class SkiView : public QWidget
{
    Q_OBJECT
public:
    explicit SkiView(QWidget *parent = nullptr);
    ~SkiView();
    QTimer* timer;
protected:
    void keyPressEvent(QKeyEvent* event);
    void paintEvent(QPaintEvent* event);

signals:

public slots:
    void tick();

private:
    SkiGame* skiGame;

};

#endif // SKIVIEW_H
