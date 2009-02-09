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

#ifndef IHMQT_H
#define IHMQT_H
#include <list>
#include <vector>
#include <iostream>
#include <QtGui/QMainWindow>
#include "joueur.h"
#include "pencase.h"
#include "humain.h"
#include "iarandom.h"
#include "qtsousplateau.h"
#include <QGridLayout>
#include "ihm.h"
#include "etat.h"
#include "jeu.h"
using std::list;
using std::vector;
namespace Ui
{
    class IhmQTClass;
}

class IhmQT : public QMainWindow, public IHM
{
    Q_OBJECT

public:
    IhmQT(Jeu* jeu,QWidget *parent = 0 );
    ~IhmQT();
     void miseAJour();

private:
    int tp,tssp;
    Ui::IhmQTClass *ui;
    vector<PenCase*> cases;
    vector<QTSousPlateau*> lFrameSsP;
    vector<QGridLayout*> listSsPlat;
    Jeu* _jeu;
};

#endif // IHMQT_H
