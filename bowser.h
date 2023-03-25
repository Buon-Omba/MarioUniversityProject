#ifndef BOWSER_H
#define BOWSER_H

#include "Enemy.h"

class bowser : public Enemy
{
    protected:

        // textures
        QPixmap texture[2];                 // walking animation (2 textures)

        Direction direction;

        // animation divisors (inversely proportional to animation speed)
        static const int walk_div = 10;

        // il movimento di bowser varia al più di 15 pixel
        static const int maxX = 30+15*16;
        static const int minX = 15+15*16;

        int ArraySalto[11] = {0,10,20,30,40,50,60,0,0,10,10};

    public:

        bowser(QPoint position);

        // pure virtual methods that must be implemented
        virtual std::string name(){ return "Bowser";}
        virtual void animate();
        virtual void hit(Object *what, Direction fromDir);

        // hurt
        virtual void hurt(){ /* do nothing */}

        void fuoco();
};

#endif // BOWSER_H
