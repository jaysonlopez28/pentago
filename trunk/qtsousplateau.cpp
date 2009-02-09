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

#include "qtsousplateau.h"

QTSousPlateau::QTSousPlateau( QWidget * pere, Qt::WindowFlags f ,int _x, int _y, int _taille,int _tailleP,vector<PenCase*>* _cases ,vector<QTSousPlateau*>* _ssplat, Jeu* _jeu ): QFrame(pere,f), x(_x) , y(_y) ,taille(_taille),tailleP(_tailleP)
{
    cases=_cases;
    jeu=_jeu;
    ssplat = _ssplat;
}
void QTSousPlateau::setFleche(){
    for(int ssx = 0 ; ssx <tailleP ; ssx++){
        for(int ssy = 0 ; ssy<tailleP ; ssy++){
            for(int xx = 0 ; xx<taille ; xx+=taille-1){
                for(int yy = taille-1 ; yy>=0 ; yy-=taille-1){
                    if(ssx!=x || ssy!=y)(*cases)[yy+xx*taille+(ssy+ssx*tailleP)*taille*taille]->setBille();
                }
            }
        }
    }
    (*cases)[(taille-1)+(y+x*tailleP)*taille*taille]->setFleche();
    (*cases)[(taille-1)*taille+(y+x*tailleP)*taille*taille]->setFleche();
}
void QTSousPlateau::setNormal(){
    while(casest.size()>0){
    casest.top()->setBille();
    casest.pop();
    }
}

void QTSousPlateau::setTransparent(){
    for(int ssx = 0 ; ssx <tailleP ; ssx++){
        for(int ssy = 0 ; ssy<tailleP ; ssy++){
            if(ssx!=x || ssy!=y){
                (*ssplat)[ssx*tailleP+ssy]->setNormal();
            }
        }
    }
     for(int xx = 0 ; xx<taille ; xx++){
            for(int yy = 0 ; yy<taille ; yy++){
                (*cases)[yy+xx*taille+(y+x*tailleP)*taille*taille]->setTemp(jeu->getEtat()->getCouleurJoueur(jeu->getEtat()->getJoueurCourant()));
            }
        }
}
