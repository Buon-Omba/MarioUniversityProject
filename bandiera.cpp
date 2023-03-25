#include "bandiera.h"
#include "Mario.h"
#include "Game.h"
#include <iostream>
using namespace std;

bandiera::bandiera(QPoint position, int size) : Inert()
{
    // set proper texture
    if(size == 0)
        setPixmap(QPixmap(loadTexture(":files/images/end0_dot.bmp"  )).transformed(QTransform().scale(0.5,0.5)));
    else if(size == 1)
    {
        collidable = false;
        setPixmap(QPixmap(loadTexture(":files/images/end0_flag.bmp" )).transformed(QTransform().scale(0.5,0.5)));
    }
    else
        setPixmap(QPixmap(loadTexture(":files/images/end0_l.bmp"    )).transformed(QTransform().scale(0.5,0.5)));

     // correct y-coordinate w.r.t. texture height
     setPos(position-QPoint(0, pixmap().height()));

     walkable=false;

     if(size == 1 || size == 0)
        collidable=false;

     _size = size;
     fin = false;
}

void bandiera::hit(Object *what, Direction fromDir)
{
    Mario *mario = dynamic_cast<Mario*>(what);
    if(mario)
    {
        collidable=false;
    }
}

void bandiera::animate()
{

}
