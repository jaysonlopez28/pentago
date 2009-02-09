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

#include "sousplateau.h"

SousPlateau::SousPlateau() : _orientation(Haut), _taille(TAILLEDEFAUTSOUSPLATEAU),
    _cases(TAILLEDEFAUTSOUSPLATEAU, vector<Case>(TAILLEDEFAUTSOUSPLATEAU)) {}

SousPlateau::SousPlateau(int taille) : _orientation(Haut), _taille(taille),
    _cases(taille, vector<Case>(taille))
{
    if(_taille < 1) {
        _taille = TAILLEDEFAUTSOUSPLATEAU;
        _cases = vector<vector<Case> >(_taille, vector<Case>(_taille));
    }
    /*
    for(int i = 0 ; i < _taille ; i++)
        for(int j = 0 ; j < _taille ; j++)
            _cases[i][j] = Case(Vide);
            */
}

void SousPlateau::tourne(Sens sens)
{
    if(sens == Horaire) {
        switch(_orientation) {
            case Haut:
                _orientation = Droite;
                break;
            case Droite:
                _orientation = Bas;
                break;
            case Bas:
                _orientation = Gauche;
                break;
            case Gauche:
                _orientation = Haut;
        }
    } else {
        switch(_orientation) {
            case Haut:
                _orientation = Gauche;
                break;
            case Droite:
                _orientation = Haut;
                break;
            case Bas:
                _orientation = Droite;
                break;
            case Gauche:
                _orientation = Bas;
        }
    }
}

void SousPlateau::setCouleur(int x, int y, Couleur couleur)
{
    if(x >= 0 && x < _taille && y >= 0 && y < _taille) {
        switch(_orientation) {
            case Haut:
                _cases[x][y].setCouleur(couleur);
                break;
            case Droite:
                _cases[miroir(y)][x].setCouleur(couleur);
                break;
            case Bas:
                _cases[miroir(x)][miroir(y)].setCouleur(couleur);
                break;
            case Gauche:
                _cases[y][miroir(x)].setCouleur(couleur);
        }
    }
}

Couleur SousPlateau::getCouleur(int x, int y)
{
    if(x >= 0 && x < _taille && y >= 0 && y < _taille) {
        switch(_orientation) {
            case Haut:
                return _cases[x][y].getCouleur();
                break;
            case Droite:
                return _cases[miroir(y)][x].getCouleur();
                break;
            case Bas:
                return _cases[miroir(x)][miroir(y)].getCouleur();
                break;
            case Gauche:
                return _cases[y][miroir(x)].getCouleur();
        }
    }
    return Invalide;
}

int SousPlateau::getTaille()
{
    return _taille;
}

int SousPlateau::miroir(int x)
{
    static double axe = ((double)_taille - 1) / 2;
    return (int)(axe + (axe - x));
}
