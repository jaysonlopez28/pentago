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

#ifndef PENCASE_H
#define PENCASE_H
#include <QLabel>
#include <iostream>
#include <QMouseEvent>
#include "jeu.h"
#include "etat.h"
#include "couleur.h"
class QTSousPlateau;
class PenCase : public QLabel {
    private :
           bool pleine;
           Jeu* jeu;
           QTSousPlateau* sspla;
           Couleur coul;
    public :
           int x,y,ssx,ssy,taillessplateau,tailleplateau;
           PenCase( QWidget * parent = 0, Qt::WindowFlags f = 0 ,int x = -1, int y = -1, int _ssx = -1,int _ssy=-1,int _taillessplateau=3,int _tailleplateau= 2,QTSousPlateau* _sspla = NULL);
           PenCase ( const QString & text, QWidget * parent = 0, Qt::WindowFlags f = 0 ,int x = -1, int y = -1, int _ssx = -1,int _ssy=-1,int _taillessplateau=3,int _tailleplateau= 2,QTSousPlateau* _sspla = NULL);
           void setNoir();
           void setVide();
           void setBlanc();
           void setJeu(Jeu* j);
           void setFleche();
           void setBille();
           void setTemp(Couleur _coul);
           ~PenCase();
           void mousePressEvent ( QMouseEvent * event );
           void mouseMoveEvent  ( QMouseEvent * event );

};
#endif // PENCASE_H
