#include "ascia.h"
#include "Mario.h"
#include "Game.h"
#include "LevelManager.h"
#include "ponte.h"
#include <iostream>
using namespace std;

ascia::ascia(QPoint position) : Inert()
{
    texture = loadTexture(":/files/images/axe_0.bmp").transformed(QTransform().scale(0.5,0.5));

    ascia_hit = false;
    ponte_end = false;

    // set texture and position
    setPixmap(texture);
    setPos(position);

    // be sure z-value is above mushroom's one
    setZValue(2);
}

void ascia::hit(Object *what, Direction fromDir)
{
    Mario* mario = dynamic_cast<Mario*>(what);
    if(mario)
    {
        collidable = false;
        ascia_hit = true;
        ponte_end = true;
    }

}


