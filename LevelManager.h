#pragma once

#include <QGraphicsScene>
#include <string>

#include "Mario.h"
#include "bandiera.h"

class LevelManager
{
    private:
        QSound* music;

    public:

        // load all items from the given level in the given scene
        // also returns the Mario object
        static Mario* load(std::string level_name, QGraphicsScene * scene);
};
