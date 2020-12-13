#include "skiobstacle.h"

SkiObstacle::SkiObstacle(QObject *parent) : QObject(parent)
{
    int temp=qrand()%2; //jelka:1, snesko:0

    if(temp)
        obstacle.load(":/new/prefix1/IMAGES/tree.png");
    else
        obstacle.load(":/new/prefix1/IMAGES/snowman.png");

    w=obstacle.width();
    h=obstacle.height();

    x=qrand() % 500;
    y=500 + qrand()%500; //y-koordinata izvan vidljivog dela
}
