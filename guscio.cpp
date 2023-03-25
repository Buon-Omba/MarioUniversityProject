#include "guscio.h"
#include "Mario.h"
#include "Entity.h"
#include "Enemy.h"
#include "Game.h"
#include "Object.h"

guscio::guscio(Object *what)
{
    texture_walk[0] = QPixmap(loadTexture("/home/william/Dropbox/supermario/graphics/turtle-turtleback-0.png"));
    texture_walk[1] = QPixmap(loadTexture("/home/william/Dropbox/supermario/graphics/turtle-turtleback-1.png"));
    moving=false;
}

void guscio::movimento(Object *what, Direction fromDir)
{
       Mario *mario = dynamic_cast<Mario*>(what);
       Enemy *enemy = dynamic_cast<Enemy*>(what);
       if(mario && fromDir == RIGHT || fromDir == LEFT)
       {
               collidable=false;
 //              setDirection(fromDir);
       }
       else if (enemy && moving)
       {
           enemy->die();
       }
}
