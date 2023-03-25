#ifndef MONETA_H
#define MONETA_H

#include "Entity.h"

class moneta : public Entity
{
    protected:

        // textures
        QPixmap texture[2];
        QPixmap texture_dead;
        QPoint Position;

        // animation divisors (inversely proportional to animation speed)
        static const int anim_div = 5;	// main animation

    public:

        moneta(QPoint position, int type = 0);

        // inherited methods
        virtual std::string name() {return "Moneta";}
        virtual void animate();
        virtual void hit(Object *what, Direction fromDir);
};

#endif // MONETA_H
