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

#ifndef QTSOUSPLATEAU_H
#define QTSOUSPLATEAU_H
#include <QFrame>
#include <vector>
#include <stack>
#include "jeu.h"
#include "pencase.h"
class QTSousPlateau : public QFrame
{
public:
    QTSousPlateau( QWidget * parent = 0, Qt::WindowFlags f = 0,int _x = 0, int _y = 0, int _taille=3,int _taillePlateau = 2, vector<PenCase*>* _cases = NULL,vector<QTSousPlateau*>* ssplat=NULL,Jeu* _jeu = NULL);
    int x,y,taille,tailleP;
    vector<PenCase*>* cases;
    std::stack<PenCase*> casest;
    vector<QTSousPlateau*>* ssplat;
    Jeu* jeu;
    void setFleche();
    void setNormal();
    void setTransparent();
};

#endif // QTSOUSPLATEAU_H
