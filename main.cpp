/********************************************************************
 Pentago

Copyright (C) 2009 Damien Mabin <damien.mabin@gmail.com>

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

#include <QtGui/QApplication>
#include "humain.h"
#include "iarandom.h"
#include "ihmqt.h"
#include "ihm.h"
#include "etat.h"
#include "selec.h"
#include "jeu.h"

#include <vector>

using std::vector;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vector<Joueur*> joueurs;
    int tailleplateau=2;
    int taillesousplateau=3;
    int ligne=5;
    int j1=1;
    int j2=1;
    Selec * s = new Selec(&tailleplateau,&taillesousplateau,&ligne,&j1,&j2);
    s->show();
    a.exec();
    s->updateInfo();
    if(j1==0)joueurs.push_back(new Humain("Humain 1"));
    else joueurs.push_back(new IARandom("IA random1"));
    if(j2==0)joueurs.push_back(new Humain("Humain 2"));
    else joueurs.push_back(new IARandom("IA random2"));
    Jeu* jeu=new Jeu(tailleplateau,taillesousplateau,ligne,joueurs);
    IhmQT* ihm = new IhmQT(jeu);
    ihm->show();
    jeu->attacheIHM((IHM*)ihm);
    jeu->jouer();
    a.exec();
    return 0;
}
