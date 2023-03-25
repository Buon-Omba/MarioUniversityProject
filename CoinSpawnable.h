#pragma once

#include "Entity.h"

class CoinSpawnable : public Entity
{
	protected:

		QPoint spawned_position;
		QPixmap texture_cycle[4];

	public:

		CoinSpawnable(QPoint position);

		// inherited methods
		virtual std::string name() {return "CoinSpawnable";}
		virtual void animate();
		virtual void hit(Object *what, Direction fromDir){}
};