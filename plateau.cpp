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

#include "plateau.h"

Plateau::Plateau(int taille, int tailleSousPlateaux) : _taille(taille),
    _plateau(taille, vector<SousPlateau>(taille))
{
    if(_taille < 1) {
        _taille = TAILLEDEFAUTPLATEAU;
        _plateau = vector<vector<SousPlateau> >(_taille, vector<SousPlateau>(_taille));
    }
    for(int i = 0 ; i < _taille ; i++)
        for(int j = 0 ; j < _taille ; j++)
            _plateau[i][j] = SousPlateau(tailleSousPlateaux);
    // Vivent les constructions/destructions inutiles.
    // Mais bon c'est ça la STL, les conteneurs sont plutôt fait pour
    // contenir des pointeurs et non des objets directement.
}

void Plateau::setCouleur(int plateauX, int plateauY, int sousPlateauX, int sousPlateauY, Couleur couleur)
{
    _plateau[plateauX][plateauY].setCouleur(sousPlateauX,sousPlateauY,couleur);
}

void Plateau::tourner(int plateauX, int plateauY, SousPlateau::Sens sens)
{
    _plateau[plateauX][plateauY].tourne(sens);
}

Couleur Plateau::getCouleur(int plateauX, int plateauY, int sousPlateauX, int sousPlateauY)
{
    if(plateauX >= 0 && plateauX < _taille && plateauY >= 0 && plateauY < _taille)
        return _plateau[plateauX][plateauY].getCouleur(sousPlateauX,sousPlateauY);
    return Invalide;
}

int Plateau::getTaille()
{
    return _taille;
}

int Plateau::getTailleSousPlateaux()
{
    return _plateau[0][0].getTaille();
}
