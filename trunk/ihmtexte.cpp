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

#include "ihmtexte.h"

#include "couleur.h"
#include "sousplateau.h"
#include "etat.h"

#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

IHMTexte::IHMTexte(Jeu * jeu) : _jeu(jeu)
{
	cout << "IHMTexte cree" << endl;
}

void IHMTexte::miseAJour()
{
	//cout << "IHMTexte mise à jour" << endl;
	Etat * etat = _jeu->getEtat();
	for(int px = 0 ; px < etat->getTaillePlateau() ; px++) {
		for(int py = 0 ; py < etat->getTaillePlateau() ; py++) {
			for(int spx = 0 ; spx < etat->getTailleSousPlateau() ; spx++) {
				for(int spy = 0 ; spy < etat->getTailleSousPlateau() ; spy++) {
					Couleur couleur = etat->getCouleurCase(px,py,spx,spy);
					if(couleur == Vide)
						cout << " ";
					else if(couleur == Blanc)
						cout << "0";
					else if(couleur == Noir)
						cout << "X";
					else
						cout << "?";
				}
				cout << endl;
			}
		}
		cout << endl;
	}
	cout << endl;
}

void IHMTexte::jouer()
{
	if(_jeu->getEtat()->getProchainMouvement() == Etat::Poser) {
		cout << "Placer un pion" << endl;
		int px, py, spx, spy;
		cin >> px;
		cin >> py;
		cin >> spx;
		cin >> spy;
		_jeu->joueCaseIHM(px,py,spx,spy);
	} else if(_jeu->getEtat()->getProchainMouvement() == Etat::Tourner) {
		cout << "Tourner un plateau" << endl;
		int px, py, s;
		cin >> px;
		cin >> py;
		cin >> s;
		SousPlateau::Sens sens;
		if(s == 0)
			sens = SousPlateau::Horaire;
		else
			sens = SousPlateau::Antihoraire;
		_jeu->tournePlateauIHM(px,py,sens);
	}
}
