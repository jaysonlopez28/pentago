#ifndef IASTATISTIQUE_H
#define IASTATISTIQUE_H

#include "joueur.h"
#include "jeu.h"
/*
struct Rotation
    {
        int x;
        int y;
        SousPlateau::Sens sens;
    };

        struct Placement
        {
                int plateauX;
                int plateauY;
                int sousPlateauX;
                int sousPlateauY;
                Couleur couleur;
        };
*/
struct Coup {
    Placement coup;
    Rotation rotation;
};

class IAStatistique : public Joueur
{
public:
    IAStatistique();
    bool placePion();
    bool tournePlateau();
private :
    //nbCoupAvance stock le nombre de coup que l'ia doit calculer entierement
    int nbCoupAvance;
    Coup final;
    Couleur coul;
};

#endif // IASTATISTIQUE_H
