#ifndef NEWFILE_H
#define NEWFILE_H

#pragma once

#include "Enemy.h"

class Koopa : public Enemy
{
	protected:

        QPixmap texture_walk[2];	// walking animation (2 textures)
        QPixmap texture_dead[2];    // dead animation
        QPixmap texture_flying[2];  // flying textures

        // colpito=false indica che il koopa non è mai stato colpito. colpito=true indica che il koopa è guscio
        bool colpito;

        // conta i frame passati da quando il Koopa è stato colpito
        int timer_colpito;

        static const int walk_div = 10;

    public:

        Koopa(QPoint position, Direction direction = RIGHT, int type = 0);

        // pure virtual methods that must be implemented
        virtual std::string name(){ return "Koopa";}
        virtual void animate();
        virtual void hit(Object *what, Direction fromDir);

        // hurt
        virtual void hurt();

        virtual void setMoving(bool _moving)
        {
            /*if(!dying)*/
            //printf("in Koopa::setMoving(%d)\n", _moving);
            moving = _moving;
        }

        bool getColpito(){return colpito;}
};

#endif // NEWFILE_H
