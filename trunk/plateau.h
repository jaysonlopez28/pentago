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

#ifndef PLATEAU_H
#define PLATEAU_H

#include "couleur.h"
#include "sousplateau.h"

#include <vector>

#define TAILLEDEFAUTPLATEAU 2

using std::vector;

class Plateau
{
public:
    Plateau(int taille, int tailleSousPlateaux);

    void setCouleur(int plateauX, int plateauY, int sousPlateauX, int sousPlateauY, Couleur couleur);
    void tourner(int plateauX, int plateauY, SousPlateau::Sens sens);

    Couleur getCouleur(int plateauX, int plateauY, int sousPlateauX, int sousPlateauY);
    int getTaille();
    int getTailleSousPlateaux();

private:
    int _taille;
    vector<vector<SousPlateau> > _plateau;
};

#endif // PLATEAU_H
