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

#ifndef ETAT_H
#define ETAT_H

#include "couleur.h"
#include "sousplateau.h"

class Joueur;

class Etat // classe abstraite
{
public:
    enum Mouvement
    {
        Poser,
        Tourner,
		Egalite,
        Termine
    };

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

    virtual Couleur getCouleurCase(int plateauX, int plateauY, int sousPlateauX, int sousPlateauY) = 0;
    virtual Couleur getCouleurJoueur(Joueur * joueur) = 0;
    virtual Joueur * getJoueurCourant() = 0;
    virtual Joueur * getProchainJoueur() = 0;
    virtual Mouvement getProchainMouvement() = 0;
    virtual Joueur * getJoueurVictorieux() = 0;
    virtual Rotation getDerniereRotation() = 0;
	virtual Placement getDernierPlacement() = 0;
    virtual int getTaillePlateau() = 0;
    virtual int getTailleSousPlateau() = 0;
	virtual int getLongueurLigne() = 0;
	virtual int getNbPionsPoses() = 0;
};

#endif // ETAT_H
