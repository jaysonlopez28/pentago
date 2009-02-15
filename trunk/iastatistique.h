#ifndef IASTATISTIQUE_H
#define IASTATISTIQUE_H
#include <list>
#include <iostream>
#include "joueur.h"
#include "iarandom.h"
#include "jeu.h"

#define N 1
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
    Etat::Placement coup;
    Etat::Rotation rotation;
};

class IAStatistique : public Joueur
{
public:
    IAStatistique(string nom,int nbCoupAvance);
    bool placePion();
    bool tournePlateau();
private :
    int joueAlea(EtatReel etat,Couleur coul);
    Coup chercheMeilleureCoup(int nbCoupAvance=1,Couleur coulCourante=Noir);
    int chercheReccurent(int nbCoupAvance=1,Couleur coulCourante=Noir,EtatReel etat = NULL);

    int ss,p,lgligne;
    //nbCoupAvance stock le nombre de coup que l'ia doit calculer entierement
    int nbCoupAvance;
    Coup final;
    Couleur coul;
};

#endif // IASTATISTIQUE_H
