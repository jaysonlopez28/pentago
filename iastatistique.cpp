#include "iastatistique.h"

IAStatistique::IAStatistique(int nbCoupAvance){
    coul=_jeu->getEtat()->getCouleurJoueur(this);
}
bool IAStatistique::placePion(){
    chercheMeilleureCoup(nbCoupAvance);

    return false;
}
bool IAStatistique::tournePlateau(){
    _jeu->tournePlateau(final.rotation.x,final.rotation.y,final.rotation.sens);
    return false;
}

Coup AIStatistique::chercheMeilleurCoup(int nbCoupAvance){
}
