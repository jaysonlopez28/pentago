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

#ifndef SOUSPLATEAU_H
#define SOUSPLATEAU_H

#include "couleur.h"
#include "case.h"

#include <vector>

#define TAILLEDEFAUTSOUSPLATEAU 3

using std::vector;

class SousPlateau
{
public:
    enum Orientation
    {
        Haut,
        Droite,
        Bas,
        Gauche
    };

    enum Sens
    {
        Horaire = 0,
        Antihoraire = 1,
        Indetermine = 2
    };

    SousPlateau(); // pour pouvoir instancier le vector
    SousPlateau(int taille);

    void tourne(Sens sens);
    void setCouleur(int x, int y, Couleur couleur);

    Couleur getCouleur(int x, int y);
    int getTaille();

private:
    Orientation _orientation;
    int _taille;
    vector<vector<Case> > _cases;

    int miroir(int x);
};

#endif // SOUSPLATEAU_H
