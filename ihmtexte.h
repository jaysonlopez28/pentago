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

#ifndef IHMTEXTE_H
#define IHMTEXTE_H

#include "ihm.h"

#include "jeu.h"

class IHMTexte : public IHM
{
public:
	IHMTexte(Jeu * jeu);
	
	void miseAJour();
	void jouer();
	
private:
	Jeu * _jeu;
};

#endif // IHMTEXTE_H
