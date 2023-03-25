#include "LevelManager.h"
#include <iostream>

#include "Background.h"
#include "Block.h"
#include "Box.h"
#include "Brick.h"
#include "Goomba.h"
#include "Mario.h"
#include "Pipe.h"
#include "Terrain.h"
#include "Koopa.h"
#include "bandiera.h"
#include "moneta.h"
#include "pianta_piranha.h"
#include "fine_livello.h"
#include "bowser.h"
#include "ponte.h"
#include "ascia.h"
#include "piattaforma.h"
#include <QSoundEffect>

// load all items from the given level in the given scene
Mario* LevelManager::load(std::string level_name, QGraphicsScene * scene)
{
    Mario* mario = 0;

    if(level_name == "World-1-1")
    {
        // impostiamo la musica
//        music = new QSound(":/sounds/overworld.wav");
//        Game::instance()->setMusic(music);

        // set background color
        scene->setBackgroundBrush(QBrush(QColor(99,133,251)));

		// terrain level
		int terrain_level = 200;

        // welcome message
        new Background(QPoint(40,terrain_level-5.5*16), ":/graphics/welcome.png");

        // sfondo nero nel tubo
        new Background(QPoint(212*16,terrain_level+2*16), ":/Extra_Level_Background.png");

        // terrain
        new Terrain(QRect(0,terrain_level,69*16,30), 0);
        new Terrain(QRect(71*16,terrain_level,17*16,30), 0);
        new Terrain(QRect(92*16,terrain_level,61*16,30), 0);
        new Terrain(QRect(155*16,terrain_level,57*16,30), 0);

        //Block group 1
        new Block(QPoint(137*16,terrain_level-1*16));
        new Block(QPoint(136*16,terrain_level-1*16));
        new Block(QPoint(135*16,terrain_level-1*16));
        new Block(QPoint(134*16,terrain_level-1*16));

        new Block(QPoint(137*16,terrain_level-2*16));
        new Block(QPoint(136*16,terrain_level-2*16));
        new Block(QPoint(135*16,terrain_level-2*16));

        new Block(QPoint(137*16,terrain_level-3*16));
        new Block(QPoint(136*16,terrain_level-3*16));

        new Block(QPoint(137*16,terrain_level-4*16));

        //Block Group 2
        new Block(QPoint(143*16,terrain_level-1*16));
        new Block(QPoint(142*16,terrain_level-1*16));
        new Block(QPoint(141*16,terrain_level-1*16));
        new Block(QPoint(140*16,terrain_level-1*16));

        new Block(QPoint(142*16,terrain_level-2*16));
        new Block(QPoint(141*16,terrain_level-2*16));
        new Block(QPoint(140*16,terrain_level-2*16));

        new Block(QPoint(141*16,terrain_level-3*16));
        new Block(QPoint(140*16,terrain_level-3*16));

        new Block(QPoint(140*16,terrain_level-4*16));

        // Block Group 3
        new Block(QPoint(152*16,terrain_level-1*16));
        new Block(QPoint(151*16,terrain_level-1*16));
        new Block(QPoint(150*16,terrain_level-1*16));
        new Block(QPoint(149*16,terrain_level-1*16));
        new Block(QPoint(148*16,terrain_level-1*16));

        new Block(QPoint(152*16,terrain_level-2*16));
        new Block(QPoint(151*16,terrain_level-2*16));
        new Block(QPoint(150*16,terrain_level-2*16));
        new Block(QPoint(149*16,terrain_level-2*16));

        new Block(QPoint(152*16,terrain_level-3*16));
        new Block(QPoint(151*16,terrain_level-3*16));
        new Block(QPoint(150*16,terrain_level-3*16));

        new Block(QPoint(151*16,terrain_level-4*16));
        new Block(QPoint(152*16,terrain_level-4*16));

        //Block Group 4
        new Block(QPoint(155*16,terrain_level-1*16));
        new Block(QPoint(156*16,terrain_level-1*16));
        new Block(QPoint(157*16,terrain_level-1*16));
        new Block(QPoint(158*16,terrain_level-1*16));

        new Block(QPoint(155*16,terrain_level-2*16));
        new Block(QPoint(156*16,terrain_level-2*16));
        new Block(QPoint(157*16,terrain_level-2*16));

        new Block(QPoint(155*16,terrain_level-3*16));
        new Block(QPoint(156*16,terrain_level-3*16));

        new Block(QPoint(155*16,terrain_level-4*16));

        //Block Group Final
        new Block(QPoint(176*16,terrain_level-1*16));
        new Block(QPoint(177*16,terrain_level-1*16));
        new Block(QPoint(178*16,terrain_level-1*16));
        new Block(QPoint(179*16,terrain_level-1*16));
        new Block(QPoint(180*16,terrain_level-1*16));
        new Block(QPoint(181*16,terrain_level-1*16));
        new Block(QPoint(182*16,terrain_level-1*16));
        new Block(QPoint(183*16,terrain_level-1*16));
        new Block(QPoint(184*16,terrain_level-1*16));
        new Block(QPoint(185*16,terrain_level-1*16));
        new Block(QPoint(186*16,terrain_level-1*16));

        new Block(QPoint(177*16,terrain_level-2*16));
        new Block(QPoint(178*16,terrain_level-2*16));
        new Block(QPoint(179*16,terrain_level-2*16));
        new Block(QPoint(180*16,terrain_level-2*16));
        new Block(QPoint(181*16,terrain_level-2*16));
        new Block(QPoint(182*16,terrain_level-2*16));
        new Block(QPoint(183*16,terrain_level-2*16));
        new Block(QPoint(184*16,terrain_level-2*16));
        new Block(QPoint(185*16,terrain_level-2*16));
        new Block(QPoint(186*16,terrain_level-2*16));

        new Block(QPoint(178*16,terrain_level-3*16));
        new Block(QPoint(179*16,terrain_level-3*16));
        new Block(QPoint(180*16,terrain_level-3*16));
        new Block(QPoint(181*16,terrain_level-3*16));
        new Block(QPoint(182*16,terrain_level-3*16));
        new Block(QPoint(183*16,terrain_level-3*16));
        new Block(QPoint(184*16,terrain_level-3*16));
        new Block(QPoint(185*16,terrain_level-3*16));
        new Block(QPoint(186*16,terrain_level-3*16));

        new Block(QPoint(179*16,terrain_level-4*16));
        new Block(QPoint(180*16,terrain_level-4*16));
        new Block(QPoint(181*16,terrain_level-4*16));
        new Block(QPoint(182*16,terrain_level-4*16));
        new Block(QPoint(183*16,terrain_level-4*16));
        new Block(QPoint(184*16,terrain_level-4*16));
        new Block(QPoint(185*16,terrain_level-4*16));
        new Block(QPoint(186*16,terrain_level-4*16));

        new Block(QPoint(180*16,terrain_level-5*16));
        new Block(QPoint(181*16,terrain_level-5*16));
        new Block(QPoint(182*16,terrain_level-5*16));
        new Block(QPoint(183*16,terrain_level-5*16));
        new Block(QPoint(184*16,terrain_level-5*16));
        new Block(QPoint(185*16,terrain_level-5*16));
        new Block(QPoint(186*16,terrain_level-5*16));

        new Block(QPoint(181*16,terrain_level-6*16));
        new Block(QPoint(182*16,terrain_level-6*16));
        new Block(QPoint(183*16,terrain_level-6*16));
        new Block(QPoint(184*16,terrain_level-6*16));
        new Block(QPoint(185*16,terrain_level-6*16));
        new Block(QPoint(186*16,terrain_level-6*16));

        new Block(QPoint(182*16,terrain_level-7*16));
        new Block(QPoint(183*16,terrain_level-7*16));
        new Block(QPoint(184*16,terrain_level-7*16));
        new Block(QPoint(185*16,terrain_level-7*16));
        new Block(QPoint(186*16,terrain_level-7*16));

        new Block(QPoint(183*16,terrain_level-8*16));
        new Block(QPoint(184*16,terrain_level-8*16));
        new Block(QPoint(185*16,terrain_level-8*16));
        new Block(QPoint(186*16,terrain_level-8*16));

        new Block(QPoint(184*16,terrain_level-9*16));
        new Block(QPoint(185*16,terrain_level-9*16));
        new Block(QPoint(186*16,terrain_level-9*16));

        new Block(QPoint(185*16,terrain_level-10*16));
        new Block(QPoint(186*16,terrain_level-10*16));

		// left boundary
        new Terrain(QRect(-16, 0, 16, 200), 0);

        // background hills/clouds/bushes
        new Background(QPoint(0,terrain_level),       ":/graphics/hill-big.png");
     //   new Background(QPoint(8.5*16,terrain_level-8.5*16),  ":/graphics/cloud-small.png");
        new Background(QPoint(11.5*16,terrain_level), ":/graphics/bush-big.png");
        new Background(QPoint(16*16,terrain_level),   ":/graphics/hill-small.png");
        new Background(QPoint(19.5*16,terrain_level-9.5*16),  ":/graphics/cloud-small.png");
        new Background(QPoint(23.5*16,terrain_level), ":/graphics/bush-small.png");
        new Background(QPoint(27.5*16,terrain_level-8.5*16),  ":/graphics/cloud-big.png");
        new Background(QPoint(36.5*16,terrain_level-9.5*16),  ":/graphics/cloud-med.png");
        new Background(QPoint(41.5*16,terrain_level), ":/graphics/bush-med.png");
        new Background(QPoint(48*16,terrain_level),   ":/graphics/hill-big.png");
        new Background(QPoint(59.5*16,terrain_level), ":/graphics/bush-big.png");
        new Background(QPoint(64*16,terrain_level),   ":/graphics/hill-small.png");

        // Hill Big
       // new Background(QPoint(40*16,terrain_level),       ":/graphics/hill-big.png");
        new Background(QPoint(97*16,terrain_level),       ":/graphics/hill-big.png");
        new Background(QPoint(140*16,terrain_level),       ":/graphics/hill-big.png");
        new Background(QPoint(187*16,terrain_level),       ":/graphics/hill-big.png");

        //Big Bush
      //  new Background(QPoint(38.5*16,terrain_level), ":/graphics/bush-big.png");
        new Background(QPoint(109*16,terrain_level), ":/graphics/bush-big.png");
        new Background(QPoint(137*16,terrain_level), ":/graphics/bush-big.png");

        //Hill Small
    //    new Background(QPoint(41*16,terrain_level),   ":/graphics/hill-small.png");
        new Background(QPoint(112*16,terrain_level),   ":/graphics/hill-small.png");
        new Background(QPoint(158*16,terrain_level),   ":/graphics/hill-small.png");

        //Bush Small
        new Background(QPoint(116*16,terrain_level), ":/graphics/bush-small.png");
        new Background(QPoint(117.5*16,terrain_level), ":/graphics/bush-small.png");
        new Background(QPoint(162.5*16,terrain_level), ":/graphics/bush-small.png");

        //Bush Med
        new Background(QPoint(102*16,terrain_level),  ":/graphics/bush-med.png");

        //Castle
        new Background(QPoint(197*16,terrain_level), ":/graphics/castle.png");

        //Bandiera
        new bandiera(QPoint(194*16,terrain_level),2);
        new bandiera(QPoint(194*16,terrain_level-1*16),2);
        new bandiera(QPoint(194*16,terrain_level-2*16),2);
        new bandiera(QPoint(194*16,terrain_level-3*16),2);
        new bandiera(QPoint(194*16,terrain_level-4*16),2);
        new bandiera(QPoint(194*16,terrain_level-5*16),2);
        new bandiera(QPoint(194*16,terrain_level-6*16),2);
        new bandiera(QPoint(194*16,terrain_level-7*16),2);
        new bandiera(QPoint(194*16,terrain_level-8*16),2);
        new bandiera(QPoint(194*16,terrain_level-9*16),2);
        new bandiera(QPoint(194*16,terrain_level-10*16),2);
        new bandiera(QPoint(194*16,terrain_level-10*16),2);
        new bandiera(QPoint(193*16+9,terrain_level-11*16),1);
        new bandiera(QPoint(194*16,terrain_level-12*16),0);

        //box di fine livello
        new Box(QPoint(195*16,terrain_level), END, VUOTO);
        new Box(QPoint(195*16,terrain_level-1*16), END, VUOTO);
        new Box(QPoint(195*16,terrain_level-2*16), END, VUOTO);
        new Box(QPoint(195*16,terrain_level-3*16), END, VUOTO);
        new Box(QPoint(195*16,terrain_level-4*16), END, VUOTO);
        new Box(QPoint(195*16,terrain_level-5*16), END, VUOTO);
        new Box(QPoint(195*16,terrain_level-6*16), END, VUOTO);
        new Box(QPoint(195*16,terrain_level-7*16), END, VUOTO);
        new Box(QPoint(195*16,terrain_level-8*16), END, VUOTO);
        new Box(QPoint(195*16,terrain_level-9*16), END, VUOTO);
        new Box(QPoint(195*16,terrain_level-10*16), END, VUOTO);
        new Box(QPoint(195*16,terrain_level-11*16), END, VUOTO);
        new Box(QPoint(195*16,terrain_level-12*16), END, VUOTO);

        new Background(QPoint(196*16,terrain_level-9.5*16),  ":/graphics/cloud-small.png");
        new Background(QPoint(205*16,terrain_level-10.5*16),  ":/graphics/cloud-small.png");

        //blocco di fine livello necessario per passaggio al livello successivo
        new fine_livello(QPoint(200*16,terrain_level-1*16), "World-1-2");

		// bricks / boxes
        new Box(QPoint(16*16,terrain_level-4*16), VISIBLE);
        new Brick(QPoint(20*16,terrain_level-4*16),0);
        new Box(QPoint(21*16,terrain_level-4*16), VISIBLE, POWERUP);
        new Brick(QPoint(22*16,terrain_level-4*16),0);
        new Box(QPoint(23*16,terrain_level-4*16));
        new Brick(QPoint(24*16,terrain_level-4*16),0);
        new Box(QPoint(22*16,terrain_level-8*16));
        new Box(QPoint(65*16,terrain_level-5*16), INVISIBLE, LIFE);

        new Background(QPoint(69*16,terrain_level-10*16),  ":/graphics/cloud-small.png");

        //brick/boxes group 1
        new Background(QPoint(76*16,terrain_level-10.5*16),  ":/graphics/cloud-small.png");
        new Brick(QPoint(78*16,terrain_level-4*16),0);
        new Box(QPoint(79*16,terrain_level-4*16), VISIBLE, POWERUP); 
        new Background(QPoint(79*16,terrain_level-9.5*16),  ":/graphics/cloud-big.png");
        new Goomba(QPoint(81*16, terrain_level-8*16), LEFT);
        new Goomba(QPoint(83*16, terrain_level-8*16), LEFT);
        new Brick(QPoint(80*16,terrain_level-4*16),0);
        new Background(QPoint(89*16,terrain_level-11*16),  ":/graphics/cloud-med.png");

        //brick/boxes group 2
        new Brick(QPoint(81*16,terrain_level-8*16),0);
        new Brick(QPoint(82*16,terrain_level-8*16),0);
        new Brick(QPoint(83*16,terrain_level-8*16),0);
        new Brick(QPoint(84*16,terrain_level-8*16),0);
        new Brick(QPoint(85*16,terrain_level-8*16),0);
        new Brick(QPoint(86*16,terrain_level-8*16),0);
        new Brick(QPoint(87*16,terrain_level-8*16),0);
        new Brick(QPoint(88*16,terrain_level-8*16),0);
        new Brick(QPoint(89*16,terrain_level-8*16),0);
        new Brick(QPoint(90*16,terrain_level-8*16),0);
        new Brick(QPoint(91*16,terrain_level-8*16),0);

        //brick/boxes group 3
        new Brick(QPoint(94*16,terrain_level-8*16),0);
        new Brick(QPoint(95*16,terrain_level-8*16),0);
        new Brick(QPoint(96*16,terrain_level-8*16),0);
        new Box(QPoint(97*16,terrain_level-8*16));

        //brick/boxes group 4 (sono i box e i brick sopra all'unico koopa. Attenzione! Gli elementi di questo gruppo non sono contigui)
        new Brick(QPoint(97*16,terrain_level-4*16),0, MONETE);

        new Goomba(QPoint(101*16, terrain_level), LEFT);
        new Goomba(QPoint(102.5*16, terrain_level), LEFT);
        new Brick(QPoint(103*16,terrain_level-4*16),0);
        new Brick(QPoint(104*16,terrain_level-4*16),0, STELLA);

        new Box(QPoint(108*16,terrain_level-4*16));
        new Koopa(QPoint(109.5*16, terrain_level), LEFT);
        new Background(QPoint(109*16,terrain_level-8*16),  ":/graphics/cloud-small.png");
        new Box(QPoint(111*16,terrain_level-4*16));
        new Box(QPoint(111*16,terrain_level-8*16), VISIBLE, POWERUP);
        new Box(QPoint(114*16,terrain_level-4*16));

        new Goomba(QPoint(116*16, terrain_level), LEFT);
        new Goomba(QPoint(117.5*16, terrain_level), LEFT);

        new Brick(QPoint(120*16,terrain_level-4*16),0);
        new Background(QPoint(119*16,terrain_level-9.5*16),  ":/graphics/cloud-small.png");

        new Brick(QPoint(122*16,terrain_level-8*16),0);
        new Brick(QPoint(123*16,terrain_level-8*16),0);
        new Brick(QPoint(124*16,terrain_level-8*16),0);
        new Background(QPoint(125*16,terrain_level-8*16),  ":/graphics/cloud-big.png");

        new Goomba(QPoint(125*16, terrain_level), LEFT);
        new Goomba(QPoint(126.5*16, terrain_level), LEFT);
        new Goomba(QPoint(128*16, terrain_level), LEFT);
        new Goomba(QPoint(129.5*16, terrain_level), LEFT);

        new Brick(QPoint(129*16,terrain_level-8*16),0);
        new Box(QPoint(130*16,terrain_level-8*16));
        new Box(QPoint(131*16,terrain_level-8*16));
        new Brick(QPoint(132*16,terrain_level-8*16),0);
        new Background(QPoint(133*16,terrain_level-10*16),  ":/graphics/cloud-med.png");

        new Brick(QPoint(130*16,terrain_level-4*16),0);
        new Brick(QPoint(131*16,terrain_level-4*16),0);

        //brick/box group 5
        new Brick(QPoint(168*16,terrain_level-4*16),0);
        new Brick(QPoint(169*16,terrain_level-4*16),0);
        new Box(QPoint(170*16,terrain_level-4*16));
        new Brick(QPoint(171*16,terrain_level-4*16),0);

        new Background(QPoint(166*16,terrain_level-10.5*16),  ":/graphics/cloud-small.png");
        new Background(QPoint(171*16,terrain_level-9.5*16),  ":/graphics/cloud-big.png");
        new Background(QPoint(177*16,terrain_level-11*16),  ":/graphics/cloud-med.png");

        new Goomba(QPoint(171*16, terrain_level), LEFT);
        new Goomba(QPoint(172.5*16, terrain_level), LEFT);

        // pipes
        new Pipe(QPoint(28*16, terrain_level), 0);
        new Pipe(QPoint(38*16, terrain_level), 1);
        new Pipe(QPoint(46*16, terrain_level), 4);
        new Pipe(QPoint(57*16, terrain_level), 4, false, QPoint(226*16, terrain_level-12*16));
        new Pipe(QPoint(163*16,terrain_level), 0);
        new Pipe(QPoint(174*16,terrain_level), 0);

        new Pipe(QPoint(236*16,terrain_level), 1, false, QPoint(164*16, terrain_level-4*16));
        new Pipe(QPoint(238*16,terrain_level), 3);
        new Pipe(QPoint(238*16,terrain_level-3*16), 3);
        new Pipe(QPoint(238*16,terrain_level-6*16), 3);
        new Pipe(QPoint(238*16,terrain_level-9*16), 3);
        new Pipe(QPoint(238*16,terrain_level-12*16), 3);

        //Bonus Zone
        new Terrain(QRect(224*16,terrain_level,16*16,30), 1);

        new Brick(QPoint(224*16,terrain_level-1*16),1);
        new Brick(QPoint(224*16,terrain_level-2*16),1);
        new Brick(QPoint(224*16,terrain_level-3*16),1);
        new Brick(QPoint(224*16,terrain_level-4*16),1);
        new Brick(QPoint(224*16,terrain_level-5*16),1);
        new Brick(QPoint(224*16,terrain_level-6*16),1);
        new Brick(QPoint(224*16,terrain_level-7*16),1);
        new Brick(QPoint(224*16,terrain_level-8*16),1);
        new Brick(QPoint(224*16,terrain_level-9*16),1);
        new Brick(QPoint(224*16,terrain_level-10*16),1);
        new Brick(QPoint(224*16,terrain_level-11*16),1);

        new Brick(QPoint(227*16,terrain_level-1*16),1);
        new Brick(QPoint(228*16,terrain_level-1*16),1);
        new Brick(QPoint(229*16,terrain_level-1*16),1);
        new Brick(QPoint(230*16,terrain_level-1*16),1);
        new Brick(QPoint(231*16,terrain_level-1*16),1);
        new Brick(QPoint(232*16,terrain_level-1*16),1);
        new Brick(QPoint(233*16,terrain_level-1*16),1);

        new Brick(QPoint(227*16,terrain_level-2*16),1);
        new Brick(QPoint(228*16,terrain_level-2*16),1);
        new Brick(QPoint(229*16,terrain_level-2*16),1);
        new Brick(QPoint(230*16,terrain_level-2*16),1);
        new Brick(QPoint(231*16,terrain_level-2*16),1);
        new Brick(QPoint(232*16,terrain_level-2*16),1);
        new Brick(QPoint(233*16,terrain_level-2*16),1);

        new Brick(QPoint(227*16,terrain_level-3*16),1);
        new Brick(QPoint(228*16,terrain_level-3*16),1);
        new Brick(QPoint(229*16,terrain_level-3*16),1);
        new Brick(QPoint(230*16,terrain_level-3*16),1);
        new Brick(QPoint(231*16,terrain_level-3*16),1);
        new Brick(QPoint(232*16,terrain_level-3*16),1);
        new Brick(QPoint(233*16,terrain_level-3*16),1);

        new Brick(QPoint(227*16,terrain_level-11*16),1);
        new Brick(QPoint(228*16,terrain_level-11*16),1);
        new Brick(QPoint(229*16,terrain_level-11*16),1);
        new Brick(QPoint(230*16,terrain_level-11*16),1);
        new Brick(QPoint(231*16,terrain_level-11*16),1);
        new Brick(QPoint(232*16,terrain_level-11*16),1);
        new Brick(QPoint(233*16,terrain_level-11*16),1);

        new moneta(QPoint(227*16,terrain_level-4*16),1);
        new moneta(QPoint(228*16,terrain_level-4*16),1);
        new moneta(QPoint(229*16,terrain_level-4*16),1);
        new moneta(QPoint(230*16,terrain_level-4*16),1);
        new moneta(QPoint(231*16,terrain_level-4*16),1);
        new moneta(QPoint(232*16,terrain_level-4*16),1);
        new moneta(QPoint(233*16,terrain_level-4*16),1);

        new moneta(QPoint(227*16,terrain_level-5*16),1);
        new moneta(QPoint(228*16,terrain_level-5*16),1);
        new moneta(QPoint(229*16,terrain_level-5*16),1);
        new moneta(QPoint(230*16,terrain_level-5*16),1);
        new moneta(QPoint(231*16,terrain_level-5*16),1);
        new moneta(QPoint(232*16,terrain_level-5*16),1);
        new moneta(QPoint(233*16,terrain_level-5*16),1);

        // Mario
        mario = new Mario(QPoint(2.5*16, terrain_level-1*16));

        // Goombas
        new Goomba(QPoint(22*16, terrain_level), LEFT);
        new Goomba(QPoint(40*16, terrain_level), LEFT);
        new Goomba(QPoint(51*16, terrain_level), LEFT);
        new Goomba(QPoint(52.5*16, terrain_level), LEFT);

    }

    else if(level_name == "World-1-2")
    {
            // left boundary
            new Terrain(QRect(-16, 0, 16, 200), 0);

            // set background color
            scene->setBackgroundBrush(QBrush(QColor(0,0,0)));

            // terrain level
            int terrain_level = 200;

            // terrain
            new Terrain(QRect(0,terrain_level,81*16,30), 1);
            new Terrain(QRect(84*16,terrain_level,36*16,30), 1);
            new Terrain(QRect(123*16,terrain_level,2*16,30), 1);
            new Terrain(QRect(127*16,terrain_level,12*16,30), 1);
            new Terrain(QRect(147*16,terrain_level,8*16,30), 1);
            new Terrain(QRect(162*16,terrain_level,19*16,30), 1);

            //Bandiera
            new bandiera(QPoint(165*16,terrain_level),2);
            new bandiera(QPoint(165*16,terrain_level-1*16),2);
            new bandiera(QPoint(165*16,terrain_level-2*16),2);
            new bandiera(QPoint(165*16,terrain_level-3*16),2);
            new bandiera(QPoint(165*16,terrain_level-4*16),2);
            new bandiera(QPoint(165*16,terrain_level-5*16),2);
            new bandiera(QPoint(165*16,terrain_level-6*16),2);
            new bandiera(QPoint(165*16,terrain_level-7*16),2);
            new bandiera(QPoint(165*16,terrain_level-8*16),2);
            new bandiera(QPoint(165*16,terrain_level-9*16),2);
            new bandiera(QPoint(165*16,terrain_level-10*16),2);
            new bandiera(QPoint(165*16,terrain_level-10*16),2);
            new bandiera(QPoint(164*16+9,terrain_level-11*16),1);
            new bandiera(QPoint(165*16,terrain_level-12*16),0);

            //box di fine livello
            new Box(QPoint(166*16,terrain_level), END, VUOTO);
            new Box(QPoint(166*16,terrain_level-1*16), END, VUOTO);
            new Box(QPoint(166*16,terrain_level-2*16), END, VUOTO);
            new Box(QPoint(166*16,terrain_level-3*16), END, VUOTO);
            new Box(QPoint(166*16,terrain_level-4*16), END, VUOTO);
            new Box(QPoint(166*16,terrain_level-5*16), END, VUOTO);
            new Box(QPoint(166*16,terrain_level-6*16), END, VUOTO);
            new Box(QPoint(166*16,terrain_level-7*16), END, VUOTO);
            new Box(QPoint(166*16,terrain_level-8*16), END, VUOTO);
            new Box(QPoint(166*16,terrain_level-9*16), END, VUOTO);
            new Box(QPoint(166*16,terrain_level-10*16), END, VUOTO);
            new Box(QPoint(166*16,terrain_level-11*16), END, VUOTO);
            new Box(QPoint(166*16,terrain_level-12*16), END, VUOTO);

            // end pipes
            new Pipe(QPoint(169*16, terrain_level), 2);
            new Pipe(QPoint(170.5*16, terrain_level), 3);
            new Pipe(QPoint(170.5*16, terrain_level-3*16), 3);
            new Pipe(QPoint(170.5*16, terrain_level-6*16), 3);
            new Pipe(QPoint(170.5*16, terrain_level-9*16), 3);
            new Pipe(QPoint(170.5*16, terrain_level-12*16), 3);

            // blocco di fine livello
            new fine_livello(QPoint(168*16, terrain_level-1*16), "World-1-4");

            //block / brick / box group 1

            new Box(QPoint(11*16,terrain_level-4*16),VISIBLE, POWERUP);
            new Box(QPoint(12*16,terrain_level-4*16));
            new Box(QPoint(13*16,terrain_level-4*16));
            new Box(QPoint(14*16,terrain_level-4*16));
            new Box(QPoint(15*16,terrain_level-4*16));

            new Goomba(QPoint(16*16,terrain_level-1*16), LEFT, 1);
            new Goomba(QPoint(18*16,terrain_level-2*16), LEFT, 1);
            new Goomba(QPoint(30*16,terrain_level-1*16), LEFT, 1);

            new Block(QPoint(18*16,terrain_level-1*16),1);
            new Block(QPoint(20*16,terrain_level-1*16),1);
            new Block(QPoint(20*16,terrain_level-2*16),1);
            new Block(QPoint(22*16,terrain_level-1*16),1);
            new Block(QPoint(22*16,terrain_level-2*16),1);
            new Block(QPoint(22*16,terrain_level-3*16),1);
            new Block(QPoint(24*16,terrain_level-1*16),1);
            new Block(QPoint(24*16,terrain_level-2*16),1);
            new Block(QPoint(24*16,terrain_level-3*16),1);
            new Block(QPoint(24*16,terrain_level-4*16),1);
            new Block(QPoint(26*16,terrain_level-1*16),1);
            new Block(QPoint(26*16,terrain_level-2*16),1);
            new Block(QPoint(26*16,terrain_level-3*16),1);
            new Block(QPoint(26*16,terrain_level-4*16),1);
            new Block(QPoint(28*16,terrain_level-1*16),1);
            new Block(QPoint(28*16,terrain_level-2*16),1);
            new Block(QPoint(28*16,terrain_level-3*16),1);
            new Brick(QPoint(30*16,terrain_level-5*16),1,MONETE);
            new Block(QPoint(32*16,terrain_level-1*16),1);
            new Block(QPoint(32*16,terrain_level-2*16),1);
            new Block(QPoint(32*16,terrain_level-3*16),1);
            new Block(QPoint(34*16,terrain_level-1*16),1);
            new Block(QPoint(34*16,terrain_level-2*16),1);

            new moneta(QPoint(41*16,terrain_level-5*16),1);
            new moneta(QPoint(42*16,terrain_level-7*16),1);
            new moneta(QPoint(43*16,terrain_level-7*16),1);
            new moneta(QPoint(44*16,terrain_level-7*16),1);
            new moneta(QPoint(45*16,terrain_level-7*16),1);
            new moneta(QPoint(46*16,terrain_level-5*16),1);

            new Brick(QPoint(40*16,terrain_level-4*16),1);
            new Brick(QPoint(40*16,terrain_level-5*16),1);
            new Brick(QPoint(40*16,terrain_level-6*16),1);
            new Brick(QPoint(41*16,terrain_level-4*16),1); 
            new Brick(QPoint(42*16,terrain_level-4*16),1);
            new Brick(QPoint(42*16,terrain_level-5*16),1);
            new Brick(QPoint(42*16,terrain_level-6*16),1);
            new Brick(QPoint(43*16,terrain_level-6*16),1);
            new Brick(QPoint(44*16,terrain_level-6*16),1);
            new Brick(QPoint(45*16,terrain_level-4*16),1);
            new Brick(QPoint(45*16,terrain_level-5*16),1);
            new Brick(QPoint(45*16,terrain_level-6*16),1);
            new Brick(QPoint(46*16,terrain_level-4*16),1);
            new Brick(QPoint(47*16,terrain_level-4*16),1);
            new Brick(QPoint(47*16,terrain_level-5*16),1);
            new Brick(QPoint(47*16,terrain_level-6*16),1, STELLA);

            new Koopa(QPoint(44*16,terrain_level-1*16), LEFT, 1);
            new Koopa(QPoint(46*16,terrain_level-1*16), LEFT, 1);

            new Brick(QPoint(53*16,terrain_level-4*16),1);
            new Brick(QPoint(53*16,terrain_level-5*16),1);
            new Brick(QPoint(53*16,terrain_level-6*16),1);
            new Brick(QPoint(53*16,terrain_level-7*16),1);
            new Brick(QPoint(53*16,terrain_level-8*16),1);
            new Brick(QPoint(54*16,terrain_level-4*16),1);
            new Brick(QPoint(54*16,terrain_level-5*16),1);
            new Brick(QPoint(54*16,terrain_level-6*16),1);
            new Brick(QPoint(54*16,terrain_level-7*16),1);
            new Brick(QPoint(54*16,terrain_level-8*16),1);

            new moneta(QPoint(59*16,terrain_level-5*16),1);
            new moneta(QPoint(60*16,terrain_level-5*16),1);
            new moneta(QPoint(61*16,terrain_level-5*16),1);
            new moneta(QPoint(62*16,terrain_level-5*16),1);

            new Brick(QPoint(55*16,terrain_level-2*16),1);
            new Brick(QPoint(55*16,terrain_level-3*16),1);
            new Brick(QPoint(55*16,terrain_level-4*16),1);
            new Brick(QPoint(55*16,terrain_level-9*16),1);
            new Brick(QPoint(55*16,terrain_level-10*16),1);
            new Brick(QPoint(56*16,terrain_level-2*16),1);
            new Brick(QPoint(56*16,terrain_level-3*16),1);
            new Brick(QPoint(56*16,terrain_level-4*16),1);
            new Brick(QPoint(56*16,terrain_level-9*16),1);
            new Brick(QPoint(56*16,terrain_level-10*16),1);

            new Brick(QPoint(59*16,terrain_level-4*16),1);
            new Brick(QPoint(60*16,terrain_level-4*16),1);
            new Brick(QPoint(61*16,terrain_level-4*16),1);
            new Brick(QPoint(62*16,terrain_level-4*16),1);
            new Brick(QPoint(59*16,terrain_level-9*16),1);
            new Brick(QPoint(60*16,terrain_level-9*16),1);
            new Brick(QPoint(61*16,terrain_level-9*16),1);
            new Brick(QPoint(62*16,terrain_level-9*16),1);
            new Brick(QPoint(59*16,terrain_level-10*16),1);
            new Brick(QPoint(60*16,terrain_level-10*16),1);
            new Brick(QPoint(61*16,terrain_level-10*16),1);
            new Brick(QPoint(62*16,terrain_level-10*16),1);
            new Brick(QPoint(63*16,terrain_level-4*16),1);
            new Brick(QPoint(64*16,terrain_level-4*16),1);
            new Brick(QPoint(63*16,terrain_level-5*16),1);
            new Brick(QPoint(64*16,terrain_level-5*16),1);
            new Brick(QPoint(63*16,terrain_level-6*16),1);
            new Brick(QPoint(64*16,terrain_level-6*16),1);
            new Brick(QPoint(63*16,terrain_level-7*16),1);
            new Brick(QPoint(64*16,terrain_level-7*16),1);
            new Brick(QPoint(63*16,terrain_level-8*16),1);
            new Brick(QPoint(64*16,terrain_level-8*16),1);
            new Brick(QPoint(63*16,terrain_level-9*16),1);
            new Brick(QPoint(64*16,terrain_level-9*16),1);
            new Brick(QPoint(63*16,terrain_level-10*16),1);
            new Brick(QPoint(64*16,terrain_level-10*16),1);

            new Koopa(QPoint(60*16,terrain_level-1*16), LEFT, 1);
            new Goomba(QPoint(63*16,terrain_level-1*16), LEFT, 1);
            new Goomba(QPoint(64*16,terrain_level-1*16), LEFT, 1);

            new moneta(QPoint(69*16,terrain_level-4*16),1);

            new Brick(QPoint(68*16,terrain_level-4*16),1);
            new Brick(QPoint(69*16,terrain_level-4*16),1);
            new Brick(QPoint(70*16,terrain_level-4*16),1);
            new Brick(QPoint(68*16,terrain_level-5*16),1);
            new Brick(QPoint(70*16,terrain_level-5*16),1, POWERUP);
            new Brick(QPoint(68*16,terrain_level-6*16),1);
            new Brick(QPoint(68*16,terrain_level-7*16),1);
            new Brick(QPoint(68*16,terrain_level-8*16),1);
            new Brick(QPoint(67*16,terrain_level-9*16),1);
            new Brick(QPoint(68*16,terrain_level-9*16),1);
            new Brick(QPoint(69*16,terrain_level-9*16),1);
            new Brick(QPoint(70*16,terrain_level-9*16),1);
            new Brick(QPoint(67*16,terrain_level-10*16),1);
            new Brick(QPoint(68*16,terrain_level-10*16),1);
            new Brick(QPoint(69*16,terrain_level-10*16),1);
            new Brick(QPoint(70*16,terrain_level-10*16),1);

            new Goomba(QPoint(74*16,terrain_level-9*16), LEFT, 1);

            new Brick(QPoint(73*16,terrain_level-4*16),1);
            new Brick(QPoint(74*16,terrain_level-4*16),1);
            new Brick(QPoint(73*16,terrain_level-5*16),1);
            new Brick(QPoint(74*16,terrain_level-5*16),1, MONETE);
            new Brick(QPoint(73*16,terrain_level-6*16),1);
            new Brick(QPoint(74*16,terrain_level-6*16),1);
            new Brick(QPoint(73*16,terrain_level-7*16),1);
            new Brick(QPoint(74*16,terrain_level-7*16),1);
            new Brick(QPoint(73*16,terrain_level-8*16),1);
            new Brick(QPoint(74*16,terrain_level-8*16),1);

            new Goomba(QPoint(77*16,terrain_level-1*16), LEFT, 1);
            new Goomba(QPoint(79*16,terrain_level-1*16), LEFT, 1);

            new Brick(QPoint(77*16,terrain_level-4*16),1);
            new Brick(QPoint(78*16,terrain_level-4*16),1);
            new Brick(QPoint(79*16,terrain_level-4*16),1);
            new Brick(QPoint(80*16,terrain_level-4*16),1);
            new Brick(QPoint(77*16,terrain_level-9*16),1);
            new Brick(QPoint(78*16,terrain_level-9*16),1);
            new Brick(QPoint(79*16,terrain_level-9*16),1);
            new Brick(QPoint(80*16,terrain_level-9*16),1);
            new Brick(QPoint(77*16,terrain_level-10*16),1);
            new Brick(QPoint(78*16,terrain_level-10*16),1);
            new Brick(QPoint(79*16,terrain_level-10*16),1);
            new Brick(QPoint(80*16,terrain_level-10*16),1);

            //bricks / pipe group 2
            new Brick(QPoint(85*16,terrain_level-5*16),1);
            new Brick(QPoint(85*16,terrain_level-6*16),1);
            new Brick(QPoint(86*16,terrain_level-5*16),1);
            new Brick(QPoint(86*16,terrain_level-6*16),1);
            new Brick(QPoint(87*16,terrain_level-5*16),1);
            new Brick(QPoint(87*16,terrain_level-6*16),1);
            new Brick(QPoint(88*16,terrain_level-5*16),1);
            new Brick(QPoint(88*16,terrain_level-6*16),1);
            new Brick(QPoint(89*16,terrain_level-5*16),1);
            new Brick(QPoint(89*16,terrain_level-6*16),1);
            new Brick(QPoint(90*16,terrain_level-5*16),1);
            new Brick(QPoint(90*16,terrain_level-6*16),1);
            new Brick(QPoint(91*16,terrain_level-5*16),1);
            new Brick(QPoint(91*16,terrain_level-6*16),1);

            new moneta(QPoint(85*16,terrain_level-6*16),1);
            new moneta(QPoint(86*16,terrain_level-6*16),1);
            new moneta(QPoint(87*16,terrain_level-6*16),1);
            new moneta(QPoint(88*16,terrain_level-6*16),1);
            new moneta(QPoint(89*16,terrain_level-6*16),1);
            new moneta(QPoint(90*16,terrain_level-6*16),1);

            new Goomba(QPoint(100*16,terrain_level-1*16), LEFT, 1);
            new Goomba(QPoint(102*16,terrain_level-1*16), LEFT, 1);
            new Goomba(QPoint(104*16,terrain_level-1*16), LEFT, 1);

            new pianta_piranha(QPoint(105.5*16, terrain_level-1*16),1);
            new pianta_piranha(QPoint(110.5*16, terrain_level-1*16),4);
            new pianta_piranha(QPoint(116.5*16, terrain_level-1*16),0);

            new Pipe(QPoint(105*16, terrain_level), 1, true);
            new Pipe(QPoint(110*16, terrain_level), 4, true);
            new Pipe(QPoint(116*16, terrain_level), 0, true);

            new Goomba(QPoint(1144*16,terrain_level-1*16), LEFT, 1);

            //bricks group 3
            new Brick(QPoint(123*16,terrain_level-1*16),1);
            new Brick(QPoint(124*16,terrain_level-1*16),1);
            new Brick(QPoint(123*16,terrain_level-2*16),1);
            new Brick(QPoint(124*16,terrain_level-2*16),1);
            new Brick(QPoint(123*16,terrain_level-3*16),1);
            new Brick(QPoint(124*16,terrain_level-3*16),1);

            //block group 4
            new Block(QPoint(134*16,terrain_level-1*16),1);
            new Block(QPoint(135*16,terrain_level-1*16),1);
            new Block(QPoint(136*16,terrain_level-1*16),1);
            new Block(QPoint(137*16,terrain_level-1*16),1);
            new Block(QPoint(138*16,terrain_level-1*16),1);
            new Block(QPoint(135*16,terrain_level-2*16),1);
            new Block(QPoint(136*16,terrain_level-2*16),1);
            new Block(QPoint(137*16,terrain_level-2*16),1);
            new Block(QPoint(138*16,terrain_level-2*16),1);
            new Block(QPoint(136*16,terrain_level-3*16),1);
            new Block(QPoint(137*16,terrain_level-3*16),1);
            new Block(QPoint(138*16,terrain_level-3*16),1);
            new Block(QPoint(137*16,terrain_level-4*16),1);
            new Block(QPoint(138*16,terrain_level-4*16),1);

            new Goomba(QPoint(136*16,terrain_level-4*16), LEFT, 1);
            new Goomba(QPoint(138*16,terrain_level-5*16), LEFT, 1);

            new piattaforma(QPoint(140*16,terrain_level-1*16));

            //bricks group 5
            new Brick(QPoint(147*16,terrain_level-6*16),1);
            new Brick(QPoint(148*16,terrain_level-6*16),1);
            new Brick(QPoint(149*16,terrain_level-6*16),1);
            new Brick(QPoint(150*16,terrain_level-6*16),1);
            new Brick(QPoint(151*16,terrain_level-6*16),1);
            new Brick(QPoint(152*16,terrain_level-6*16),1);
            new Brick(QPoint(153*16,terrain_level-6*16),1, POWERUP);

            new Koopa(QPoint(150*16,terrain_level-1*16), LEFT, 1);

            new Brick(QPoint(147*16,terrain_level-1*16),1, MONETE);
            new Brick(QPoint(154*16,terrain_level-1*16),1, MONETE);

            new piattaforma(QPoint(158*16,terrain_level-1*16));

            // bricks group high
            new Brick(QPoint(6*16,terrain_level-11*16),1);
            new Brick(QPoint(7*16,terrain_level-11*16),1);
            new Brick(QPoint(8*16,terrain_level-11*16),1);
            new Brick(QPoint(9*16,terrain_level-11*16),1);
            new Brick(QPoint(10*16,terrain_level-11*16),1);
            new Brick(QPoint(11*16,terrain_level-11*16),1);
            new Brick(QPoint(12*16,terrain_level-11*16),1);
            new Brick(QPoint(13*16,terrain_level-11*16),1);
            new Brick(QPoint(14*16,terrain_level-11*16),1);
            new Brick(QPoint(15*16,terrain_level-11*16),1);
            new Brick(QPoint(16*16,terrain_level-11*16),1);
            new Brick(QPoint(17*16,terrain_level-11*16),1);
            new Brick(QPoint(18*16,terrain_level-11*16),1);
            new Brick(QPoint(19*16,terrain_level-11*16),1);
            new Brick(QPoint(20*16,terrain_level-11*16),1);
            new Brick(QPoint(21*16,terrain_level-11*16),1);
            new Brick(QPoint(22*16,terrain_level-11*16),1);
            new Brick(QPoint(23*16,terrain_level-11*16),1);
            new Brick(QPoint(24*16,terrain_level-11*16),1);
            new Brick(QPoint(25*16,terrain_level-11*16),1);
            new Brick(QPoint(26*16,terrain_level-11*16),1);
            new Brick(QPoint(27*16,terrain_level-11*16),1);
            new Brick(QPoint(28*16,terrain_level-11*16),1);
            new Brick(QPoint(29*16,terrain_level-11*16),1);
            new Brick(QPoint(30*16,terrain_level-11*16),1);
            new Brick(QPoint(31*16,terrain_level-11*16),1);
            new Brick(QPoint(32*16,terrain_level-11*16),1);
            new Brick(QPoint(33*16,terrain_level-11*16),1);
            new Brick(QPoint(34*16,terrain_level-11*16),1);
            new Brick(QPoint(35*16,terrain_level-11*16),1);
            new Brick(QPoint(36*16,terrain_level-11*16),1);
            new Brick(QPoint(37*16,terrain_level-11*16),1);
            new Brick(QPoint(38*16,terrain_level-11*16),1);
            new Brick(QPoint(39*16,terrain_level-11*16),1);
            new Brick(QPoint(40*16,terrain_level-11*16),1);
            new Brick(QPoint(41*16,terrain_level-11*16),1);
            new Brick(QPoint(42*16,terrain_level-11*16),1);
            new Brick(QPoint(43*16,terrain_level-11*16),1);
            new Brick(QPoint(44*16,terrain_level-11*16),1);
            new Brick(QPoint(45*16,terrain_level-11*16),1);
            new Brick(QPoint(46*16,terrain_level-11*16),1);
            new Brick(QPoint(47*16,terrain_level-11*16),1);
            new Brick(QPoint(48*16,terrain_level-11*16),1);
            new Brick(QPoint(49*16,terrain_level-11*16),1);
            new Brick(QPoint(50*16,terrain_level-11*16),1);
            new Brick(QPoint(51*16,terrain_level-11*16),1);
            new Brick(QPoint(52*16,terrain_level-11*16),1);
            new Brick(QPoint(53*16,terrain_level-11*16),1);
            new Brick(QPoint(54*16,terrain_level-11*16),1);
            new Brick(QPoint(55*16,terrain_level-11*16),1);
            new Brick(QPoint(56*16,terrain_level-11*16),1);
            new Brick(QPoint(57*16,terrain_level-11*16),1);
            new Brick(QPoint(58*16,terrain_level-11*16),1);
            new Brick(QPoint(59*16,terrain_level-11*16),1);
            new Brick(QPoint(60*16,terrain_level-11*16),1);
            new Brick(QPoint(61*16,terrain_level-11*16),1);
            new Brick(QPoint(62*16,terrain_level-11*16),1);
            new Brick(QPoint(63*16,terrain_level-11*16),1);
            new Brick(QPoint(64*16,terrain_level-11*16),1);
            new Brick(QPoint(65*16,terrain_level-11*16),1);
            new Brick(QPoint(66*16,terrain_level-11*16),1);
            new Brick(QPoint(67*16,terrain_level-11*16),1);
            new Brick(QPoint(68*16,terrain_level-11*16),1);
            new Brick(QPoint(69*16,terrain_level-11*16),1);
            new Brick(QPoint(70*16,terrain_level-11*16),1);
            new Brick(QPoint(71*16,terrain_level-11*16),1);
            new Brick(QPoint(72*16,terrain_level-11*16),1);
            new Brick(QPoint(73*16,terrain_level-11*16),1);
            new Brick(QPoint(74*16,terrain_level-11*16),1);
            new Brick(QPoint(75*16,terrain_level-11*16),1);
            new Brick(QPoint(76*16,terrain_level-11*16),1);
            new Brick(QPoint(77*16,terrain_level-11*16),1);
            new Brick(QPoint(78*16,terrain_level-11*16),1);
            new Brick(QPoint(79*16,terrain_level-11*16),1);
            new Brick(QPoint(80*16,terrain_level-11*16),1);
            new Brick(QPoint(81*16,terrain_level-11*16),1);
            new Brick(QPoint(82*16,terrain_level-11*16),1);
            new Brick(QPoint(83*16,terrain_level-11*16),1);
            new Brick(QPoint(84*16,terrain_level-11*16),1);
            new Brick(QPoint(85*16,terrain_level-11*16),1);
            new Brick(QPoint(86*16,terrain_level-11*16),1);
            new Brick(QPoint(87*16,terrain_level-11*16),1);
            new Brick(QPoint(88*16,terrain_level-11*16),1);
            new Brick(QPoint(89*16,terrain_level-11*16),1);
            new Brick(QPoint(90*16,terrain_level-11*16),1);
            new Brick(QPoint(91*16,terrain_level-11*16),1, POWERUP);
            new Brick(QPoint(92*16,terrain_level-11*16),1);
            new Brick(QPoint(93*16,terrain_level-11*16),1);
            new Brick(QPoint(94*16,terrain_level-11*16),1);
            new Brick(QPoint(95*16,terrain_level-11*16),1);
            new Brick(QPoint(96*16,terrain_level-11*16),1);
            new Brick(QPoint(97*16,terrain_level-11*16),1);
            new Brick(QPoint(98*16,terrain_level-11*16),1);
            new Brick(QPoint(99*16,terrain_level-11*16),1);
            new Brick(QPoint(100*16,terrain_level-11*16),1);
            new Brick(QPoint(101*16,terrain_level-11*16),1);
            new Brick(QPoint(102*16,terrain_level-11*16),1);
            new Brick(QPoint(103*16,terrain_level-11*16),1);
            new Brick(QPoint(104*16,terrain_level-11*16),1);
            new Brick(QPoint(105*16,terrain_level-11*16),1);
            new Brick(QPoint(106*16,terrain_level-11*16),1);
            new Brick(QPoint(107*16,terrain_level-11*16),1);
            new Brick(QPoint(108*16,terrain_level-11*16),1);
            new Brick(QPoint(109*16,terrain_level-11*16),1);
            new Brick(QPoint(110*16,terrain_level-11*16),1);
            new Brick(QPoint(111*16,terrain_level-11*16),1);
            new Brick(QPoint(112*16,terrain_level-11*16),1);
            new Brick(QPoint(113*16,terrain_level-11*16),1);
            new Brick(QPoint(114*16,terrain_level-11*16),1);
            new Brick(QPoint(115*16,terrain_level-11*16),1);
            new Brick(QPoint(116*16,terrain_level-11*16),1);
            new Brick(QPoint(117*16,terrain_level-11*16),1);
            new Brick(QPoint(118*16,terrain_level-11*16),1);
            new Brick(QPoint(119*16,terrain_level-11*16),1);
            new Brick(QPoint(120*16,terrain_level-11*16),1);
            new Brick(QPoint(121*16,terrain_level-11*16),1);
            new Brick(QPoint(122*16,terrain_level-11*16),1);
            new Brick(QPoint(123*16,terrain_level-11*16),1);
            new Brick(QPoint(124*16,terrain_level-11*16),1);
            new Brick(QPoint(125*16,terrain_level-11*16),1);
            new Brick(QPoint(126*16,terrain_level-11*16),1);
            new Brick(QPoint(127*16,terrain_level-11*16),1);
            new Brick(QPoint(128*16,terrain_level-11*16),1);
            new Brick(QPoint(129*16,terrain_level-11*16),1);
            new Brick(QPoint(130*16,terrain_level-11*16),1);
            new Brick(QPoint(131*16,terrain_level-11*16),1);
            new Brick(QPoint(132*16,terrain_level-11*16),1);
            new Brick(QPoint(133*16,terrain_level-11*16),1);
            new Brick(QPoint(134*16,terrain_level-11*16),1);
            new Brick(QPoint(135*16,terrain_level-11*16),1);
            new Brick(QPoint(136*16,terrain_level-11*16),1);
            new Brick(QPoint(137*16,terrain_level-11*16),1);
            new Brick(QPoint(138*16,terrain_level-11*16),1);

            // Mario
            mario = new Mario(QPoint(2.5*16, terrain_level-12*16));
    }

    else if(level_name == "World-1-4")
    {
        // left boundary
        new Terrain(QRect(-16, 0, 16, 200), 0);

        // set background color
        scene->setBackgroundBrush(QBrush(QColor(0,0,0)));

        // terrain level
        int terrain_level = 200;

        // terrain
        new Terrain(QRect(0, terrain_level-3*16, 81*16, 80), 2);
        new Terrain(QRect(101*16, terrain_level-3*16, 15*16, 90 ),2);
        new Terrain(QRect(116*16, terrain_level-0*16, 25*16, 42 ),2);

        new Terrain(QRect(0, terrain_level-13*16, 141*16, 16 ),2);

        new Terrain(QRect(140*16, terrain_level-13*16, 1*16, 13*16 ),2);

        // Peach
        new Background(QPoint(130*16,terrain_level), ":files/images/peach_mod.bmp");

        QGraphicsTextItem* text = scene->addText("THANK YOU MARIO! BUT YOUR PRINCESS IS IN ANOTHER CASTLE!");
        text->setDefaultTextColor(Qt::white);
        text->setPos(120*16,terrain_level-6*16);

        // ponte
        new ponte(QRect(81*16, terrain_level-2*16, 20*16, 15));

        // start pipe
        new Pipe(QPoint(2.5*16, terrain_level-3*16), 0);

        //bowser
        new bowser(QPoint(85*16, terrain_level-3*16));

        // ascia
        new ascia(QPoint(102*16,terrain_level-4*16));

        // Mario
        mario = new Mario(QPoint(3*16, terrain_level-7*16));
    }

    else
        std::cerr << "Level not implemented"<<endl;

    return mario;
}
