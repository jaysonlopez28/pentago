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

#ifndef BOUTONSTOURNER_H
#define BOUTONSTOURNER_H
#include <QLabel>
#include "sousplateau.h"
#include "jeu.h"

class boutonsTourner : public QLabel
{
public:
    boutonsTourner(int x = -1, int y = -1,int _s=-1);
    boutonsTourner( QWidget * parent = 0, Qt::WindowFlags f = 0 ,int x = -1, int y = -1,int _s=-1);
    boutonsTourner ( const QString & text, QWidget * parent = 0, Qt::WindowFlags f = 0 ,int x = -1, int y = -1,int _s=-1);
    void setJeu(Jeu* j);
    void mousePressEvent ( QMouseEvent * event );
    int x,y,s;
private :
    Jeu* jeu;

};

#endif // BOUTONSTOURNER_H
