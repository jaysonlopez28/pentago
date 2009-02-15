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

#include "etatreel.h"

EtatReel::EtatReel(int taillePlateau, int tailleSousPlateaux, int longueurLigne) :
        _plateau(taillePlateau, tailleSousPlateaux), _longueurLigne(longueurLigne),
    _nbPions(0), _joueurVictorieux(NULL), _prochainMouvement(Poser)
{
    _derniereRotation.x = -1;
    _derniereRotation.y = -1;
	_dernierPlacement.plateauX = -1;
	_dernierPlacement.plateauY = -1;
	_dernierPlacement.sousPlateauX = -1;
	_dernierPlacement.sousPlateauY = -1;
	_dernierPlacement.couleur = Invalide;
    _derniereRotation.sens = SousPlateau::Horaire;
    _taillePlateau = _plateau.getTaille();
    _tailleSousPlateaux = _plateau.getTailleSousPlateaux();
        if(longueurLigne < 2)
                _longueurLigne = 2;
        if(longueurLigne > _taillePlateau * _tailleSousPlateaux)
                _longueurLigne = _taillePlateau * _tailleSousPlateaux - 1;
}

EtatReel::EtatReel(Etat & etat) : _plateau(2,3)
{
    _taillePlateau = etat.getTaillePlateau();
    _tailleSousPlateaux = etat.getTailleSousPlateau();
    _plateau = Plateau(_taillePlateau, _tailleSousPlateaux);
    for(int i = 0 ; i < _taillePlateau ; i++) {
        for(int j = 0 ; j < _taillePlateau ; j++) {
            for(int k = 0 ; k < _tailleSousPlateaux ; k++) {
                for(int l = 0 ; l < _tailleSousPlateaux ; l++) {
                    _plateau.setCouleur(i, j, k, l, etat.getCouleurCase(i, j, k, l));
                }
            }
        }
    }
    _nbPions = etat.getNbPionsPoses();
    _longueurLigne = etat.getLongueurLigne();
    _derniereRotation = etat.getDerniereRotation();
    _dernierPlacement = etat.getDernierPlacement();
    _prochainMouvement = etat.getProchainMouvement();
    list<Joueur *> joueurs = etat.getJoueurs();
    for(list<Joueur *>::iterator it = joueurs.begin() ; it != joueurs.end() ; it++){
        ajoutJoueur(*it, etat.getCouleurJoueur(*it));
    }
}

EtatReel::~EtatReel() {}

void EtatReel::setCouleur(int plateauX, int plateauY, int sousPlateauX, int sousPlateauY, Couleur couleur)
{
    Couleur couleurCase = _plateau.getCouleur(plateauX,plateauY,sousPlateauX,sousPlateauY);
    if(couleurCase == Vide && couleur != Vide)
            _nbPions++;
    else if(couleurCase != Blanc && couleur == Blanc)
            _nbPions--;
    _plateau.setCouleur(plateauX,plateauY,sousPlateauX,sousPlateauY,couleur);
    _dernierPlacement.plateauX = plateauX;
    _dernierPlacement.plateauY = plateauY;
    _dernierPlacement.sousPlateauX = sousPlateauX;
    _dernierPlacement.sousPlateauY = sousPlateauY;
    _dernierPlacement.couleur = couleur;
}

void EtatReel::tourner(int plateauX, int plateauY, SousPlateau::Sens sens)
{
    _plateau.tourner(plateauX,plateauY,sens);
    _derniereRotation.x = plateauX;
    _derniereRotation.y = plateauY;
    _derniereRotation.sens = sens;
}

Joueur * EtatReel::getJoueurCourant()
{
    return _joueurCourant;
}

void EtatReel::setJoueurCourant(Joueur * joueur)
{
    _joueurCourant = joueur;
}

Joueur * EtatReel::getProchainJoueur()
{
    for(list<Joueur*>::iterator it = _joueurs.begin() ; it != _joueurs.end() ; it++)
        if(*it == _joueurCourant) {
            it++;
            if(it == _joueurs.end())
                return *(_joueurs.begin());
            else
                return *it;
        }
    return NULL;
}

