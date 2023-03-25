#pragma once

#include "Inert.h"
#include "Mario.h"
#include "pianta_piranha.h"

class Pipe : public Inert
{
    protected:

        QPixmap texture;

    public:

        Pipe(QPoint position, int size, bool _vaso = false, QPoint destinazione=QPoint(0,0));

        // pure virtual methods that must be implemented
        virtual std::string name() { return "Pipe"; }
        virtual void hit(Object *what, Direction fromDir);
        virtual void animate();

        //variabile ausiliaria per la gestione dell'ingresso
        QPoint AuxDestinazione;

        bool canEnter(){return AuxDestinazione!=QPoint(0,0);}

};
