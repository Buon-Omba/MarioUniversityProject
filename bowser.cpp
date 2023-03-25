#include "bowser.h"
#include "Mario.h"
#include "Game.h"
#include "bowser_fire.h"

bowser::bowser(QPoint position)
{
    // set texture and position
    texture[0] = QPixmap(loadTexture(":/files/images/bowser0.bmp").transformed(QTransform().scale(0.5,0.5)));
    texture[1] = QPixmap(loadTexture(":/files/images/bowser1.bmp").transformed(QTransform().scale(0.5,0.5)));

    //is evil?
    evil = true;

    jumping_duration = 50;
    jumping_speed = 1;

    locked = false;

    // set texture and correct y-coordinate w.r.t. texture height
    setPixmap(texture[0]);
    setPos(position - QPoint(0, pixmap().height()));

}

void bowser::animate()
{

    if(moving)
    {
        setPixmap(texture[(walk_counter++/walk_div)%2]);
        Direction ArrayMovimentoCasuale[4] = {UP, RIGHT, LEFT, UP};

        if(walk_counter % 200 == 1)
        {
          srand(walk_counter);
          int RandIndex = rand() % 4;
          direction = ArrayMovimentoCasuale[RandIndex];

          if(direction == UP)
          {
             setDirection(LEFT);

                 srand(walk_counter);
                 int Random_Jump = rand() % 11;
                 jumping_duration = ArraySalto[Random_Jump];

//                 jumping = true;

             startJumping();
//             fuoco();
          }

          else
          {
            setDirection(direction);
          }

        }

        // jumping
        if(jumping)
        {
            prevPos = pos();

            // move upwards
            setY(y() - jumping_speed);

            // increase jump frame count
            jump_counter += jumping_speed;

            // end jumping when frame count reaches the defined limit
            if(jump_counter > jumping_duration)
            {
                fuoco();
                endJumping();
            }
            solveCollisions();
        }

    Mario* mario = Game::instance()->getMario();

    if(x()-(mario->x()) <= 0)
    {
        setDirection(inverse(direction));
        setPixmap(texture[(walk_counter++/walk_div)%2].transformed(QTransform().scale(-1,1)));
    }

    }
}

void bowser::hit(Object *what, Direction fromDir)
{
        // if hit from its left or right side, it
        // has to move to the opposite direction w.r.t. the one
        // is he currently moving
        if(fromDir == RIGHT || fromDir == LEFT)
            setDirection(inverse(fromDir));
}

// gestisce lo sparo del fuoco nelle corrette direzioni e dalla corretta posizione
void bowser::fuoco()
{

    // coefficienti per aggiustare lo sparo del fuoco
    int deltaFireX = texture[0].width();

    Mario* mario = Game::instance()->getMario();

    if(x()-(mario->x()) <= 0)
    {
            new bowser_fire(QPoint(x()+deltaFireX,y()), RIGHT);
    }
    else
            new bowser_fire(QPoint(x()-deltaFireX,y()), LEFT);

    return;
}
