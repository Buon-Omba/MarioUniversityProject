#include "Mario.h"
#include "Enemy.h"
#include "Game.h"
#include "pallafuoco.h"
#include "Pipe.h"
#include "bandiera.h"
#include "fine_livello.h"
#include "pianta_piranha.h"
#include "bowser.h"
#include "ascia.h"
#include "piattaforma.h"
#include <time.h>
#include <QTime>
#include <QBrush>
#include <iostream>
using namespace std;

QSound levelend(":/files/sounds/levelend.wav");

Mario::Mario(QPoint position) : Entity()
{
	// set flags
    moving  = false;
    running = false;
	bouncing = false;
	big = false;
	fire = false;
    invicibile = false;
	transforming = false;
	transformation_counter = 0;
    enteringPipe = false;
    endlevel = false;
    tocco_ascia =false;

	// durations
	jumping_duration = jump_duration_small;
	death_duration = 300;
	transformation_duration = freeze_duration;

    //sulle textures ho usato la notazione che se il primo numero è dispari si parla di mario grande. Se pari mario piccolo
	// textures
    texture_walk [0][0]     = QPixmap(loadTexture(":/files/images/mario/mario_move0.bmp" )).transformed(QTransform().scale(0.5,0.5));
    texture_walk [0][1]     = QPixmap(loadTexture(":/files/images/mario/mario_move1.bmp" )).transformed(QTransform().scale(0.5,0.5));
    texture_walk [0][2]     = QPixmap(loadTexture(":/files/images/mario/mario_move2.bmp" )).transformed(QTransform().scale(0.5,0.5));
    texture_walk [1][0]     = QPixmap(loadTexture(":/files/images/mario/mario1_move0.bmp")).transformed(QTransform().scale(0.5,0.5));
    texture_walk [1][1]     = QPixmap(loadTexture(":/files/images/mario/mario1_move1.bmp")).transformed(QTransform().scale(0.5,0.5));
    texture_walk [1][2]     = QPixmap(loadTexture(":/files/images/mario/mario1_move2.bmp")).transformed(QTransform().scale(0.5,0.5));
    texture_stand[0]        = QPixmap(loadTexture(":/files/images/mario/mario.bmp"       )).transformed(QTransform().scale(0.5,0.5));
    texture_stand[1]        = QPixmap(loadTexture(":/files/images/mario/mario1.bmp"      )).transformed(QTransform().scale(0.5,0.5));
    texture_jump [0]        = QPixmap(loadTexture(":/files/images/mario/mario_jump.bmp"  )).transformed(QTransform().scale(0.5,0.5));
    texture_jump [1]        = QPixmap(loadTexture(":/files/images/mario/mario1_jump.bmp" )).transformed(QTransform().scale(0.5,0.5));
    texture_dead	        = QPixmap(loadTexture(":/files/images/mario/mario_death.bmp" )).transformed(QTransform().scale(0.5,0.5));
    texture_squat[1]        = QPixmap(loadTexture(":/files/images/mario/mario1_squat.bmp")).transformed(QTransform().scale(0.5,0.5));
    texture_end  [0][0]     = QPixmap(loadTexture(":/files/images/mario/mario_end.bmp"   )).transformed(QTransform().scale(0.5,0.5));
    texture_end  [0][1]     = QPixmap(loadTexture(":/files/images/mario/mario_end1.bmp"  )).transformed(QTransform().scale(0.5,0.5));
    texture_end  [1][0]     = QPixmap(loadTexture(":/files/images/mario/mario1_end.bmp"  )).transformed(QTransform().scale(0.5,0.5));
    texture_end  [1][1]     = QPixmap(loadTexture(":/files/images/mario/mario1_end1.bmp" )).transformed(QTransform().scale(0.5,0.5));

    //texture per la trasformazione
    texture_small_to_big[0] = texture_stand[0];
    texture_small_to_big[1] = QPixmap(loadTexture(":/graphics/mario-med-stand.bmp"   ));
	texture_small_to_big[2] = texture_stand[1];
    texture_small_to_big[3] = QPixmap(loadTexture(":/graphics/mario-med-stand.bmp"   ));

    //textures per mario stella
    texture_walk [2][0]     = QPixmap(loadTexture(":/files/images/mario/mario_s0_move0.bmp")).transformed(QTransform().scale(0.5,0.5));
    texture_walk [2][1]     = QPixmap(loadTexture(":/files/images/mario/mario_s0_move1.bmp")).transformed(QTransform().scale(0.5,0.5));
    texture_walk [2][2]     = QPixmap(loadTexture(":/files/images/mario/mario_s0_move2.bmp")).transformed(QTransform().scale(0.5,0.5));
    texture_walk [3][0]     = QPixmap(loadTexture(":/files/images/mario/mario2s_move0.bmp" )).transformed(QTransform().scale(0.5,0.5));
    texture_walk [3][1]     = QPixmap(loadTexture(":/files/images/mario/mario2s_move1.bmp" )).transformed(QTransform().scale(0.5,0.5));
    texture_walk [3][2]     = QPixmap(loadTexture(":/files/images/mario/mario2s_move2.bmp" )).transformed(QTransform().scale(0.5,0.5));
    texture_stand[2]        = QPixmap(loadTexture(":/files/images/mario/mario_s0.bmp"      )).transformed(QTransform().scale(0.5,0.5));
    texture_stand[3]        = QPixmap(loadTexture(":/files/images/mario/mario2s.bmp"       )).transformed(QTransform().scale(0.5,0.5));
    texture_jump [2]        = QPixmap(loadTexture(":/files/images/mario/mario_s0_jump.bmp" )).transformed(QTransform().scale(0.5,0.5));
    texture_jump [3]        = QPixmap(loadTexture(":/files/images/mario/mario2s_jump.bmp"  )).transformed(QTransform().scale(0.5,0.5));
    texture_squat[3]        = QPixmap(loadTexture(":/files/images/mario/mario2s_squat.bmp" )).transformed(QTransform().scale(0.5,0.5));
    texture_end  [2][0]     = QPixmap(loadTexture(":/files/images/mario/mario_s0_end.bmp"  )).transformed(QTransform().scale(0.5,0.5));
    texture_end  [2][1]     = QPixmap(loadTexture(":/files/images/mario/mario_s0_end1.bmp" )).transformed(QTransform().scale(0.5,0.5));
    texture_end  [3][0]     = QPixmap(loadTexture(":/files/images/mario/mario2s_end.bmp"   )).transformed(QTransform().scale(0.5,0.5));
    texture_end  [3][1]     = QPixmap(loadTexture(":/files/images/mario/mario2s_end1.bmp"  )).transformed(QTransform().scale(0.5,0.5));

    //textures per mario fuoco
    texture_walk [4][0]     = QPixmap(loadTexture(":/files/images/mario/mario_s1_move0.bmp")).transformed(QTransform().scale(0.5,0.5));
    texture_walk [4][1]     = QPixmap(loadTexture(":/files/images/mario/mario_s1_move1.bmp")).transformed(QTransform().scale(0.5,0.5));
    texture_walk [4][2]     = QPixmap(loadTexture(":/files/images/mario/mario_s1_move2.bmp")).transformed(QTransform().scale(0.5,0.5));
    texture_walk [5][0]     = QPixmap(loadTexture(":/files/images/mario/mario2_move0.bmp"  )).transformed(QTransform().scale(0.5,0.5));
    texture_walk [5][1]     = QPixmap(loadTexture(":/files/images/mario/mario2_move1.bmp"  )).transformed(QTransform().scale(0.5,0.5));
    texture_walk [5][2]     = QPixmap(loadTexture(":/files/images/mario/mario2_move2.bmp"  )).transformed(QTransform().scale(0.5,0.5));
    texture_stand[4]        = QPixmap(loadTexture(":/files/images/mario/mario_s1.bmp"      )).transformed(QTransform().scale(0.5,0.5));
    texture_stand[5]        = QPixmap(loadTexture(":/files/images/mario/mario2.bmp"        )).transformed(QTransform().scale(0.5,0.5));
    texture_jump [4]        = QPixmap(loadTexture(":/files/images/mario/mario_s1_jump.bmp" )).transformed(QTransform().scale(0.5,0.5));
    texture_jump [5]        = QPixmap(loadTexture(":/files/images/mario/mario2_jump.bmp"   )).transformed(QTransform().scale(0.5,0.5));
    texture_squat[5]        = QPixmap(loadTexture(":/files/images/mario/mario2_squat.bmp"  )).transformed(QTransform().scale(0.5,0.5));
    texture_end  [4][0]     = QPixmap(loadTexture(":/files/images/mario/mario_s1_end.bmp"  )).transformed(QTransform().scale(0.5,0.5));
    texture_end  [4][1]     = QPixmap(loadTexture(":/files/images/mario/mario_s1_end1.bmp" )).transformed(QTransform().scale(0.5,0.5));
    texture_end  [5][0]     = QPixmap(loadTexture(":/files/images/mario/mario2_end.bmp"    )).transformed(QTransform().scale(0.5,0.5));
    texture_end  [5][1]     = QPixmap(loadTexture(":/files/images/mario/mario2_end1.bmp"   )).transformed(QTransform().scale(0.5,0.5));

	// set texture and correct y-coordinate w.r.t. texture height
	setPixmap(texture_stand[0]);
	setPos(position-QPoint(0, pixmap().height()));

	// Mario is at a higher layer than other objects
	setZValue(3);

    endlevel = false;
    squatting = false;
}

 bool Mario::isisFinished(){return levelend.isFinished();} //la canzone di fine livello è terminata

