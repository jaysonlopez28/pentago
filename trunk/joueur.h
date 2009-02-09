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

#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

using std::string;

class Jeu;

class Joueur // Classe abstraite
{
public:
    Joueur(string nom) : _nom(nom) {}
    virtual ~Joueur() {}
	
	string getNom() { return _nom; }

    virtual bool placePion() = 0;
    virtual bool tournePlateau() = 0;

    void setJeu(Jeu * jeu) { _jeu = jeu; }

protected:
    Jeu * _jeu;
    string _nom;
};

#endif // JOUEUR_H
