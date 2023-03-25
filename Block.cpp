#include "Block.h"
#include <QSound>

Block::Block(QPoint position, int type) : Inert()
{
    // set texture and position
    if(type == 0)
    {
    setPixmap(QPixmap(loadTexture(":/graphics/block.png")));
    }

    else if(type == 1)
    {
    setPixmap(QPixmap(loadTexture(":/files/images/gnd1_2.bmp")).transformed(QTransform().scale(0.5,0.5)));
    }

    else if(type == 2)
    {
    setPixmap(QPixmap(loadTexture(":/files/images/gnd2_2.bmp")).transformed(QTransform().scale(0.5,0.5)));
    }
	setPos(position);
    setZValue(1);
}

void Block::hit(Object *what, Direction fromDir)
{
    if(fromDir == DOWN)
        QSound::play(":/sounds/block-hit.wav");
}
