#pragma once

#include "Object.h"

// Entity object are "living", i.e. they can move, animate, fall,
// jump, collide, etc.
class Entity : public Object
{
    protected:

		// physics parameters
        float moving_speed;					// moving speed (pixels/frame)
		int moving_speed_div;				// see 'slow' flag
		int jumping_speed;					// jumping speed (pixels/frame)
		int jumping_duration;				// jump duration (frames)

		// flags
		Direction dir;						// the direction of moving
        bool moving;						// is moving?
        bool jumping;						// is jumping?
        bool falling;						// is falling (gravity)?
		bool phantom;						// phantom mode = no collisions with other entities
		bool collectable;					// entity that Mario can collect (e.g. mushrooms, stars, ...)
		bool dying;							// dying / scheduled for death / death in progress
		bool dead;							// 100% dead
		bool freezed;						// cannot temporarily move
		bool slow;							// subpixel moving speed: move 1 pixel every moving_speed_div frames
        bool dead_alt;                      // flag necessario per la gestione della morte alternativa

        // counters
        int jump_counter;					// counts the number of frames since jump started
		int death_counter;					// counts the number of frames since death
		int walk_counter;					// used for walking (main) animation cycle
		int phantom_counter;				// counts the number of frames since phantom turned on
		int freeze_counter;					// counts the number of frames since freeze started

		// durations (= limits for counters)
		int falling_speed;					// falling speed
		int death_duration;					// death duration (frames) before disappearing
		int phantom_duration;				// phantom duration (frames) before back to normal state
		int freeze_duration;				// freeze duration (frames) before back to normal state

        // others
        QPointF prevPos;                    // previous position
        Object *walkable_object;			// object on which current entity is walking, if any

        // utility methods
        virtual void startJumping();
        virtual void endJumping();
		virtual void startPhantom();
		virtual void endPhantom();

    public:

        Entity();

		// getters and setters
		bool isDead(){return dead;}
		bool isDying(){return dying;}
		bool isPhantom(){ return phantom; }
		bool isCollectable() { return collectable;}
		bool isFalling() {return falling;}
		virtual void setDirection(Direction _dir) { dir = _dir;}
        virtual void setMoving(bool _moving)
        {
            /*if(!dying)*/
           //printf("in setMoving(%d)\n", _moving);
            moving = _moving;
        }
        virtual void setDead_alt(bool _dead_alt) {dead_alt = _dead_alt;}
        virtual void setMovingSpeed(float _moving_speed) {moving_speed = _moving_speed;}
        virtual void setSlow(bool _slow) {slow = _slow;}

        // pure virtual methods to be implemented
        virtual std::string name()     = 0;
        virtual void animate()         = 0;
        virtual void advance();
        virtual void solveCollisions();
        virtual void hit(Object *what, Direction fromDir) = 0;

		// die method, performs common operations to all entities
		// but it will need be overridden in some cases
		virtual void die();

        //morte alternativa nel caso in cui venissero colpiti non dal salto di Mario
        virtual void die_alt();

		// freeze method
		virtual void freeze(){ freezed = true;}
};
