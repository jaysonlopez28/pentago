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
#include "pencase.h"



PenCase::PenCase( QWidget * parent , Qt::WindowFlags f ,int _x,int _y, int _ssx ,int _ssy,int _taillessplateau,int _tailleplateau,QTSousPlateau * _sspla)
    :x(_x),y(_y),ssx(_ssx),ssy(_ssy),taillessplateau(_taillessplateau),tailleplateau(_tailleplateau){
    QLabel(parent,f);
    ((QLabel*)(this))->setPixmap(QPixmap(":/image/trou"));
    this->show();
    pleine=false;
    sspla=_sspla;
    coul = Vide;
}
PenCase::~PenCase(){
}
void PenCase::setJeu(Jeu* j){
    jeu=j;
}
void PenCase::mousePressEvent ( QMouseEvent * event ){
    Etat* EC = jeu->getEtat();
    if(EC->getProchainMouvement()==Etat::Poser){
        std::cout<<"Mouse Presse !!!!sspx = "<<this->ssx<<"  sspy = "<<this->ssy<<std::endl;
        jeu->joueCaseIHM(this->ssx,this->ssy,this->x,this->y);jeu->jouer();
    }else if(EC->getProchainMouvement()==Etat::Tourner){
        if(x==taillessplateau-1 && y==0){
            jeu->tournePlateauIHM(ssx,ssy,SousPlateau::Antihoraire);jeu->jouer();
        }else if(x==0 && y == taillessplateau-1){
            jeu->tournePlateauIHM(ssx,ssy,SousPlateau::Horaire);jeu->jouer();
        }
    }
}
PenCase::PenCase ( const QString & text, QWidget * parent , Qt::WindowFlags f ,int _x,int _y, int _ssx ,int _ssy,int _taillessplateau,int _tailleplateau,QTSousPlateau * _sspla)
    :x(_x),y(_y),ssx(_ssx),ssy(_ssy),taillessplateau(_taillessplateau),tailleplateau(_tailleplateau){
    QLabel(text,parent,f);
    (this)->setPixmap(QPixmap(":/image/trou"));
    this->show();
    pleine=false;
    sspla=_sspla;
    coul = Vide;
}
void PenCase::setNoir(){
    coul=Noir;
    (this)->setPixmap(QPixmap(":/image/boutonN"));
    pleine=true;
    this->repaint();
}

void PenCase::setTemp(Couleur _coul){
    if(pleine == false && underMouse()){
        if(_coul == Blanc){
            (this)->setPixmap(QPixmap(":/image/BoutonSB"));
        }else if(_coul == Noir){
            (this)->setPixmap(QPixmap(":/image/BoutonSM"));
        }
        sspla->casest.push(this);
    }else {setBille();}
    repaint();
}
void PenCase::setVide(){
    coul = Vide;
    (this)->setPixmap(QPixmap(":/image/trou"));
    pleine=false;
    this->repaint();
}
void PenCase::setBlanc(){
    coul = Blanc;
    (this)->setPixmap(QPixmap(":/image/boutonB"));
    pleine=true;
    this->repaint();
}


void PenCase::setFleche(){
    SousPlateau::Sens  sens;
    if(y<((float)taillessplateau/2.0)-1 || (y<((float)taillessplateau/2.0)&&x<((float)taillessplateau/2.0)-1)){
        sens = SousPlateau::Antihoraire;
    }else if(y>((float)taillessplateau/2.0)|| (y>((float)taillessplateau/2.0-1)&&x>((float)taillessplateau/2.0))){
        sens = SousPlateau::Horaire;
    }else sens = SousPlateau::Indetermine;


    if((jeu->getEtat()->getDerniereRotation().x==ssx && jeu->getEtat()->getDerniereRotation().y==ssy)&& sens != jeu->getEtat()->getDerniereRotation().sens)return;
    else{
        if(coul==Noir){
            if(sens == SousPlateau::Antihoraire){
                (this)->setPixmap(QPixmap(":/image/FNAH"));
            }else if(sens == SousPlateau::Horaire){
                (this)->setPixmap(QPixmap(":/image/FNH"));
            }
        }else if(coul == Blanc){
            if(sens == SousPlateau::Antihoraire){
                (this)->setPixmap(QPixmap(":/image/FBAH"));
            }else if(sens == SousPlateau::Horaire){
                (this)->setPixmap(QPixmap(":/image/FBH"));
            }
        }else if(coul == Vide){
            if(sens == SousPlateau::Antihoraire){
                (this)->setPixmap(QPixmap(":/image/FVAH"));
            }else if(sens == SousPlateau::Horaire){
                (this)->setPixmap(QPixmap(":/image/FVH"));
            }
    }
    repaint();
}
}
void PenCase::setBille(){
    if(coul==Noir){
        (this)->setPixmap(QPixmap(":/image/boutonN"));
    }else if(coul == Blanc){
        (this)->setPixmap(QPixmap(":/image/boutonB"));
    }else if(coul == Vide){
        (this)->setPixmap(QPixmap(":/image/trou"));
    }
    repaint();
}


void PenCase::mouseMoveEvent  ( QMouseEvent * event ){
    Etat* EC = jeu->getEtat();
    if(pleine == false && (*EC).getProchainMouvement() != Etat::Termine && (*EC).getProchainMouvement() != Etat::Egalite && EC->getProchainMouvement() == Etat::Poser){
        sspla->setTransparent();
    }else if((*EC).getProchainMouvement() != Etat::Termine && (*EC).getProchainMouvement() != Etat::Egalite && EC->getProchainMouvement() == Etat::Tourner){
        sspla->setFleche();
    }
}

