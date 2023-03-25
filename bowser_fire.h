#ifndef BOWSER_FIRE_H
#define BOWSER_FIRE_H

#include "Entity.h"

class bowser_fire : public Entity
{
        protected:

                // textures
                QPixmap texture[2];
                QPoint spawned_position;

                // animation divisors (inversely proportional to animation speed)
                static const int anim_div = 2;	// main animation

                bool morente; //necessario per gestire una corretta morte della palla di fuoco

        public:

                bowser_fire(QPoint position, Direction dir_);

                // inherited methods
                virtual std::string name() {return "bowser_fire";}
                virtual void animate();
                virtual void hit(Object *what, Direction fromDir);

                virtual void die();
};

#endif // BOWSER_FIRE_H
