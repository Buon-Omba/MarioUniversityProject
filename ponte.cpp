#include "ponte.h"
#include "ascia.h"
#include "Game.h"
#include <QBrush>
#include <QPainter>
#include <iostream>
using namespace std;

ponte::ponte(QRect rect) : Inert()
{
    // set position
    setPos(QPoint(rect.x(), rect.y()));

    // create collage texture
    QPixmap collage(loadTexture(":/files/images/bridge_0.bmp").transformed(QTransform().scale(0.5,0.5)));
    collage = collage.scaled(rect.width(), rect.height());
    QPainter painter(&collage);
    QPixmap single_block(loadTexture(":/files/images/bridge_0.bmp").transformed(QTransform().scale(0.5,0.5)));
    for(int y=0; y<rect.height(); y += single_block.height())
        for(int x=0; x<rect.width(); x += single_block.width())
            painter.drawPixmap(x, y, single_block);
    setPixmap(collage);

    // set a high z-value so it is displayed on top of other objects
    setZValue(2);
}
void ponte::animate()
{
    Mario* mario = Game::instance()->getMario();
    if(mario->isToccoAscia())
    {
        setVisible(false);
        collidable = false;
    }
}