Couleur EtatReel::verifierVictoire()
{
    // recherche verticale
    for(int x = 0 ; x < _taillePlateau * _tailleSousPlateaux ; x++) {
        Couleur encours = _plateau.getCouleur(x/_tailleSousPlateaux,0,x%_tailleSousPlateaux,0);
        Couleur nouvelle;
        int compte = 0;
        if(encours != Vide)
            compte = 1;
        for(int x = 1 ; x < _taillePlateau * _tailleSousPlateaux ; x++) {
            nouvelle = _plateau.getCouleur(x/_tailleSousPlateaux,y/_tailleSousPlateaux,x%_tailleSousPlateaux,y%_tailleSousPlateaux);
            if(nouvelle == encours && nouvelle != Vide) {
                compte++;
                if(compte == _longueurLigne)
                    return encours;
            } else if(nouvelle != encours && nouvelle != Vide) {
                compte = 1;
                encours = nouvelle;
            } else { // nouvelle == Vide
                compte = 0;
                encours = nouvelle;
            }
        }
    }

    // recherche horizontale
    for(int y = 0 ; y < _taillePlateau * _tailleSousPlateaux ; y++) {
        Couleur encours = _plateau.getCouleur(0,y/_tailleSousPlateaux,0,y%_tailleSousPlateaux);
        Couleur nouvelle;
        int compte = 0;
        if(encours != Vide)
            compte = 1;
        for(int y = 1 ; y < _taillePlateau * _tailleSousPlateaux ; y++) {
            nouvelle = _plateau.getCouleur(x/_tailleSousPlateaux,y/_tailleSousPlateaux,x%_tailleSousPlateaux,y%_tailleSousPlateaux);
            if(nouvelle == encours && nouvelle != Vide) {
                compte++;
                if(compte == _longueurLigne)
                    return encours;
            } else if(nouvelle != encours && nouvelle != Vide) {
                compte = 1;
                encours = nouvelle;
            } else { // nouvelle == Vide
                compte = 0;
                encours = nouvelle;
            }
        }
    }

        // recherche diagonale haut gauche vers bas droite
        for(int x = 0 ; x < _taillePlateau * _tailleSousPlateaux ; x++) {
        Couleur encours = _plateau.getCouleur(x/_tailleSousPlateaux,0,x%_tailleSousPlateaux,0);
        Couleur nouvelle;
        int compte = 0;
        if(encours != Vide)
            compte = 1;
        for(int y = 1 ; y < _taillePlateau * _tailleSousPlateaux ; y++) {
            nouvelle = _plateau.getCouleur(x/_tailleSousPlateaux,y/_tailleSousPlateaux,x%_tailleSousPlateaux,y%_tailleSousPlateaux);
            if(nouvelle == encours && nouvelle != Vide) {
                compte++;
                if(compte == _longueurLigne)
                    return encours;
            } else if(nouvelle != encours && nouvelle != Vide) {
                compte = 1;
                encours = nouvelle;
            } else { // nouvelle == Vide
                compte = 0;
                encours = nouvelle;
            }
        }
    }

        for(int y = 0 ; y < _taillePlateau * _tailleSousPlateaux ; y++) {
        Couleur encours = _plateau.getCouleur(0,y/_tailleSousPlateaux,0,y%_tailleSousPlateaux);
        Couleur nouvelle;
        int compte = 0;
        if(encours != Vide)
            compte = 1;
        for(int x = 1 ; x + y < _taillePlateau * _tailleSousPlateaux ; x++) {
            nouvelle = _plateau.getCouleur(x/_tailleSousPlateaux,(y+x)/_tailleSousPlateaux,x%_tailleSousPlateaux,(y+x)%_tailleSousPlateaux);
            if(nouvelle == encours && nouvelle != Vide) {
                compte++;
                if(compte == _longueurLigne)
                    return encours;
            } else if(nouvelle != encours && nouvelle != Vide) {
                compte = 1;
                encours = nouvelle;
            } else { // nouvelle == Vide
                compte = 0;
                encours = nouvelle;
            }
        }
    }

        // recherche diagonale bas gauche vers haut droite
        for(int x = 0 ; x < _taillePlateau * _tailleSousPlateaux ; x++) {
        Couleur encours = _plateau.getCouleur(x/_tailleSousPlateaux,_taillePlateau-1,x%_tailleSousPlateaux,_tailleSousPlateaux-1);
        Couleur nouvelle;
        int compte = 0;
        if(encours != Vide)
            compte = 1;
        for(int y = _taillePlateau * _tailleSousPlateaux - 2 ; (x+((_taillePlateau * _tailleSousPlateaux - 1)-y)) < _taillePlateau * _tailleSousPlateaux ; y--) {
            nouvelle = _plateau.getCouleur((x+((_taillePlateau * _tailleSousPlateaux - 1)-y))/_tailleSousPlateaux,y/_tailleSousPlateaux,(x+((_taillePlateau * _tailleSousPlateaux - 1)-y))%_tailleSousPlateaux,y%_tailleSousPlateaux);
            if(nouvelle == encours && nouvelle != Vide) {
                compte++;
                if(compte == _longueurLigne)
                    return encours;
            } else if(nouvelle != encours && nouvelle != Vide) {
                compte = 1;
                encours = nouvelle;
            } else { // nouvelle == Vide
                compte = 0;
                encours = nouvelle;
            }
        }
    }
        for(int y = 0 ; y < _taillePlateau * _tailleSousPlateaux ; y++) {
        Couleur encours = _plateau.getCouleur(0,y/_tailleSousPlateaux,0,y%_tailleSousPlateaux);
        Couleur nouvelle;
        int compte = 0;
        if(encours != Vide)
            compte = 1;
        for(int x = _taillePlateau * _tailleSousPlateaux - 2 ; (y+((_taillePlateau * _tailleSousPlateaux - 1)-x)) < _taillePlateau * _tailleSousPlateaux ; x++) {
            nouvelle = _plateau.getCouleur(x/_tailleSousPlateaux,(y+((_taillePlateau * _tailleSousPlateaux - 1)-x))/_tailleSousPlateaux,x%_tailleSousPlateaux,(y+((_taillePlateau * _tailleSousPlateaux - 1)-x))%_tailleSousPlateaux);
            if(nouvelle == encours && nouvelle != Vide) {
                compte++;
                if(compte == _longueurLigne)
                    return encours;
            } else if(nouvelle != encours && nouvelle != Vide) {
                compte = 1;
                encours = nouvelle;
            } else { // nouvelle == Vide
                compte = 0;
                encours = nouvelle;
            }
        }
    }

}

