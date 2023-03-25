#ifndef PIATTAFORMA_H
#define PIATTAFORMA_H
#include <QPixmap>
#include "Enemy.h"

class piattaforma : public Enemy
{
    protected:

     // textures
     QPixmap texture;

     // animation divisors (inversely proportional to animation speed)
     static const int walk_div= 70; // walking animation

     // è la costante che indica la massima altezza del tubo. Viene settata in base al tubo su cui è la pianta piranha
     int maxY;

     // conta il tempo che la pianta rimane ferma
     int counter_high;

     // la piattaforma sta salendo?
     bool up;

    public:

     piattaforma(QPoint position);

     // pure virtual methods that must be implemented
     virtual std::string name(){ return "piattaforma";}
     virtual void animate();
     virtual void hit(Object *what, Direction fromDir);
     virtual void advance();

     // hurt
     virtual void hurt();

     // set e get di maxY
     void setMaxY(int _maxY){maxY = _maxY;}

     // get up
     bool getUP(){return up;}
};
#endif // PIATTAFORMA_H
