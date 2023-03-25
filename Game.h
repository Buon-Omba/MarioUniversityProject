#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QSound>
#include "Inert.h"
#include "Mario.h"
#include "LevelManager.h"
#include "fine_livello.h"
#include "ascia.h"

class Game : public QGraphicsView 
{ 
	Q_OBJECT 
	
	enum game_state{READY, RUNNING, PAUSE, GAME_OVER};

	private:

        static Game* uniqueInstance;	// Singleton design pattern
        Game(QGraphicsView *parent=0);	// Singleton design pattern

        QGraphicsScene *scene;          // the scene used to render the game (2D)
        Mario *mario;                   // mario object
        QTimer engine;                  // game engine / timer
		game_state cur_state;           // current game state
		QSound *music;					// game music
        bool fin = false;               // mario sta finendo il livello?

        //Variabile per il cambio di livello
        std::string Livello = "World-1-1";

	protected:

        // the game is controlled using the keyboard
        // hence we have to intercept all keyboard events
		virtual void keyPressEvent(QKeyEvent *e);
		virtual void keyReleaseEvent(QKeyEvent *e);

        // zoom-in/out
        virtual void wheelEvent(QWheelEvent *e);

	public: 
		
		// get unique instance
		static Game* instance();

		// getters
		QGraphicsScene* getScene(){return scene;}

        //Metodo Set e Get per la variabile di fine livello
        void setFin(bool _fin){fin = _fin;}
        bool getFin(){return fin;}

        //Metodo Set e Get per la variabile livello
        void setLivello(std::string _Livello){Livello = _Livello;}
        std::string getLivello(){return Livello;}

        //Metodo Get per Mario
        Mario* getMario(){return mario;}

	public slots:

        // advance game / next frame
        void advance();

		// pause / resume game
		void tooglePause();

		// reset game
		void reset();

		// start new game
		void start();

		// game over
		void gameover();

		// stop music
		void stopMusic();

        //Funzione per avviare la musica
        void playMusic();
};
