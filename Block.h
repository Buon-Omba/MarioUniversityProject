#pragma once

#include "Inert.h"

class Block : public Inert
{
	public:

        Block(QPoint position, int type = 0);

        // pure virtual methods that must be implemented
        virtual std::string name() { return "Block"; }
        virtual void hit(Object *what, Direction fromDir);
};
