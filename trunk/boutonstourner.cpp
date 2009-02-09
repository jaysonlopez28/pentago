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

#include "boutonstourner.h"

boutonsTourner::boutonsTourner(int _x, int _y,int _s):x(_x),y(_y),s(-s)
{
    QLabel();
    this->show();
}


boutonsTourner::boutonsTourner( QWidget * parent , Qt::WindowFlags f  ,int _x , int _y ,int _s):x(_x),y(_y),s(-s){
    QLabel(parent,f);
    this->show();
}

boutonsTourner::boutonsTourner ( const QString & text, QWidget * parent , Qt::WindowFlags f  ,int _x , int _y,int _s ):x(_x),y(_y),s(-s){
    QLabel(text,parent,f);
    this->show();
}

void boutonsTourner::setJeu(Jeu* j){
    jeu=j;
}
void boutonsTourner::mousePressEvent ( QMouseEvent * event ){
    if(this->s==0){jeu->tournePlateauIHM(this->x,this->y,SousPlateau::Antihoraire);jeu->jouer();}
    if(this->s==1){jeu->tournePlateauIHM(this->x,this->y,SousPlateau::Horaire);jeu->jouer();}
}

