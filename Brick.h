#pragma once

#include "Inert.h"
#include "Box.h"

class Brick : public Inert
{
	protected:

		bool hitted;				// whether the brick has been hit by Mario
		bool broken;				// whether the brick has been broken by Mario
		int  hit_counter;			// counts the number of frames since Mario hit
        bool used;				    // whether the box has been used

        int hit_counter_coin;       // conta le monete comparse

        QPixmap texture_used;		// texture for 'used' state

        spawnable_t spawnable;		// spawnable object

	public:

        Brick(QPoint position, int type, spawnable_t _spawnable = VUOTO);

		// inherited methods
		virtual std::string name() {return "Brick";}
		virtual void advance();
		virtual void hit(Object *what, Direction fromDir);
};
