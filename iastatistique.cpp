#include "iastatistique.h"

IAStatistique::IAStatistique(string nom,int _nbCoupAvance) : Joueur(nom){
    std::cout<<"lapin"<<std::endl;
    nbCoupAvance = _nbCoupAvance;
    ss=3;
    p=2;
    lgligne = 5;
}
bool IAStatistique::placePion(){
    coul=_jeu->getEtat()->getCouleurJoueur(((Joueur*)this));
    //recuperation du plateau du jeu en cour dans plat :
    /*Plateau plat = Plateau(p,ss);
    for(int x = 0 ; x < p ; x++ ){
        for(int y = 0 ; y < p ; y++ ){
            for(int ssx = 0 ; ssx < ss ; ssx++ ){
                for(int ssy = 0 ; ssy < ss ; ssy++ ){
                    plat.setCouleur(x,y,ssx,ssy,_jeu->getEtat()->getCouleurCase(x,y,ssx,ssy));
                }
            }
        }
    }*/
    //Appel de la fonction pour chercher le coup :
    final = chercheMeilleureCoup(nbCoupAvance,coul);
    //On joue le coup
    _jeu->joueCase(final.coup.plateauX,final.coup.plateauY,final.coup.sousPlateauX,final.coup.sousPlateauY);
    return false;
}
bool IAStatistique::tournePlateau(){
    _jeu->tournePlateau(final.rotation.x,final.rotation.y,final.rotation.sens);
    return false;
}

Coup IAStatistique::chercheMeilleureCoup(int nbCoupAvance,Couleur coulCourante){
    EtatReel etat = EtatReel(*(_jeu->getEtat()));
    // 1 : on push tt les coups valident dans une liste
    list<Coup> coupsPossibles;
    Etat::Rotation last = _jeu->getEtat()->getDerniereRotation();
    for(int x = 0 ; x < p ; x++ ){
        for(int y = 0 ; y < p ; y++ ){
            for(int ssx = 0 ; ssx < ss ; ssx++ ){
                for(int ssy = 0 ; ssy < ss ; ssy++ ){
                    if(_jeu->getEtat()->getCouleurCase(x,y,ssx,ssy)==Vide){
                        //Coup valide (la case est libre on peut la prendre en compte comme case à jouer possible
                        for(int tx = 0 ; tx < p ; tx++ ){
                            for(int ty = 0 ; ty < p ; ty++ ){
                                for(int sens = 0 ; sens < 2 ; sens++){
                                    if(last.x != tx && last.y != ty && last.sens != (SousPlateau::Sens)sens){
                                        Coup temp;
                                        temp.coup.plateauX = x;
                                        temp.coup.plateauY = y;
                                        temp.coup.sousPlateauX = ssx;
                                        temp.coup.sousPlateauY = ssy;
                                        temp.coup.couleur = coulCourante;
                                        temp.rotation.sens = (SousPlateau::Sens)sens;
                                        temp.rotation.x = tx;
                                        temp.rotation.y = ty;
                                        coupsPossibles.push_back(temp);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    list<std::pair<Coup,int> > valeur;
    // 2 : on appel chercheRecurrent sur chaques plateaux mit a jour avec un coup de la liste à chaque fois
    for(int j = 0 ; j < coupsPossibles.size() ; j++){
    //for(int j = 0 ; j < 2 ; j++){
        Coup cc = coupsPossibles.front();
        coupsPossibles.pop_front();
        etat.setCouleur(cc.coup.plateauX,cc.coup.plateauY,cc.coup.sousPlateauX,cc.coup.sousPlateauY,cc.coup.couleur);
        valeur.push_back(std::pair<Coup,int>(cc,chercheReccurent(nbCoupAvance,(Couleur)((coulCourante%2)+1),etat)));
        etat.setCouleur(cc.coup.plateauX,cc.coup.plateauY,cc.coup.sousPlateauX,cc.coup.sousPlateauY,Vide);
    }
    int max = -9000;
    // 3 : on parcours valeur pour savoir quel coup a le meilleur score, et on le retourne.
    //for(list<std::pair<Coup,int>>::iterator it = valeur.begin() ; it != valeur.end() ; it++)
    for(list<std::pair<Coup,int> >::iterator it = valeur.begin() ; it != valeur.end() ; it++ ){
        if(it->second>max)final = it->first;
    }
    return final;

}

int IAStatistique::chercheReccurent(int nbCoupAvance,Couleur coulCourante,EtatReel etat){
     int res = 0;
     /*
     *1 : Il y a 2 cas possible, soit nbCoupAvance == 0 , soit nbCoupAvance > 0
     *si == 0 : On tire avec le plateau courant N partis, N est definis par le #define du main "N"
     *si >0 : on place tout les coup possible dans la liste "coupsPossibles" puis on en pop 1,
     *on met le plateau a jour, puis on appel recursivment la fonction
    */
    if(nbCoupAvance==0){
        for(int i = 0 ; i < N ; i++){
            res +=joueAlea(etat,coul);
        }
    }
    return (int)(((float)res)/((float)N));
}

int IAStatistique::joueAlea(EtatReel etat,Couleur coulCourante){
    /*ToDo :
     *Crée une instance de jeu avec l'etat : etat
     *jouer la partie jusqu'a la fin
     *Renvoyer :
        *egalité : 0
        *victoire de coulCourante : valeur positive
        *victoire de !coulCourante : valeur negative
      */

     etat.removePlayers();
     IARandom* j1 = new IARandom("IA random1");
     IARandom* j2 = new IARandom("IA random2");
     etat.ajoutJoueur(j1, coulCourante);
     etat.ajoutJoueur(j2, (Couleur)((coulCourante%2)+1));
     etat.setJoueurCourant(j1);
     std::cout<<"IAStatistique : debut partie"<<std::endl;
     //On joue la partie :
     Jeu alea = Jeu(etat);
     j1->setJeu(&alea);
     j2->setJeu(&alea);
     alea.jouer();
     std::cout<<"IAStatistique : fin partie"<<std::endl;
     //A la fin de la partie :
     if(etat.getProchainMouvement() == Etat::Egalite)return 0;
     if(etat.getProchainMouvement() == Etat::Termine){
        if(etat.getCouleurJoueur(etat.getJoueurVictorieux())==coulCourante){
            return 100;
        }
        else if(etat.getCouleurJoueur(etat.getJoueurVictorieux())!=coulCourante){
            return -100;
        }
        else return 0;
     }


     delete j1;
     delete j2;
     std::cout<<"Fin Alea"<<std::endl;
    return 0;
}

