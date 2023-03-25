#include "Enemy.h"
#include "Mario.h"
#include "Game.h"

Enemy::Enemy() : Entity()
{
	// enemies are usually slow
	slow = true;

	// most enemies are usually hurtable
	hurtable = true;

    // il nemico può danneggiare Mario?
    evil = true;

    // la variabile per il blocco
    locked = true;

}

void Enemy::bloccato()
{
    Mario* mario = Game::instance()->getMario();

    if(locked)
    {
        if(x()-(mario->x()) >= 23*16)
        {
            freeze();
        }
        else if (!dying)
        {
           return;
        }
    }
}

