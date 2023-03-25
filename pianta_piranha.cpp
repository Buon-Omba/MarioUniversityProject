#include "pianta_piranha.h"
#include "Enemy.h"
#include "pallafuoco.h"
#include "Pipe.h"
#include <QPixmap>
#include <iostream>
using namespace std;

pianta_piranha::pianta_piranha(QPoint position, int size_pipe)
{
    // set texture and position
    texture[0] = QPixmap(loadTexture(":/files/images/plant1_0.bmp"  ).transformed(QTransform().scale(0.5,0.5)));
    texture[1] = QPixmap(loadTexture(":/files/images/plant1_1.bmp"  ).transformed(QTransform().scale(0.5,0.5)));

    if(size_pipe == 0)
    {
        texture_pipe = QPixmap(loadTexture(":/graphics/pipe-small.png"));
    }
    else if(size_pipe == 1)
    {
        texture_pipe = QPixmap(loadTexture(":/graphics/pipe-med.png"));
    }
    else
    {
        texture_pipe = QPixmap(loadTexture(":/graphics/pipe-big.png"));
    }

    //is evil?
    evil = true;

    falling = false;

//    collidable=false;

    //direction
    setDirection(UP);
    up=true;
    moving = true;

    // set texture and correct y-coordinate w.r.t. texture height
    setPixmap(texture[0]);
    setPos(position - QPoint(0, pixmap().height()));

    setZValue(4);

    counter_high=0;

    maxY=texture_pipe.height();
}

void pianta_piranha::animate()
{
        setPixmap(texture[(walk_counter++/walk_div)%2]);

        if(up == true && y()>200-(maxY+texture[(walk_counter++/walk_div)%2].height()))
        {
            setDirection(UP);
            moving = true;
        }
        else if(y()==200-(maxY+texture[(walk_counter++/walk_div)%2].height()) && counter_high<100)
        {
            counter_high++;
            moving=false;
        }
        else if(y()==200-(maxY+texture[(walk_counter++/walk_div)%2].height()) && counter_high==100)
        {
            up=false;
            setDirection(DOWN);
            moving=true;

        }
        else if(y()>200-(maxY+texture[(walk_counter++/walk_div)%2].height()) && up==false && y()<200-texture[(walk_counter++/walk_div)%2].height())
        {
            moving=true;
            setDirection(DOWN);
            up=false;
        }
        else if(y()==200-texture[(walk_counter++/walk_div)%2].height() && counter_high>0)
        {
            up=false;
            counter_high--;
            moving=false;
        }
        else if(y()==200-texture[(walk_counter++/walk_div)%2].height() && counter_high==0)
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

void pianta_piranha::hit(Object *what, Direction fromDir)
{
    Pipe* pipe =dynamic_cast<Pipe*>(what);
    if(pipe)
        pipe_touch = true;
}

// hurt
void pianta_piranha::hurt()
{

}

void pianta_piranha::advance()
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

