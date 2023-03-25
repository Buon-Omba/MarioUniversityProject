#include "Goomba.h"
#include "Mario.h"
#include <QSound>

Goomba::Goomba(QPoint position, Direction direction, int type)
{
    // set texture and position
    if(type == 0)
    {
    texture_walk[0] = QPixmap(loadTexture(":/graphics/goomba-0.png"));
    texture_walk[1] = QPixmap(loadTexture(":/graphics/goomba-1.png"));
    texture_dead    = QPixmap(loadTexture(":/graphics/goomba-dead.png"));
    }

    else if(type == 1)
    {
    texture_walk[0] = QPixmap(loadTexture(":/files/images/goombas1_0.bmp"  ).transformed(QTransform().scale(0.5,0.5)));
    texture_walk[1] = QPixmap(loadTexture(":/files/images/goombas1_1.bmp"  ).transformed(QTransform().scale(0.5,0.5)));
    texture_dead    = QPixmap(loadTexture(":/files/images/goombas1_ded.bmp").transformed(QTransform().scale(0.5,0.5)));
    }

    // set direction
	dir = direction;

    //is evil?
    evil = true;

	// set texture and correct y-coordinate w.r.t. texture height
	setPixmap(texture_walk[0]);
	setPos(position - QPoint(0, pixmap().height()));

}

void Goomba::animate()
{

	if(dying || dead)
		setPixmap(texture_dead);
    else if(moving)
        setPixmap(texture_walk[(walk_counter++/walk_div)%2]);

    bloccato();
}

void Goomba::hit(Object *what, Direction fromDir)
{
	// if hit from its left or right side, it
	// has to move to the opposite direction w.r.t. the one
	// is he currently moving
	if(fromDir == RIGHT || fromDir == LEFT)
        setDirection(inverse(fromDir));
}

// hurt
void Goomba::hurt()
{
	QSound::play(":/sounds/stomp.wav");
    die();
}

