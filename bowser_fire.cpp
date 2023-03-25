#include "bowser_fire.h"
#include "Inert.h"
#include "Mario.h"

bowser_fire::bowser_fire(QPoint position, Direction dir_)
{
    // set texture and position
    texture[0] = loadTexture(":/files/images/fire_0.bmp").transformed(QTransform().scale(0.5,0.5));
    texture[1] = loadTexture(":/files/images/fire_1.bmp").transformed(QTransform().scale(0.5,0.5));
    setPixmap(texture[0]);
    setPos(position);

    // set properties
    collectable = false;
    collidable = true;
    dir = dir_ ;
    moving = true;
    falling = false;
    moving_speed = 1.5;
    moving_speed_div = 6;
    slow = false;
    setZValue(2);
    spawned_position = position;
    walkable=true;
    death_duration=0;
}

void bowser_fire::animate()
{
        // increase main animation counter (also used to slow down the entity in 'slow' mode)
        walk_counter++;

        // setter del fuoco
        if(y() == spawned_position.y()-pixmap().height())
        {
                collidable = true;
                moving = true;
        }

        setPixmap(texture[(walk_counter/anim_div)%2]);
}

void bowser_fire::hit(Object *what, Direction fromDir)
{

        Mario* mario = dynamic_cast<Mario*>(what);
        Inert* inert = dynamic_cast<Inert*>(what);
        bowser_fire* fire = dynamic_cast<bowser_fire*>(what);

        // gestisce il colpo a mario
        if(mario)
        {
                mario->hurt();
               // setVisible(false);
                die();
                return;
        }

        // gestisce le interazioni tra le palle
        else if(fire)
        {
            fire->setVisible(false);
            fire->die();
        }

        // gestisce le interazioni con elementi inerti
        else if(inert)
        {

            if(fromDir == DOWN)
            {
                startJumping();
                return;
            }

            else if(fromDir == LEFT || fromDir == RIGHT)
                die();

            else
                {
                 setDirection(inverse(dir));
                 return;
                }

        }

}

void bowser_fire::die()
{
    Entity::die();
    morente == true;
}
