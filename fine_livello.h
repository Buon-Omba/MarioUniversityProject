#ifndef FINE_LIVELLO_H
#define FINE_LIVELLO_H

#include "Inert.h"
#include "Game.h"

class fine_livello : public Inert
{
    protected:

    //textures
    QPixmap texture;

    // animation divisors (inversely proportional to animation speed)
    static const int anim_div = 40;	// main animation

    //è la stringa che indica il livello a cui il blocco di fine livello dovrebbe portare
    std::string _livello_successivo;

    //indica se il blocco di fine livello è stato colpito e se quindi bisogna cambiare livello
    bool fine_livello_hit = false;

    public:
        fine_livello(QPoint position, std::string livello_successivo);

        // pure virtual methods that must be implemented
        virtual std::string name() { return "fine_livello"; }
        virtual void hit(Object *what, Direction fromDir);

        //Set e Get di fine_livello_hit
        void setFine_Livello_Hit(bool _Fine_Livello_Hit) {_Fine_Livello_Hit = fine_livello_hit;}
        bool getFine_Livello_Hit(){return fine_livello_hit;}

        //Set e Get di fine_livello_hit
        void setLivello_Successivo(std::string _Livello_Successivo) {_Livello_Successivo = _livello_successivo;}
        std::string getLivello_Successivo(){return _livello_successivo;}
};

#endif // FINE_LIVELLO_H