// Mario jumps
void Mario::jump()
{
	// do nothing if already jumping
	if(jumping)
		return;

    // start a jump
    startJumping();

    // if jumping has started, play jump sound
    if(jumping)
        QSound::play(big ? ":/sounds/jump-big.wav" : ":/sounds/jump-small.wav");
}

// Mario eats a (red = default) Mushroom and gets big
void Mario::mushroomEat(bool red)
{
	if(red)
	{
		// get big if not already
		if(!big)
		{
			big = true;

			// set proper jump duration
			jumping_duration = jump_duration_big;

			// start transformation
            startTransformation();
		}

		// play sound in any case
		QSound::play(":/sounds/mushroom-eat.wav");
	}
	// green: life up
	else
		QSound::play(":/sounds/oneup.wav");
}

// Mario eats a Flower and can fire
void Mario::flowerEat()
{
    QSound::play(":/sounds/mushroom-eat.wav");

    if(!fire)
    {
        startTransformation();
        fire=true;
    }
}

void Mario::stellaEat()
{
    //Gestistisce il primo play di starmusic
    Game::instance()->stopMusic();
    QSound::play(":/sounds/starmusic.wav");

    invicibile=true;
    timer_stella=0;
}

// Mario is hurt
void Mario::hurt()
{
	// cannot fire anymore
	fire = false;

	// if big, gets small
	if(big)
	{
		big = false;

		// set proper jump duration
		jumping_duration = jump_duration_small;

		// play sound
		QSound::play(":/sounds/shrink.wav");

		// Mario becomes a phantom temporarily
		startPhantom();

		// start transformation
		startTransformation();
	}
	// otherwise, Mario dies
	else
		die();
}