Joueur * EtatReel::getJoueurVictorieux()
{
    if(_prochainMouvement == Termine)
        return _joueurVictorieux;
    Couleur couleur = verifierVictoire();
    if(couleur != Invalide) {
        _prochainMouvement = Termine;
        for(map<Joueur*,Couleur>::iterator it = _couleurs.begin() ; it != _couleurs.end() ; it++)
            if(it->second == couleur)
                _joueurVictorieux = it->first;
        return _joueurVictorieux;
    }
    return NULL;
}

Couleur EtatReel::getCouleurCase(int plateauX, int plateauY, int sousPlateauX, int sousPlateauY)
{
    return _plateau.getCouleur(plateauX,plateauY,sousPlateauX,sousPlateauY);
}

void EtatReel::ajoutJoueur(Joueur * joueur, Couleur couleur)
{
    _joueurs.push_back(joueur);
    _couleurs[joueur] = couleur;
    if(_joueurs.size() == 1) // premier joueur ajout
        _joueurCourant = joueur;
}

Couleur EtatReel::getCouleurJoueur(Joueur * joueur)
{
    map<Joueur*,Couleur>::iterator couleur = _couleurs.find(joueur);
    if(couleur != _couleurs.end())
        return couleur->second;
    else
        return Invalide;
}

void EtatReel::setProchainMouvement(Mouvement prochainMouvement)
{
    _prochainMouvement = prochainMouvement;
}

Etat::Mouvement EtatReel::getProchainMouvement()
{
    return _prochainMouvement;
}

Etat::Rotation EtatReel::getDerniereRotation()
{
    return _derniereRotation;
}

Etat::Placement EtatReel::getDernierPlacement()
{
	return _dernierPlacement;
}

int EtatReel::getTaillePlateau()
{
    return _taillePlateau;
}

int EtatReel::getTailleSousPlateau()
{
    return _tailleSousPlateaux;
}

int EtatReel::getLongueurLigne()
{
    return _longueurLigne;
}

int EtatReel::getNbPionsPoses()
{
    return _nbPions;
}

list<Joueur *> EtatReel::getJoueurs()
{
    return _joueurs;
}
