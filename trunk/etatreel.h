/********************************************************************
 Pentago

Copyright (C) 2009 Thomas Petillon <tpetillon@gmail.com>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of
the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
********************************************************************/

#ifndef ETATREEL_H
#define ETATREEL_H

#include "couleur.h"
#include "sousplateau.h"
#include "plateau.h"
#include "joueur.h"
#include "etat.h"

#include <list>
#include <map>

using std::list;
using std::map;

class EtatReel : public Etat
{
public:
    EtatReel(int taillePlateau, int tailleSousPlateaux, int longueurLigne);
    EtatReel(Etat & etat);
    virtual ~EtatReel();

    void setCouleur(int plateauX, int plateauY, int sousPlateauX, int sousPlateauY, Couleur couleur);
    void tourner(int plateauX, int plateauY, SousPlateau::Sens sens);

    Couleur getCouleurCase(int plateauX, int plateauY, int sousPlateauX, int sousPlateauY);

    void ajoutJoueur(Joueur * joueur, Couleur couleur);
    Couleur getCouleurJoueur(Joueur * joueur);

    void setJoueurCourant(Joueur * joueur);
    Joueur * getJoueurCourant();
    Joueur * getProchainJoueur();
    Joueur * getJoueurVictorieux();

    void setProchainMouvement(Mouvement prochainMouvement);
    Mouvement getProchainMouvement();

    Rotation getDerniereRotation();
    Placement getDernierPlacement();

    int getTaillePlateau();
    int getTailleSousPlateau();
    int getLongueurLigne();
    int getNbPionsPoses();

    friend class EtatProcuration;
    void removePlayers();
    list<Joueur *> getJoueurs();

private:
    Plateau _plateau;
    int _taillePlateau, _tailleSousPlateaux;
    int _longueurLigne;
    list<Joueur*> _joueurs;
    map<Joueur*,Couleur> _couleurs;
    Joueur * _joueurCourant;
    int _nbPions;
    Joueur * _joueurVictorieux;
    Mouvement _prochainMouvement;
    Rotation _derniereRotation;
    Placement _dernierPlacement;

    Couleur verifierVictoire();
};

#endif // ETATREEL_H
