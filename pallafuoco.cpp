#include "pallafuoco.h"
#include "Enemy.h"
#include "Background.h"
#include <QSound>

pallafuoco::pallafuoco(QPoint position, Direction dir_) : Entity()
{
        // set texture and position
        texture_cycle[0] = loadTexture(":/graphics/fireball-0.bmp");
        texture_cycle[1] = loadTexture(":/graphics/fireball-1.bmp");
        texture_cycle[2] = loadTexture(":/graphics/fireball-2.bmp");
        texture_cycle[3] = loadTexture(":/graphics/fireball-3.bmp");
        setPixmap(texture_cycle[0]);
        setPos(position);

        // set properties
        collectable = false;
        collidable = true;
        dir = dir_ ;
        moving = true;
        falling = true;
        moving_speed = 1.5;
        moving_speed_div = 6;
        slow = false;
        setZValue(2);
        spawned_position = position;
        walkable=true;
        death_duration=0;
        // riproduce il suono
        QSound::play(":/files/sounds/fireball.wav");
}

void pallafuoco::animate()
{
        // increase main animation counter (also used to slow down the entity in 'slow' mode)
        walk_counter++;

        // setter della palla di fuoco
        if(y() == spawned_position.y()-pixmap().height())
        {
                collidable = true;
                moving = true;
        }

        setPixmap(texture_cycle[(walk_counter/anim_div)%4]);
}

void pallafuoco::hit(Object *what, Direction fromDir)
{

        Enemy* en = dynamic_cast<Enemy*>(what);
        Inert* inert = dynamic_cast<Inert*>(what);
        pallafuoco* ball = dynamic_cast<pallafuoco*>(what);

        // gestisce il colpo al nemico
        if(en)
        {
                en->setDead_alt(true);
                en->die_alt();
               // setVisible(false);
                die();
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

            else if(fromDir == LEFT || fromDir == RIGHT)
                die();

            else
                {
                 setDirection(inverse(dir));
                 return;
                }

        }

        // gestisce le interazioni tra le palle
        else if(ball)
        {
            ball->setVisible(false);
            ball->die();
        }

}

void pallafuoco::die()
{
    Entity::die();
    morente == true;
}

