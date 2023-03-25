#include <QSound>
#include "Brick.h"
#include "Mario.h"
#include "BrickDebris.h"
#include "Mushroom.h"
#include "Flower.h"
#include "CoinSpawnable.h"
#include "Game.h"
#include "stella.h"
#include "Koopa.h"

Brick::Brick(QPoint position, int type, spawnable_t _spawnable) : Inert()
{
    // set texture and position
    if(type == 0)
    {
	setPixmap(QPixmap(loadTexture(":/graphics/brick.bmp")));
    }

    else if(type == 1)
    {
    setPixmap(QPixmap(loadTexture(":/files/images/brick1.bmp")).transformed(QTransform().scale(0.5,0.5)));
    }

    else if(type == 2)
    {
    setPixmap(QPixmap(loadTexture(":/files/images/brick2.bmp")).transformed(QTransform().scale(0.5,0.5)));
    }

    texture_used = loadTexture(":/graphics/box-used.bmp");

	setPos(position);

    spawnable = _spawnable;
    used=false;
    hit_counter_coin=0;

	hitted = false;
	broken = false;
	hit_counter = 0;
}

// manage collisions with Mario
void Brick::advance()
{
	// do nothing if brick is not visible
	if(this->isVisible() == 0)
		return;

    // gestisce il brick se è usato
    if(used)
        setPixmap(texture_used);

	// hit by Mario: move upwards and downwards
	if(hitted)
	{
		if(hit_counter < 10)
			setY(y()-1);
		else if(hit_counter < 20)
			setY(y()+1);
		
		hit_counter++;

		if(hit_counter >= 20)
		{
			hitted = false;
			hit_counter = 0;
		}
	}
	else if(broken)
	{
		setVisible(false);

		// spawn debris
		new BrickDebris(QPoint(x(),                  y()-15), LEFT);
		new BrickDebris(QPoint(x()+pixmap().width(), y()-15), RIGHT);
		new BrickDebris(QPoint(x()-5,                  y()-5), LEFT);
		new BrickDebris(QPoint(x()+pixmap().width()+5, y()-5), RIGHT);
	}
}

void Brick::hit(Object *what, Direction fromDir)
{
	// hit by Mario from bottom
	Mario* mario = dynamic_cast<Mario*>(what);
	if(mario && fromDir == DOWN)
	{
        if(mario->isBig() && spawnable == VUOTO)
		{
			QSound::play(":/sounds/block-break.wav");
			broken = true;
		}
        else if(used)
            QSound::play(":/sounds/block-hit.wav");
        else if (spawnable !=VUOTO)
        {
            // spawn object
            if(spawnable == COIN)
                new CoinSpawnable(QPoint(x(), y()-20));
            else if(spawnable == MONETE)
            {
                if(hit_counter_coin<10)
                {
                hit_counter_coin++;
                new CoinSpawnable(QPoint(x(), y()-20));
                }
                else if(hit_counter_coin >10)
                    used = true;
            }
            else if(spawnable == POWERUP)
            {
                if(mario->isBig())
                    new Flower(QPoint(x(), y()));
                else
                    new Mushroom(QPoint(x(), y()));
            }
            else if(spawnable == STELLA)
            {
                new stella(QPoint(x() , y() ));
            }
            else if(spawnable == LIFE)
                    new Mushroom(QPoint(x(), y()), false);

            // set flags / counters
            hitted = true;
            used = true;
            hit_counter = 0;
        }
        else
        {
            QSound::play(":/sounds/block-hit.wav");
            hitted = true;
            hit_counter = 0;
        }
	}

    Koopa* koopa = dynamic_cast<Koopa*>(what);
    if(koopa && koopa->getColpito())
    {
            if(fromDir == LEFT || fromDir == RIGHT)
            {
                if(spawnable == MONETE)
                {
                    if(hit_counter_coin<10)
                    {
                    hit_counter_coin++;
                    new CoinSpawnable(QPoint(x(), y()-20));
                    }
                    else if(hit_counter_coin >10)
                        used = true;
                }
            }
    }
}
