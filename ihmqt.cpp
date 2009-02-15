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

#include "ihmqt.h"
#include "ui_ihmqt.h"

IhmQT::IhmQT(Jeu* jeu,QWidget *parent)
    : QMainWindow(parent), ui(new Ui::IhmQTClass)
{
        _jeu=jeu;
    ui->setupUi(this);
    tssp = _jeu->getEtat()->getTailleSousPlateau();
    tp = _jeu->getEtat()->getTaillePlateau();
    cases.resize(tssp*tssp*tp*tp);
    lFrameSsP.resize(tp*tp);
    listSsPlat.resize(tp*tp);
    
    for(int ssx = 0 ; ssx <tp ; ssx++){
        for(int ssy = 0 ; ssy<tp ; ssy++){
            
            lFrameSsP[ssy+ssx*tp] = new QTSousPlateau(ui->gridFrame_5,0,ssx,ssy,tssp,tp,&cases,&lFrameSsP,_jeu);
            lFrameSsP[ssy+ssx*tp]->setObjectName(QString::fromUtf8("gridFrame_2"));
            lFrameSsP[ssy+ssx*tp]->setStyleSheet(QString::fromUtf8("border-image: url(:/image/plateau);\n"));
            listSsPlat[ssy+ssx*tp] = new QGridLayout(lFrameSsP[ssy+ssx*tp]);
            listSsPlat[ssy+ssx*tp]->setSpacing(0);
            listSsPlat[ssy+ssx*tp]->setMargin(4);
            lFrameSsP[ssy+ssx*tp]->setMouseTracking(true);
            listSsPlat[ssy+ssx*tp]->setObjectName(QString::fromUtf8("gridLayout"));
            ui->gridLayout_5->addWidget(lFrameSsP[ssy+ssx*tp], ssx, ssy, 1, 1);
            for(int x = 0 ; x<tssp ; x++){
                for(int y = 0 ; y<tssp ; y++){
                    cases[y+x*tssp+(ssy+ssx*tp)*tssp*tssp]=new PenCase( lFrameSsP[ssy+ssx*tp],0,x,y,ssx,ssy,tssp,tp,lFrameSsP[ssy+ssx*tp]);
                    cases[y+x*tssp+(ssy+ssx*tp)*tssp*tssp]->setObjectName(QString::fromUtf8("label_10"));
                    cases[y+x*tssp+(ssy+ssx*tp)*tssp*tssp]->setCursor(QCursor(Qt::CrossCursor));
                    cases[y+x*tssp+(ssy+ssx*tp)*tssp*tssp]->setMouseTracking(true);
                    cases[y+x*tssp+(ssy+ssx*tp)*tssp*tssp]->setAutoFillBackground(false);
                    cases[y+x*tssp+(ssy+ssx*tp)*tssp*tssp]->setStyleSheet(QString::fromUtf8("border-image: url(:/image/vide);\n"));
                    cases[y+x*tssp+(ssy+ssx*tp)*tssp*tssp]->setFrameShape(QFrame::NoFrame);
                    cases[y+x*tssp+(ssy+ssx*tp)*tssp*tssp]->setFrameShadow(QFrame::Plain);
                    cases[y+x*tssp+(ssy+ssx*tp)*tssp*tssp]->setScaledContents(true);
                    cases[y+x*tssp+(ssy+ssx*tp)*tssp*tssp]->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);
                    cases[y+x*tssp+(ssy+ssx*tp)*tssp*tssp]->setJeu(_jeu);
                    listSsPlat[ssy+ssx*tp]->addWidget(cases[y+x*tssp+(ssy+ssx*tp)*tssp*tssp], x, y, 1, 1);
                }
            }
        }
    }

}

IhmQT::~IhmQT()
{
    delete _jeu;
    delete ui;
}
void IhmQT::miseAJour(){
    Etat* EC=_jeu->getEtat();
    if(EC->getProchainMouvement()!=Etat::Termine && EC->getProchainMouvement()!=Etat::Egalite){
        if(EC->getProchainMouvement()==Etat::Tourner){
    ui->label->setText(QApplication::translate("IhmQTClass", ("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Berlin Sans FB Demi'; font-size:11pt; font-weight:72; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+(EC->getJoueurCourant()->getNom())+" Tourner </p></body></html>").c_str(), 0, QApplication::UnicodeUTF8));
    }    else{
        ui->label->setText(QApplication::translate("IhmQTClass", ("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Berlin Sans FB Demi'; font-size:11pt; font-weight:72; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"+(EC->getJoueurCourant()->getNom())+" Poser </p></body></html>").c_str(), 0, QApplication::UnicodeUTF8));

    }
    }else if(EC->getProchainMouvement()==Etat::Termine) {
ui->label->setText(QApplication::translate("IhmQTClass", ("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Berlin Sans FB Demi'; font-size:11pt; font-weight:72; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Victoire ! "+(EC->getJoueurVictorieux()->getNom())+"</p></body></html>").c_str(), 0, QApplication::UnicodeUTF8));
    }else if(EC->getProchainMouvement()==Etat::Egalite) {
    ui->label->setText(QApplication::translate("IhmQTClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Berlin Sans FB Demi'; font-size:11pt; font-weight:72; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Egalité!</p></body></html>", 0, QApplication::UnicodeUTF8));
    }

    if(EC->getProchainMouvement()==Etat::Poser){
    int _ssx = EC->getDerniereRotation().x;
    int _ssy = EC->getDerniereRotation().y;
    for(int i=0;i<tssp;i++){
        for(int j=0;j<tssp;j++){
            if(EC->getCouleurCase( _ssx, _ssy , cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->x, cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->y)==Noir)cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->setNoir();
            if(EC->getCouleurCase( _ssx, _ssy , cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->x, cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->y)==Blanc)cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->setBlanc();
            if(EC->getCouleurCase( _ssx, _ssy , cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->x, cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->y)==Vide)cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->setVide();
        }
    }
    }else if(EC->getProchainMouvement()==Etat::Tourner) {
        int _ssx = EC->getDernierPlacement().plateauX;
        int _ssy = EC->getDernierPlacement().plateauY;
        for(int i=0;i<tssp;i++){
            for(int j=0;j<tssp;j++){
                if(EC->getCouleurCase( _ssx, _ssy , cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->x, cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->y)==Noir)cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->setNoir();
                if(EC->getCouleurCase( _ssx, _ssy , cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->x, cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->y)==Blanc)cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->setBlanc();
                if(EC->getCouleurCase( _ssx, _ssy , cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->x, cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->y)==Vide)cases[j+i*tssp+(_ssy+_ssx*tp)*tssp*tssp]->setVide();
            }
        }
    }else {
        for(unsigned int i=0; i < cases.size(); i++){
            if(EC->getCouleurCase( cases[i]->ssx, cases[i]->ssy , cases[i]->x, cases[i]->y)==Noir)cases[i]->setNoir();
            if(EC->getCouleurCase( cases[i]->ssx, cases[i]->ssy , cases[i]->x, cases[i]->y)==Blanc)cases[i]->setBlanc();
            if(EC->getCouleurCase( cases[i]->ssx, cases[i]->ssy , cases[i]->x, cases[i]->y)==Vide)cases[i]->setVide();
        }
    }
}

