#ifndef BANDIERA_H
#define BANDIERA_H

#include "Inert.h"
#include "Mario.h"
#include <iostream>
using namespace std;

class bandiera : public Inert
{
    protected:
         QPixmap re;             // variabile texture
         bool fin;               // indica se il livello sta finendo
         int _size;              // indica quale texture usare

    public:

        bandiera(QPoint position, int size);

        // pure virtual methods that must be implemented
        virtual std::string name() { return "bandiera"; }
        virtual void hit(Object *what, Direction fromDir);
        virtual void animate();

        void setFin(bool _fin){fin = _fin;}

};

#endif // BANDIERA_H
