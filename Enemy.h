#pragma once

#include "Entity.h"
#include "Mario.h"
#include<iostream>
using namespace std;

// Enemy objects are entities that can hurt Mario
// and that Mario can hurt
class Enemy : public Entity
{
	protected:

		bool hurtable;		// whether it can be hurt by Mario's feet
        bool evil;          // il nemico può colpire Mario?
        bool locked;        // blocca il nemico se Mario è lontano

	public:

		Enemy();

        // getters and setters
		bool isHurtable(){return hurtable;}
        bool isEvil(){return evil;}
        virtual void setEvil(bool _evil) { evil = _evil;}

		// pure virtual methods that must be implemented
		virtual std::string name() = 0;
		virtual void animate()     = 0;
		virtual void hit(Object *what, Direction fromDir) = 0;

		// hurt
		virtual void hurt() = 0;

        //Funzione per bloccare i nemici
        void bloccato();
};
