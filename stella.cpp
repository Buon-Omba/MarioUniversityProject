#include "stella.h"
#include "Mario.h"
#include "Inert.h"
#include <QSound>

stella::stella(QPoint position) : Entity()
{
        // set texture and position
        texture_star = QPixmap(loadTexture(":/graphics/star.png"));
        setPixmap(texture_star);
        setPos(position);

        // set properties
        collectable = true;
        collidable = false;
        dir = RIGHT;
        moving = true;
        falling = false;
        moving_speed = 0.5;
        moving_speed_div = 6;
        slow = false;
        setZValue(2);
        spawned_position = position;

        // play mushroom sound
        QSound::play(":/sounds/mushroom-appear.wav");
}

void stella::animate()
{
        // increase main animation counter (also used to slow down the entity in 'slow' mode)
        walk_counter++;

        startJumping();

        // if star fully emerges from spawn position,
        // fix its position (moving = false)
        if(y() == spawned_position.y()-pixmap().height())
        {
                collidable = true;
                moving = true;
        }

        setPixmap(texture_star);
}

void stella::hit(Object *what, Direction fromDir)
{
        // if hit by Mario, Mario eats star and star disappears
        Mario* mario = dynamic_cast<Mario*>(what);
        Inert* inert = dynamic_cast<Inert*>(what);
        if(mario)
        {
                mario->stellaEat();
                die();
                setVisible(false);
                return;
        }
        // gestisce le interazioni con elementi inerti
        else if(inert)
        {
            if(fromDir == DOWN)
            {
                startJumping();
                return;
            }
            else
                {
                 setDirection(inverse(dir));
                 return;
                }

        }
}