// start transformation
void Mario::startTransformation()
{
	// start transformation
	transforming = true;

	// set animation counter so that next animation
	// is properly handled (see animate())
	transformation_counter = big ? 0 : 2*transf_div;

	// freeze
	freeze();
}

// end transformation
void Mario::endTransformation()
{
	// end transformation
	transforming = false;

	// reset animation counter
	transformation_counter = 0;

	// correct y coordinate so that the 'final' (transformed) Mario
	// has the same bottom coordinate 
	int dy = pixmap().height()-(big ? texture_stand[1] : texture_stand[0]).height();
	setY(y()+dy);
}


void Mario::animate()
{
	// handle bouncing
	if(jumping == false && bouncing)
	{
		bouncing = false;
		jumping_duration = big ? jump_duration_big : jump_duration_small;
	}

	// handle phantom mode
	if(phantom)
	{
		phantom_counter++;
		if(phantom_counter > phantom_duration)
			endPhantom();
	}

	// handle transformation
	if(transforming)
	{
		transformation_counter++;
		if(transformation_counter > transformation_duration)
			endTransformation();
	}

	// set proper texture
	if(transforming)
	{
		int prev = ((transformation_counter-1)/transf_div)%4;
		int curr = (transformation_counter/transf_div)%4;
		int dy = texture_small_to_big[prev].height()-texture_small_to_big[curr].height();
		setPixmap(texture_small_to_big[(transformation_counter/transf_div)%4]);
		setY(y()+dy);
	}

	else if(dying || dead)
    {
        moving = false;
        running = false;
		setPixmap(texture_dead);
    }
    else if(moving && !jumping && !falling)
        setPixmap(texture_walk[gestione_texture()][(walk_counter++/(running ? running_div : walk_div))%3]);
    else if(jumping || falling && !endlevel)
        setPixmap(texture_jump[gestione_texture()]);
    else if(squatting && big)
        setPixmap(texture_squat[gestione_texture()]);
    else if(endlevel)
    {
        moving = false;
        setPixmap(texture_end[gestione_texture()][walk_counter++%2]);

        //La y() è la costante del posizionamento del terreno. La x() è la costante del posizionamento della porta del mondo 1-1.
        //x() va modificata alla creazione del nuovo mondo
        //tale if è diviso in caso big e caso not big per aggiustare il posizionamento di Mario nel caso in cui è big
        if(y() == 184 && x()!=3177)
        {
            setPixmap(texture_walk[gestione_texture()][(walk_counter++/(running ? running_div : walk_div))%3]);
            moving = true;
            dir = RIGHT;
        }
        else if(y() == 168 && x()!=3177 && big)
        {
            setPixmap(texture_walk[gestione_texture()][(walk_counter++/(running ? running_div : walk_div))%3]);
            moving = true;
            dir = RIGHT;
        }
    }

    else
        setPixmap(texture_stand[gestione_texture()]);

	// mirror the texture along the horizontal axis if needed
	if(dir == LEFT)
		setPixmap(pixmap().transformed(QTransform().scale(-1,1)));

}

