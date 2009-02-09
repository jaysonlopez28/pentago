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

#ifndef ETATPROCURATION_H
#define ETATPROCURATION_H

#include "couleur.h"
#include "joueur.h"
#include "etat.h"
#include "etatreel.h"

class EtatProcuration : public Etat
{
public:
    EtatProcuration(EtatReel * etat);

    Couleur getCouleurCase(int plateauX, int plateauY, int sousPlateauX, int sousPlateauY);
    Couleur getCouleurJoueur(Joueur * joueur);
    Joueur * getJoueurCourant();
    Joueur * getProchainJoueur();
    Joueur * getJoueurVictorieux();
    Mouvement getProchainMouvement();
    Rotation getDerniereRotation();
    Placement getDernierPlacement();
    int getTaillePlateau();
    int getTailleSousPlateau();
	int getLongueurLigne();
	int getNbPionsPoses();

private:
    EtatReel * _etat;
};

#endif // ETATPROCURATION_H
