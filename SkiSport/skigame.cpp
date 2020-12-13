#include "skigame.h"

SkiGame::SkiGame(QObject *parent) : QObject(parent)
{
    santa=new SkiSanta();

    int temp=15+qrand()%7; //broj prepreka
    for(int i=0;i<temp;i++)
        obstacles.append(new SkiObstacle());

}

SkiGame::~SkiGame()
{
    if(santa!=nullptr)
    {
        delete santa;
        santa=nullptr;
    }

    if(!obstacles.isEmpty())
    {
        for(int i=0;i<obstacles.size();i++)
        {
            if(obstacles[i]!=nullptr)
            {
                delete obstacles[i];
                obstacles[i]=nullptr;
            }
        }
        obstacles.clear();
    }
}

void SkiGame::tick()
{
    for(int i=0;i<obstacles.size();i++)
    {
        obstacles[i]->setY(obstacles[i]->getY()-30);
        if(obstacles[i]->getY()<0-obstacles[i]->getH())
        {
            obstacles[i]->setY(500+qrand()%500);
            obstacles[i]->setX(qrand()%500);
        }
    }
}

void SkiGame::moveSanta(int dx)
{
    if(dx>0)
    {
        santa->setTrenutnoStanje(2); //desno

    }
    else if(dx<0)
    {
        santa->setTrenutnoStanje(1); //levo

    }


    santa->setX(santa->getX()+dx); //azuriranje x koordinate
}

void SkiGame::draw(QPainter &p)
{

   p.drawImage(santa->getX(), santa->getY(), santa->getImage()); //getImage vraca jednu od 6 slika
   if(santa->getTrenutnoStanje()==2 || santa->getTrenutnoStanje()==1) //desno
   {
       santa->setTrenutnoStanje(0);
   }


   for(int i=0;i<obstacles.size();i++)
   {
       p.drawImage(obstacles[i]->getX(),obstacles[i]->getY(),obstacles[i]->getImage());
   }
}