// Mario has been hit
void Mario::hit(Object *what, Direction fromDir)
{
	// if hit by Enemy
	Enemy *enemy = dynamic_cast<Enemy*>(what);
    pianta_piranha *pianta = dynamic_cast<pianta_piranha*>(what);
    bowser *bow = dynamic_cast<bowser*>(what);
    ascia *axe=dynamic_cast<ascia*>(what);
    piattaforma *piatta=dynamic_cast<piattaforma*>(what);

    if(enemy)
	{
		// with Mario's feet and enemy is hurtable --> enemy is hurt
        if(fromDir == DOWN && enemy->isHurtable() && enemy->isEvil()==true && !pianta && !bow)
		{
			// hurt enemy and bounce
			enemy->hurt();
			bounce();
		}

        else if(enemy->isEvil()==false)
        {
            int a=1+1;
        }

        else if(invicibile == true)
        {
                enemy->die_alt();
        }

		// all other cases   --> Mario is hurt
		else
			hurt();
    }

    //tocco della bandiera
    bandiera *ban = dynamic_cast<bandiera*>(what);
    if(ban)
    {
        Game::instance()->stopMusic();
        if(endlevel == false)
        {
            levelend.play();
        }
        endlevel=true;
        ban->setFin(true);
    }

    //tocco del blocco di fine livello
    fine_livello *lv = dynamic_cast<fine_livello*>(what);
    if(lv && endlevel)
    {
        setZValue(-3);
        texture_stand[gestione_texture()].fill(Qt::black);
        texture_walk[gestione_texture()][(walk_counter++/(running ? running_div : walk_div))%3].fill(Qt::black);
    }


    Inert *in = dynamic_cast<Inert*>(what);
    if(in && big)
    {
        sposta_mario = true;
        setX(x()-100*16);
    }

    if(axe)
        tocco_ascia=axe->getPonte_end();

}

// bounce on enemies
void Mario::bounce()
{
	falling = false;
	bouncing = true;
	jumping_duration = jump_duration_tiny;
	startJumping();
}

