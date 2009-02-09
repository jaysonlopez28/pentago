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

#include "etatprocuration.h"

EtatProcuration::EtatProcuration(EtatReel * etat) : _etat(etat) {}

Couleur EtatProcuration::getCouleurCase(int plateauX, int plateauY, int sousPlateauX, int sousPlateauY)
{
    return _etat->getCouleurCase(plateauX, plateauY, sousPlateauX, sousPlateauY);
}

Couleur EtatProcuration::getCouleurJoueur(Joueur * joueur)
{
    return _etat->getCouleurJoueur(joueur);
}

Joueur * EtatProcuration::getJoueurCourant()
{
    return _etat->getJoueurCourant();
}

Joueur * EtatProcuration::getProchainJoueur()
{
    return _etat->getProchainJoueur();
}

Joueur * EtatProcuration::getJoueurVictorieux()
{
    return _etat->getJoueurVictorieux();
}

Etat::Mouvement EtatProcuration::getProchainMouvement()
{
    return _etat->getProchainMouvement();
}

Etat::Rotation EtatProcuration::getDerniereRotation()
{
    return _etat->getDerniereRotation();
}

Etat::Placement EtatProcuration::getDernierPlacement()
{
	return _etat->getDernierPlacement();
}

int EtatProcuration::getTaillePlateau()
{
    return _etat->getTaillePlateau();
}

int EtatProcuration::getTailleSousPlateau()
{
    return _etat->getTailleSousPlateau();
}

int EtatProcuration::getLongueurLigne()
{
	return _etat->getLongueurLigne();
}

int EtatProcuration::getNbPionsPoses()
{
	return _etat->getNbPionsPoses();
}
