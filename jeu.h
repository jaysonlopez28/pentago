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

#ifndef JEU_H
#define JEU_H

#include "couleur.h"
#include "sousplateau.h"
#include "etat.h"
#include "joueur.h"
#include "ihm.h"
#include "etatreel.h"
#include "etatprocuration.h"

#include <list>
#include <vector>

using std::list;
using std::vector;

class Jeu
{
public:
    Jeu(int taillePlateau, int tailleSousPlateaux, int longueurLigne, vector<Joueur*> joueurs);
    ~Jeu();

    void attacheIHM(IHM * ihm);
    void detacheIHM(IHM * ihm);
    void notifieIHM();
	
	void jouer();

    bool joueCase(int sousPlateauX, int sousPlateauY, int caseX, int caseY);
    bool tournePlateau(int sousPlateauX, int sousPlateauY, SousPlateau::Sens sens);
    bool joueCaseIHM(int sousPlateauX, int sousPlateauY, int caseX, int caseY);
    bool tournePlateauIHM(int sousPlateauX, int sousPlateauY, SousPlateau::Sens sens);

    Etat * getEtat();

private:
    EtatReel _etat;
    EtatProcuration _etatProcuration;
    list<IHM*> _listeIHM;
    bool _utiliseIHM;
};

#endif // JEU_H