// override die method so we can play Mario death animation
void Mario::die()
{
    if(enteringPipe)
    {
        setPos(destinazioneTubo);
        dying=false;
        dead=false;
        collidable=true;
        enteringPipe = false;
        falling_speed = 2;
        setZValue(1);
        startJumping();
        return;
    }

	// call superclass method
	Entity::die();

	// in addition, we make Mario not collidable
	// so he can fall through all objects (including Terrain)
	collidable = false;


	// play death sound while stopping level music
	QSound::play(":/sounds/death.wav");
	Game::instance()->stopMusic();

	// freeze Mario before jumping
	freeze();

	// make a slow jump
	jumping_speed = 1;
	falling_speed = 1;
	startJumping();
}

// running = double moving speed
void Mario::setRunning(bool _running)
{
	// do nothing if running state does not change
	if(running == _running)
		return;

	// set new running state
	running = _running;

	// double / halve moving speed
	if(running)
		moving_speed *= 2;
	else
		moving_speed /= 2;
}

void Mario::setSquatting(bool _squatting)
{
    squatting = _squatting;
}

//gestisce lo sparo del fuoco nelle corrette direzioni e dalla corretta posizione
void Mario::fuoco()
{
    if(fire)
    {
        if(dir == RIGHT)
            new pallafuoco(QPoint(x()+16,y()+22), dir);
        else if (dir == LEFT)
            new pallafuoco(QPoint(x()-16,y()+22), dir);
        else
            new pallafuoco(QPoint(x(),y()-20), dir);
    }
    return;
}

int Mario::gestione_texture()
{
   if(fire && big && !invicibile)
       return 5;
   else if(fire && !big)
       return 4;
   else if(invicibile && big)
   {
       timer_stella++;

       //Gestisce il suono della stella
       if(timer_stella%315 == 1 && timer_stella<1260)
       {
           Game::instance()->stopMusic();
           QSound::play(":/sounds/starmusic.wav");
       }

       if(timer_stella>1260)
       {
           invicibile=false;
           Game::instance()->playMusic();
           return 1;
       }
       else
       {
        int ArrayStarBig[3] = {3, 5, 1};
        int ElementoStellaGrande = 1;
        srand (timer_stella); //initialize the random seed
        int RandIndex = rand() % 3; //generates a random number between 0 and 2
        return ArrayStarBig[RandIndex];
       }
   }
   else if(invicibile && fire)
   {
       timer_stella++;

       //Gestisce il suono della stella
       if(timer_stella%315 == 1 && timer_stella<1260)
       {
           Game::instance()->stopMusic();
           QSound::play(":/sounds/starmusic.wav");
       }

       if(timer_stella>1260)
       {
           invicibile=false;
           Game::instance()->playMusic();
           return 1;
       }

       else {
        int ArrayStarBig[3] = {3, 5, 1};
        int ElementoStellaGrande = 1;
        srand (timer_stella); //initialize the random seed
        int RandIndex = rand() % 3; //generates a random number between 0 and 2
        }
   }
   else if(invicibile && !big)
   {

       timer_stella++;

       //Gestisce il suono della stella
       if(timer_stella%315 == 1 && timer_stella<1260)
       {
           Game::instance()->stopMusic();
           QSound::play(":/sounds/starmusic.wav");
       }

       if(timer_stella>1260)
       {
           invicibile=false;
           Game::instance()->playMusic();
           return 1;
       }

       else {
        int ArrayStarBig[3] = {2, 4, 0};
        int ElementoStellaGrande = 1;
        srand (timer_stella); //initialize the random seed
        int RandIndex = rand() % 3; //generates a random number between 0 and 2
        return ArrayStarBig[RandIndex];
       }
   }
   else if(!fire && !invicibile && big)
       return 1;
   else
       return 0;
}

 void Mario::squat()
 {
     if(walkable_object)
     {
        Pipe* pipe = dynamic_cast<Pipe*>(walkable_object);
        if(pipe && pipe->canEnter())
        {
            falling=true;
            collidable=false;
            falling_speed=1;
            enteringPipe=true;
            setZValue(1);
            destinazioneTubo = pipe->AuxDestinazione;
            QSound::play(":/files/sounds/pipe.wav");
        }
        else
            squatting=true;
     }

 }

 void Mario::EndLevelJump()
 {
     jumping = false;
     endJumping();
     moving=false;
     falling=true;
 }
