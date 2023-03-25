#include "fine_livello.h"
#include "Mario.h"
#include "Game.h"
#include "LevelManager.h"
#include <iostream>
using namespace std;

fine_livello::fine_livello(QPoint position, std::string livello_successivo) : Inert()
{
    texture = loadTexture(":/graphics/box-used.bmp");
    texture.fill(Qt::black);

    _livello_successivo = livello_successivo;

    // set texture and position
    setPixmap(texture);
    setPos(position);

    // be sure z-value is above mushroom's one
    setZValue(-3);
}

void fine_livello::hit(Object *what, Direction fromDir)
{
    Mario* mario = dynamic_cast<Mario*>(what);
    if(mario)
    {
        fine_livello_hit = true;
    }
    Game::instance()->setLivello(_livello_successivo);
    Game::instance()->setFin(true);
}


