#ifndef GUSCIO_H
#define GUSCIO_H
#pragma once
#include <QPixmap>
#include "Object.h"

class guscio : public Object
{

 protected:
    //textures
    QPixmap texture_walk[2];
 public:
    //costruttore
    guscio(Object *what);

    //gestisce il movimento
    void movimento(Object *what, Direction fromDir);

    // flag
    bool collidable;
    bool moving;
};

#endif // GUSCIO_H
