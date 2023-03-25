#ifndef PIANTA_PIRANHA_H
#define PIANTA_PIRANHA_H

#pragma once

#include <QPixmap>
#include "Pipe.h"
#include "Enemy.h"

class pianta_piranha : public Enemy
{
    protected:

     // textures
     QPixmap texture[2];    // walking animation (2 textures)
     QPixmap texture_pipe;

     // animation divisors (inversely proportional to animation speed)
     static const int walk_div= 70; // walking animation

     // è la costante che indica la massima altezza del tubo. Viene settata in base al tubo su cui è la pianta piranha
     int maxY;

     // conta il tempo che la pianta rimane ferma
     int counter_high;

     // la pianta sta toccando il tubo?
     bool pipe_touch;

    public:

     pianta_piranha(QPoint position, int size_pipe);

     // pure virtual methods that must be implemented
     virtual std::string name(){ return "pianta_piranha";}
     virtual void animate();
     virtual void hit(Object *what, Direction fromDir);
     virtual void advance();

     // hurt
     virtual void hurt();

     // set e get di maxY
     void setMaxY(int _maxY){maxY = _maxY;}

     // la pianta sta salendo?
     bool up;

};

#endif // PIANTA_PIRANHA_H
