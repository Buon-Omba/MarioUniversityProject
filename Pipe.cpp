#include "Pipe.h"
#include "Mario.h"
#include <iostream>
using namespace std;

Pipe::Pipe(QPoint position, int size, bool _vaso, QPoint destinazione) : Inert()
{
	// set proper texture
	if(size == 0)
        texture = QPixmap(loadTexture(":/graphics/pipe-small.png"));
	else if(size == 1)
        texture = QPixmap(loadTexture(":/graphics/pipe-med.png"));
    else if(size == 2)
        texture = QPixmap(loadTexture(":/graphics/pipe-small.png")).transformed(QTransform().rotate(270));
    else if(size == 3)
        texture = QPixmap(loadTexture(":/graphics/pipe-corpe.png"));
    else
        texture = QPixmap(loadTexture(":/graphics/pipe-big.png"));

	// correct y-coordinate w.r.t. texture height
    setPixmap(texture);
	setPos(position-QPoint(0, pixmap().height()));

    AuxDestinazione = destinazione;

    setZValue(3);

}

void Pipe::hit(Object *what, Direction fromDir)
{

}

void Pipe::animate()
{

}
