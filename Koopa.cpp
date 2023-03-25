#include "Koopa.h"
#include "Mario.h"
#include <QSound>
#include "Enemy.h"
#include "Game.h"
#include "guscio.h"
#include <QTimer>
#include <iostream>
using namespace std;

Koopa::Koopa(QPoint position, Direction direction, int type)
{
    // set texture and position
    if(type == 0)
    {
    texture_walk[0]  = QPixmap(loadTexture(":/graphics/turtle-walk-0.png"));
    texture_walk[1]  = QPixmap(loadTexture(":/graphics/turtle-walk-1.png"));
    texture_dead[0]  = QPixmap(loadTexture(":/graphics/turtle-turtleback-0.png"));
    texture_dead[1]  = QPixmap(loadTexture(":/graphics/turtle-turtleback-1.png"));
    }

    else if(type == 1)
    {
    texture_walk[0]  = QPixmap(loadTexture(":/files/images/koopa1_0.bmp"  ).transformed(QTransform().scale(0.5,0.5)));
    texture_walk[1]  = QPixmap(loadTexture(":/files/images/koopa1_1.bmp"  ).transformed(QTransform().scale(0.5,0.5)));
    texture_dead[0]  = QPixmap(loadTexture(":/files/images/koopa1_ded.bmp").transformed(QTransform().scale(0.5,0.5)));
    texture_dead[1]  = QPixmap(loadTexture(":/files/images/koopa1_ded.bmp").transformed(QTransform().scale(0.5,0.5)));
    }

    timer_colpito = 0;
    colpito = false;
    moving = true;

	// set direction
	dir = direction;

	// set texture and correct y-coordinate w.r.t. texture height
	setPixmap(texture_walk[0]);
	setPos(position - QPoint(0, pixmap().height()));

    // setters di Evil e Moving da Enemy
    setEvil(true);
    setMoving(true);
}

void Koopa::animate()
{
    bloccato();

    if(colpito)
    {
        setPixmap(texture_dead[0]);
        timer_colpito++;
        setMovingSpeed(2.5) ; //era 1.5
    }

    if(!moving && colpito && timer_colpito>3000)
    {
        // Gestisce il ritorno a Koopa normale da guscio
        setPixmap(texture_dead[(walk_counter++/walk_div)%2]);
        setPixmap(texture_walk[0]);

        int dy = texture_dead[0].height()-texture_walk[0].height();
        setY(y()+dy);

        moving=true;
        colpito=false;
        evil=true;
        timer_colpito=0;
        setMovingSpeed(1);
        setSlow(true);
    }

    else if(moving && !colpito)
        setPixmap(texture_walk[(walk_counter++/walk_div)%2]);

    if(dir == RIGHT)
        setPixmap(pixmap().transformed(QTransform().scale(-1,1)));
}

void Koopa::hit(Object *what, Direction fromDir)
{
	// if hit from its left or right side, it
	// has to move to the opposite direction w.r.t. the one
	// is he currently moving

    Mario* mario = dynamic_cast<Mario*>(what);
    Enemy* en = dynamic_cast<Enemy*>(what);

    if(mario && !moving && colpito)
    //  gestisce le relazioni tra il Koopa guscio che non si muove e Mario lo colpisce
    {

      if(fromDir == RIGHT || fromDir == LEFT)
      {
        setMoving(true);
        setDirection(inverse(fromDir));
      }

    }

    else if(en && moving && colpito)
    //  gestisce le relazioni tra il Koopa guscio movente e i nemici
    {

       if(fromDir == RIGHT || fromDir == LEFT)
       {
            en->die_alt();
       }

    }

    else if (moving)
       //   gestisce le relazioni tra il Koopa normale e i vari elementi
        {
            setEvil(true);

            if(fromDir == RIGHT || fromDir == LEFT)
            {
              setDirection(inverse(fromDir));
            }

        }

}

 //hurt
void Koopa::hurt()
{
    QSound::play(":/sounds/stomp.wav");
    colpito=true;
    timer_colpito=0;
    setMoving(false);
    setEvil(false);
    setSlow(false);
    walkable=true;
}

