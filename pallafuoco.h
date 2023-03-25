#ifndef PALLAFUOCO_H
#define PALLAFUOCO_H

#pragma once

#include "Entity.h"

class pallafuoco : public Entity
{
        protected:

                // textures
                QPixmap texture_cycle[4];
                QPoint spawned_position;

                // animation divisors (inversely proportional to animation speed)
                static const int anim_div = 2;	// main animation

                bool morente; //necessario per gestire una corretta morte della palla di fuoco

        public:

                pallafuoco(QPoint position, Direction dir_);

                // inherited methods
                virtual std::string name() {return "pallafuoco";}
                virtual void animate();
                virtual void hit(Object *what, Direction fromDir);

                virtual void die();
};

#endif // PALLAFUOCO_H
