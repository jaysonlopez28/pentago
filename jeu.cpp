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

#include "jeu.h"

#include "humain.h"
#include "iarandom.h"

#include <iostream>

using std::cout;
using std::endl;

Jeu::Jeu(int taillePlateau, int tailleSousPlateaux, int longueurLigne, vector<Joueur*> joueurs) :
        _etat(taillePlateau, tailleSousPlateaux, longueurLigne),
        _etatProcuration(&_etat), _utiliseIHM(false)
{
    int c = 0;
    for(vector<Joueur*>::iterator it = joueurs.begin() ; it != joueurs.end() ; it++) {
        (*it)->setJeu(this);
        _etat.ajoutJoueur(*it, (c == 0 ? Premiere : Derniere));
        ++c%2;
    }
}

Jeu::~Jeu() {}

void Jeu::attacheIHM(IHM * ihm)
{
    _listeIHM.push_back(ihm);
}

void Jeu::detacheIHM(IHM * ihm)
{
    for(list<IHM*>::iterator it = _listeIHM.begin() ; it != _listeIHM.end() ; it++)
        if(*it = ihm) {
            _listeIHM.erase(it);
            return;
        }
}

void Jeu::notifieIHM()
{
    for(list<IHM*>::iterator it = _listeIHM.begin() ; it != _listeIHM.end() ; it++)
        (*it)->miseAJour();
}

void Jeu::jouer()
{
        _utiliseIHM = false;
        while(true) {
                Joueur * joueur = _etat.getJoueurCourant();
                if(_etat.getProchainMouvement() == Etat::Poser) {
                        cout << "Joueur " << joueur->getNom() << " place un pion..." << endl;
                        if(joueur->placePion()) {
                                _utiliseIHM = true;
                                return;
                        }
                } else if(_etat.getProchainMouvement() == Etat::Tourner) {
                        cout << "Joueur " << joueur->getNom() << " tourne un plateau..." << endl;
                        if(joueur->tournePlateau()) {
                                _utiliseIHM = true;
                                return;
                        }
                } else { // mouvement == Termine || mouvement == Egalite
                        cout << "Partie terminee !" << endl;
                        notifieIHM();
                        return;
                }
        }
}

bool Jeu::joueCase(int sousPlateauX, int sousPlateauY, int caseX, int caseY)
{
        cout << "joueCase" << endl;
    if(_etat.getProchainMouvement() == Etat::Poser) {
        if(_etat.getCouleurCase(sousPlateauX, sousPlateauY, caseX, caseY) == Vide) {
            _etat.setCouleur(sousPlateauX, sousPlateauY, caseX, caseY,
                             _etat.getCouleurJoueur(_etat.getJoueurCourant()));
            _etat.setProchainMouvement(Etat::Tourner);
            _utiliseIHM = false;
            _etat.getJoueurVictorieux(); // provoque la recherche de vainqueur
            notifieIHM();
            return true;
        }
    }
    return false;
}

bool Jeu::joueCaseIHM(int sousPlateauX, int sousPlateauY, int caseX, int caseY)
{
    if(_utiliseIHM) {
        return joueCase(sousPlateauX, sousPlateauY, caseX, caseY);
    }
    return false;
}

bool Jeu::tournePlateau(int sousPlateauX, int sousPlateauY, SousPlateau::Sens sens)
{
    if(_etat.getProchainMouvement() == Etat::Tourner) {
        Etat::Rotation derniereRotation = _etat.getDerniereRotation();
        if(!(derniereRotation.x == sousPlateauX && derniereRotation.y == sousPlateauY
           && derniereRotation.sens != sens)) {
            _etat.tourner(sousPlateauX,sousPlateauY,sens);
                        _etat.setProchainMouvement(Etat::Poser);
            _utiliseIHM = false;
            _etat.setJoueurCourant(_etat.getProchainJoueur());
            if(_etat.getJoueurVictorieux() == NULL && // provoque la recherche de vainqueur
                                _etat.getNbPionsPoses() == _etat.getTaillePlateau() * _etat.getTaillePlateau()
                                                                                        * _etat.getTailleSousPlateau() * _etat.getTailleSousPlateau())
                                _etat.setProchainMouvement(Etat::Egalite);
            notifieIHM();
            return true;
        }
                cout << "Impossible de faire la rotation inverse !" << endl;
    }
    return false;
}

bool Jeu::tournePlateauIHM(int sousPlateauX, int sousPlateauY, SousPlateau::Sens sens)
{
    if(_utiliseIHM) {
        return tournePlateau(sousPlateauX, sousPlateauY, sens);
    }
    return false;
}

Etat * Jeu::getEtat()
{
    return &_etatProcuration;
}
