#include "Entity.h"
#include "Game.h"
#include "Mario.h"
#include "Box.h"
#include "Enemy.h"
#include "pianta_piranha.h"
#include "Pipe.h"
#include "iostream"
using namespace std;

Entity::Entity() : Object()
{
	// physics parameters
    moving_speed     = 1;
	jumping_speed    = 2;
	falling_speed    = 2;
	moving_speed_div = 2;

	// flags
//    dir     = RIGHT;
    moving  = true;
	jumping = false;
	falling = true;		// we can create entities in mid air and they will fall
	phantom = false;
	dying   = false;
	dead    = false;
	freezed = false;
	slow	= false;
	collectable = false;
    dead_alt = true;

	// counters
	jump_counter    = 0;
	death_counter   = 0;
	walk_counter    = 0;
	phantom_counter = 0;
	freeze_counter	= 0;

	// durations
	jumping_duration = 30;
	death_duration   = 100;
	phantom_duration = 200;
	freeze_duration  = 80;

	// others
    walkable_object = 0;
}

void Entity::startJumping()
{
    // entity can jump only when it is not falling
	if(!falling && !jumping)
	{
		walkable_object = 0;
		jumping = true;
	}
}

void Entity::endJumping()
{
	if(jumping)
	{
		jumping = false;
		jump_counter = 0;
		falling = true;
	}
}


void Entity::startPhantom()
{
	if(!phantom)
	{
		phantom = true;
		phantom_counter = 0;
		setOpacity(0.5);
	}
}
void Entity::endPhantom()
{
	if(phantom)
	{
		phantom = false;
		phantom_counter = 0;
		setOpacity(1.0);
	}
}

void Entity::advance()
{
    // NOTE: every movement is embedded in a prevPos = pos() ... solveCollisions() block

	// do nothing if object is freezed
	if(freezed)
	{
		freeze_counter++;
		if(freeze_counter > freeze_duration)
		{
			freezed = false;
			freeze_counter = 0;
		}
		else
			return;
	}

    // moving
    if(moving)
    {
        prevPos = pos();

		// slow mode: move 1 pixel every moving_speed_div frames
        if(slow)
        {
            //printf("sono slow \n");
            moving_speed = walk_counter % moving_speed_div == 0;
        }
        if(dir == RIGHT)
            setX(x() + moving_speed);
        else if(dir == LEFT)
			setX(x() - moving_speed);
		else if(dir == UP)
			setY(y() - moving_speed);
            else if(dir == DOWN)
            setY(y() + moving_speed);
        solveCollisions();
    }

    // jumping
    if(jumping)
    {
		prevPos = pos();
	
        // move upwards
        setY(y() - jumping_speed);
	
        // increase jump frame count
        jump_counter += jumping_speed;
	
        // end jumping when frame count reaches the defined limit
        if(jump_counter > jumping_duration)
            endJumping();
	
        solveCollisions();
    }

    // if the entity is not touching its walkable object anymore
    // we have to start falling
	if(walkable_object && !touchingDirection(walkable_object))
		falling = true;

    // falling
	if(falling)
	{
		prevPos = pos();

		setY(y() + falling_speed);

		solveCollisions();
	}

	// if we fall beyond the scene bottom limit
	// we have to die (if not dead already)
	if(y() > Game::instance()->getScene()->sceneRect().height() && !dying)
		die();

	// if dead, increase death counter and remove
	// item from scene if required
	if(dying)
	{
		death_counter++;
		if(death_counter > death_duration)
		{
			dead = true;
			setVisible(false);
		}
	}
}

void Entity::solveCollisions()
{
	// if the entity cannot collide or is 100% dead, we avoid
	// solving possible collisions
	if(!collidable || dead)
		return;

    // get collisions
    QList<QGraphicsItem*> colliding_items = collidingItems();

	// will be set to true if we collide an impenetrable object
	bool revert = false;	

    // manage collisions
    for(auto & ci : colliding_items)
    {
		// convert to game object, and skip if conversion
		// does not work (should never happen)
		Object *obj = dynamic_cast<Object*>(ci);
        if(!obj)
        {
          //  cout<<"not work \n";
			continue;
        }

		// ignore collision if obj is not collidable
		if( ! obj->isCollidable())
        {
            //cout<<obj->name()<<"not collidable \n";
			continue;
        }
		// ignore collisions if a phantom Entity is involved
		Entity* entity_obj = dynamic_cast<Entity*>(obj);
		if(entity_obj && (entity_obj->isPhantom() || phantom))
        {
          //  cout<<"phantom \n";
			continue;
        }
		// ignore collisions between Mario's collectables and Enemies
		if( (dynamic_cast<Enemy*>(obj) && this->isCollectable()) ||
			(entity_obj && entity_obj->isCollectable() && dynamic_cast<Enemy*>(this)))
        {
            //cout<<"collectables and enemy \n";
			continue;
         }
		
        // get collision direction
        Direction coll_dir = collisionDirection(obj);
   
		// if it is not possible to calculate it, we skip current collision
        // (e.g. this may happen if we have solved the collision earlier)
        if(!coll_dir)
        {
         //   cout<<"not coll_dir \n";
            continue;
        }

		// special case 0: ignore collisions between Mario and 
		// Invisible boxes
		Mario* mario = dynamic_cast<Mario*>(this);
		Box* box = dynamic_cast<Box*>(obj);
		if(mario && box && box->getVisibility() == INVISIBLE && 
			coll_dir != UP && !mario->isFalling())
        {
           // cout<<"invisible boxes \n";
			continue;
        }

        // special case 1: touching a walkable object while falling
        // ---> end falling and set walkable object
        if(coll_dir == DOWN && falling && obj->isWalkable())
        {
           // cout<<"walkable object \n";
            falling = false;
            walkable_object = obj;
        }

        // special case 2: touching an object while jumping
        // --> end jumping
        if(coll_dir == UP && jumping)
        {
           // cout<<"object while jump \n";
            endJumping();
        }

        // special case 3: collisione tra tubo
        pianta_piranha* pianta = dynamic_cast<pianta_piranha*>(this);
        Pipe* pipe = dynamic_cast<Pipe*>(obj);
        if(pianta && pipe /*&& coll_dir == DOWN*/)
        {
            continue;
        }

        // the two objects hit each other
        //cout<<name()<<"&"<<obj->name()<<endl;

        obj->hit(this, inverse(coll_dir));
		this->hit(obj, coll_dir);

        // if we ended up here, it means we have to revert
		// to the previous position (impenetrable object)
		revert = true;
    }

	// revert to previous position if needed
	if(revert)
    {
        setPos(prevPos);
    }
}

void Entity::die()
{
    // only a full living entity can die
    if(!dying && !dead)
    {
        // scheduled for death
        dying = true;

        // start death counter
        death_counter = 0;

        // invisible to other entities
        phantom = true;

        // cannot move
        moving = false;
    }
}

void Entity::die_alt()
{
    // only a full living entity can die
    if(!dying && !dead && dead_alt)
    {

        // invisible to other entities
        phantom = true;

        // cannot move
        moving =false;

        startJumping();

        setPixmap(pixmap().transformed(QTransform().scale(1,-1)));

        collidable =false;

        QSound::play(":/files/sounds/shot.wav");
    }
}


