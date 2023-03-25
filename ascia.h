#ifndef ASCIA_H
#define ASCIA_H

#include "Inert.h"
#include "Game.h"
#include <iostream>
using namespace std;

class ascia: public Inert
{

protected:
    QPixmap texture;
    bool ascia_hit;
    bool ponte_end;

    // animation divisors (inversely proportional to animation speed)
    static const int anim_div = 40;	// main animation

    public:
        ascia(QPoint position);

        // pure virtual methods that must be implemented
        virtual std::string name() { return "ascia"; }
        virtual void hit(Object *what, Direction fromDir);

        bool getPonte_end(){return this->ponte_end;}
};
#endif // ASCIA_H
