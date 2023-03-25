#include "moneta.h"
#include "Mario.h"
#include <QSound>
#include <iostream>
using namespace std;

moneta::moneta(QPoint position, int type)
{
    if(type == 0)
    {
    texture[0]       = loadTexture(":files/images/coin_use00.bmp").transformed(QTransform().scale(0.5,0.5));
    texture[1]       = loadTexture(":files/images/coin_use01.bmp").transformed(QTransform().scale(0.5,0.5));
    }

    else if(type == 1)
    {
    texture[0]  = loadTexture(":files/images/coin_use0.bmp").transformed(QTransform().scale(0.5,0.5));
    texture[1]  = loadTexture(":files/images/coin_use20.bmp").transformed(QTransform().scale(0.5,0.5));
    texture_dead = loadTexture(":files/images/coin_use00.bmp").transformed(QTransform().scale(0.5,0.5));
    texture_dead.fill(Qt::black);
    }

    else if(type == 2)
    {
    texture[0]    = loadTexture(":files/images/coin_use1.bmp").transformed(QTransform().scale(0.5,0.5));
    texture[1]    = loadTexture(":files/images/coin_use21.bmp").transformed(QTransform().scale(0.5,0.5));
    texture_dead = loadTexture(":files/images/coin_use00.bmp").transformed(QTransform().scale(0.5,0.5));
    texture_dead.fill(Qt::black);
    }

    collectable = true;
    collidable =true;
    moving = false;
    jumping =false;
    falling =false;
    dying = false;
    dead = false;

    setPixmap(texture[0]);
    setPos(position - QPoint(0, pixmap().height()));
}

void moneta::animate()
{
   if(dying || dead)
        setPixmap(texture_dead);
    setPixmap(texture[walk_counter++%2]);
}

void moneta::hit(Object *what, Direction fromDir)
{
    Mario* mario = dynamic_cast<Mario*>(what);
    if(mario)
    {
        setPixmap(texture_dead);
        // play coin sound
        QSound::play(":/sounds/coin.wav");
        setVisible(false);
        die();
    }
}
