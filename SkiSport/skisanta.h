#ifndef SKISANTA_H
#define SKISANTA_H

#include <QObject>
#include <QImage>

class SkiSanta : public QObject
{
    Q_OBJECT
public:
    explicit SkiSanta(QObject *parent = nullptr);
    void setTrenutnoStanje(int s);
    void setX(int x);
    int getX(){return x;}
    int getY(){return y;}
    int getTrenutnoStanje(){return trenutnoStanje;}

    QImage getImage();
    bool kapica; //pomeranje kape


signals:

private:
    int x;
    int y;
    int w;
    int h;
    QImage santa1;
    QImage santa2;
    QImage santaLeft1;
    QImage santaLeft2;
    QImage santaRight1;
    QImage santaRight2;
    int trenutnoStanje; //1-levo, 2-desno


};

#endif // SKISANTA_H
