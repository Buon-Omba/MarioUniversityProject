#include "piattaforma.h"
#include "Enemy.h"
#include <QPixmap>
#include <iostream>
using namespace std;

piattaforma::piattaforma(QPoint position)
{
    // set texture and position
    texture = QPixmap(loadTexture(":/piattaforma.bmp"  ).transformed(QTransform().scale(0.5,0.5)));

    falling = false;
    walkable = true;
    evil = false;

    //direction
    setDirection(UP);
    up=true;
    moving = true;

    // set texture and correct y-coordinate w.r.t. texture height
    setPixmap(texture);
    setPos(position - QPoint(0, pixmap().height()));

    setZValue(4);

    counter_high=0;

    maxY=8*16;
}

void piattaforma::animate()
{

        if(up == true && y()>200-maxY-texture.height())
        {
            setDirection(UP);
            moving = true;
        }
        else if(y()==200-(maxY+texture.height()) && counter_high<100)
        {
            counter_high++;
            moving=false;
        }
        else if(y()==200-(maxY+texture.height()) && counter_high==100)
        {
            up=false;
            setDirection(DOWN);
            moving=true;

        }
        else if(y()>200-(maxY+texture.height()) && up==false && y()<200-texture.height())
        {
            moving=true;
            setDirection(DOWN);
            up=false;
        }
        else if(y()==200-texture.height() && counter_high>0)
        {
            up=false;
            counter_high--;
            moving=false;
        }
        else if(y()==200-texture.height() && counter_high==0)
        {
            up=true;
            moving=true;
            setDirection(UP);
        }

        if(y()>200-maxY)
        {
            setZValue(-1);
        }

    bloccato();
}

void piattaforma::hit(Object *what, Direction fromDir)
{

}

// hurt
void piattaforma::hurt()
{

}

void piattaforma::advance()
{
    // moving
    if(moving)
    {
        prevPos = pos();
        if(dir == UP)
         {
            setY(y() - moving_speed);
         }
        else if(dir == DOWN)
         {
            setY(y() + moving_speed);
         }
        solveCollisions();
    }
}
