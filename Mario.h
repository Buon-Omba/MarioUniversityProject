#pragma once

#include "Entity.h"
#include "QPoint"
#include "QSound"

class Mario : public Entity
{
	protected:

		// physics parameters
		static const int jump_duration_tiny  = 30;	// when Mario jumps over enemies
		static const int jump_duration_small = 70;	// when small Mario jumps
		static const int jump_duration_big   = 90;	// when big Mario jumps

		// animation divisors (inversely proportional to animation speed)
		static const int walk_div    = 6;			// walking animation
		static const int running_div = 4;			// running animation
		static const int transf_div  = 5;			// transformation animation

		// textures
        QPixmap texture_walk[6][3];			// small/big walking animation (3 textures)
        QPixmap texture_stand[6];			// small/big stand texture
        QPixmap texture_jump[6];			// small/big jump texture
		QPixmap texture_dead;				// Mario dies
		QPixmap texture_small_to_big[4];	// Mario small to big transformation
        QPixmap texture_squat[6];           // Mario do a squat
        QPixmap texture_end[6][2];          // Mario sta sulla bandiera

		// flags
		bool big;							// is Mario big?
		bool fire;							// can Mario fire?
        bool invicibile;                    // mario ha mangiato una stella?
        bool bouncing;						// is Mario bouncing on enemies?
		bool running;						// is Mario running?
		bool transforming;					// is Mario transforming? (e.g. from big to small)
        bool squatting;                     // is Mario squatting?
        bool endlevel;                      // Mario sta toccando la bandiera?
        bool enteringPipe;                  // Mario sta entrando nel tubo
        bool sposta_mario;                  // sposta Mario se sta toccando un inerte e si sta trasformando
        bool tocco_ascia;                   // mario ha toccato l'ascia di World-1-4?

		// counters
		int transformation_counter;

		// durations (= limits for counters)
		int transformation_duration;

        //conta i frame in cui Mario è stella
        int timer_stella;

        //variabile ausiliaria necessaria per determinare la destinazione del tubo
        QPoint destinazioneTubo;

		// UTILITY METHODS

		// bounce on enemies
		void bounce();

		// start/end transformation
		void startTransformation();
		void endTransformation();

	public:

		Mario(QPoint position);

		// getters and setters
		bool isBig(){return big;}
		bool isTransforming(){return transforming;}
        bool isEndingLevel(){return endlevel;}
        bool isSquatting(){return squatting;}
        bool isInvincibile(){return invicibile;}
        bool isToccoAscia(){return tocco_ascia;}
		void setRunning(bool _running);
        void setSquatting(bool _squatting);

        bool isisFinished();

        void EndLevelJump();

        // pure virtual methods that must be implemented
        virtual std::string name(){ return "Mario";}
        virtual void animate();
        virtual void hit(Object *what, Direction fromDir);

		// override die method so we can play Mario death animation
		virtual void die();

		// Mario eats a (red = default) Mushroom and gets big
		void mushroomEat(bool red = true);

		// Mario eats a Flower and can fire
		void flowerEat();

        //Mario mangia una stella
        void stellaEat();

		// Mario is hurt
		void hurt();

        // jump
        void jump();

        // gestisce la trasformazione mario fuoco
        void fuoco();

        // per impostare la texture corretta
        int gestione_texture();

        // per far fare a mario lo squat
        void squat();

        int jump_platform();
};
