#include "skisanta.h"

SkiSanta::SkiSanta(QObject *parent) : QObject(parent)
{

     santa1.load(":/new/prefix1/IMAGES/santa1.png");
     santa2.load(":/new/prefix1/IMAGES/santa2.png");
     santaLeft1.load(":/new/prefix1/IMAGES/santa-left1.png");
     santaLeft2.load(":/new/prefix1/IMAGES/santa-left2.png");
     santaRight1.load(":/new/prefix1/IMAGES/santa-right1.png");
     santaRight2.load(":/new/prefix1/IMAGES/santa-right2.png");



     w=santa1.width();
     h=santa1.height();
     x=225;
     y=80;
     trenutnoStanje=0;
     kapica=false; //false->slika1
                   //true->slika2


}

void SkiSanta::setTrenutnoStanje(int s)
{
    this->trenutnoStanje=s;
}

void SkiSanta::setX(int x)
{
    //provera da li x izlazi iz granica
    if(x<0)
        x=0;
    else if(x>500-w) //ukupna sirina - sirina slike
        x=500-w;
    this->x=x;
}

QImage SkiSanta::getImage()
{

    //odredjuje koja slika ce biti vracena na osnovu trenutnog stanja
    //bool kapica sluzi za pomeranje kapice i naizmenicno se menja
    if(trenutnoStanje==0)
    {
        if(!kapica)
         {
            kapica=true;
            return santa1;
        }
        else
        {
            kapica=false;
            return santa2;
        }
    }
    else if(trenutnoStanje==1)
    {
        if(!kapica)
        {
            kapica=true;
            return santaLeft1;
        }
        else
        {
            kapica=false;
            return santaLeft2;
        }
    }
    else
    {
        if(!kapica)
        {
            kapica=true;
            return santaRight1;
        }
        else
        {
            kapica=false;
            return santaRight2;
        }
    }

}
