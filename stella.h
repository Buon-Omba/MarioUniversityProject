#pragma once

#include "Entity.h"

class stella : public Entity
{
        protected:

                // textures
                QPixmap texture_star;
                QPoint spawned_position;

                // animation divisors (inversely proportional to animation speed)
                static const int anim_div = 5;	// main animation


        public:

                stella(QPoint position);

                // inherited methods
                virtual std::string name() {return "Stella";}
                virtual void animate();
                virtual void hit(Object *what, Direction fromDir);
};
