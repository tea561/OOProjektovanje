#ifndef SKIGAME_H
#define SKIGAME_H

#include <QObject>
#include <QList>
#include "skiobstacle.h"
#include "skisanta.h"
#include <QPainter>


class SkiGame : public QObject
{
    Q_OBJECT
public:
    explicit SkiGame(QObject *parent = nullptr);
    ~SkiGame();
    void tick();
    void moveSanta(int dx);
    void draw(QPainter& p);


signals:

private:
    QList<SkiObstacle*> obstacles;
    SkiSanta* santa;

};

#endif // SKIGAME_H
