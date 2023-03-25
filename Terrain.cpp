#include "Terrain.h"
#include <QBrush>
#include <QPainter>

Terrain::Terrain(QRect rect, int type) : Inert()
{
    if(type == 1)
    {
        // set position
        setPos(QPoint(rect.x(), rect.y()));

        // create collage texture
        QPixmap collage(loadTexture(":/files/images/gnd1.bmp").transformed(QTransform().scale(0.5,0.5)));
        collage = collage.scaled(rect.width(), rect.height());
        QPainter painter(&collage);
        QPixmap single_block(loadTexture(":/files/images/gnd1.bmp").transformed(QTransform().scale(0.5,0.5)));
        for(int y=0; y<rect.height(); y += single_block.height())
            for(int x=0; x<rect.width(); x += single_block.width())
                painter.drawPixmap(x, y, single_block);
        setPixmap(collage);

        // set a high z-value so it is displayed on top of other objects
        setZValue(2);
        }

    else if(type == 2)
    {
    // set position
    setPos(QPoint(rect.x(), rect.y()));

    // create collage texture
    QPixmap collage(loadTexture(":/files/images/gnd2.bmp").transformed(QTransform().scale(0.5,0.5)));
    collage = collage.scaled(rect.width(), rect.height());
    QPainter painter(&collage);
    QPixmap single_block(loadTexture(":/files/images/gnd2.bmp").transformed(QTransform().scale(0.5,0.5)));
    for(int y=0; y<rect.height(); y += single_block.height())
        for(int x=0; x<rect.width(); x += single_block.width())
            painter.drawPixmap(x, y, single_block);
    setPixmap(collage);

    // set a high z-value so it is displayed on top of other objects
    setZValue(2);
    }

    else if(type == 0)
    {
    // set position
    setPos(QPoint(rect.x(), rect.y()));

	// create collage texture
    QPixmap collage(loadTexture(":/graphics/wall.png"));
	collage = collage.scaled(rect.width(), rect.height());
    QPainter painter(&collage);
    QPixmap single_block(loadTexture(":/graphics/wall.png"));
    for(int y=0; y<rect.height(); y += single_block.height())
        for(int x=0; x<rect.width(); x += single_block.width())
            painter.drawPixmap(x, y, single_block);
    setPixmap(collage);

	// set a high z-value so it is displayed on top of other objects
	setZValue(2);
    }
}
