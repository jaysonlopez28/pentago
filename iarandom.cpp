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

#include "iarandom.h"

#include "sousplateau.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

IARandom::IARandom(string nom) : Joueur(nom)
{
    srand(time(0));
}

IARandom::~IARandom() {}

bool IARandom::placePion()
{
	cout << "IARandom place un pion..." << endl;
    bool ok = false;
    do {
        int sousPlateauX = rand() % _jeu->getEtat()->getTaillePlateau();
        int sousPlateauY = rand() % _jeu->getEtat()->getTaillePlateau();
        int caseX = rand() % _jeu->getEtat()->getTailleSousPlateau();
        int caseY = rand() % _jeu->getEtat()->getTailleSousPlateau();
        ok = _jeu->joueCase(sousPlateauX,sousPlateauY,caseX,caseY);
    } while(!ok);
	return false;
}

bool IARandom::tournePlateau()
{
	cout << "IARandom tourne un plateau..." << endl;
    bool ok = false;
    do {
        int sousPlateauX = rand() % _jeu->getEtat()->getTaillePlateau();
        int sousPlateauY = rand() % _jeu->getEtat()->getTaillePlateau();
        int valSens = rand() % 2;
        SousPlateau::Sens sens = valSens ? SousPlateau::Horaire : SousPlateau::Antihoraire;
        ok = _jeu->tournePlateau(sousPlateauX,sousPlateauY,sens);
    } while(!ok);
	return false;
}
