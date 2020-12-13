#ifndef SKIOBSTACLE_H
#define SKIOBSTACLE_H

#include <QObject>
#include <QImage>

class SkiObstacle : public QObject
{
    Q_OBJECT
public:
    explicit SkiObstacle(QObject *parent = nullptr);
    void setY(int y){this->y=y;}
    void setX(int x){this->x=x;}
    int getY(){return y;}
    int getX(){return x;}
    QImage getImage(){return obstacle;}
    int getH(){return h;}

signals:

private:
    int x;
    int y;
    int w;
    int h;
    QImage obstacle;

};

#endif // SKIOBSTACLE_H
