#ifndef PONTE_H
#define PONTE_H

#pragma once

#include "Inert.h"
#include "ascia.h"

class ponte : public Inert
{
    public:

        ponte(QRect rect);


        // pure virtual methods that must be implemented
        virtual std::string name() { return "Ponte"; }
        virtual void hit(Object *what, Direction fromDir) { /* do nothing */ }
        virtual void animate();
};

#endif // PONTE_H
