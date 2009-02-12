#include "iastatistique.h"

IAStatistique::IAStatistique(string nom,int nbCoupAvance) : Joueur(nom){
    std::cout<<"lapin"<<std::endl;
    ss=3;
    p=2;
    lgligne = 5;
}
bool IAStatistique::placePion(){
    coul=_jeu->getEtat()->getCouleurJoueur(((Joueur*)this));
    //recuperation du plateau du jeu en cour dans plat :
    Plateau plat = Plateau(p,ss);
    for(int x = 0 ; x < p ; x++ ){
        for(int y = 0 ; y < p ; y++ ){
            for(int ssx = 0 ; ssx < ss ; ssx++ ){
                for(int ssy = 0 ; ssy < ss ; ssy++ ){
                    plat.setCouleur(x,y,ssx,ssy,_jeu->getEtat()->getCouleurCase(x,y,ssx,ssy));
                }
            }
        }
    }

    //Appel de la fonction pour chercher le coup :
    final = chercheMeilleureCoup(nbCoupAvance,coul,plat);
    //On joue le coup
    _jeu->joueCase(final.coup.plateauX,final.coup.plateauY,final.coup.sousPlateauX,final.coup.sousPlateauY);
    return false;
}
bool IAStatistique::tournePlateau(){
    _jeu->tournePlateau(final.rotation.x,final.rotation.y,final.rotation.sens);
    return false;
}

Coup IAStatistique::chercheMeilleureCoup(int nbCoupAvance,Couleur coulCourante,Plateau plat){
    // 1 : on push tt les coups valident dans une liste
    list<Coup> coupsPossibles;
    for(int x = 0 ; x < p ; x++ ){
        for(int y = 0 ; y < p ; y++ ){
            for(int ssx = 0 ; ssx < ss ; ssx++ ){
                for(int ssy = 0 ; ssy < ss ; ssy++ ){
                    if(plat.getCouleur(x,y,ssx,ssy)==Vide){
                        //Coup valide (la case est libre on peut la prendre en compte comme case � jouer possible
                        for(int tx = 0 ; tx < p ; tx++ ){
                            for(int ty = 0 ; ty < p ; ty++ ){
                                for(int sens = 0 ; sens < 2 ; sens++){
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
    list<std::pair<Coup,int> > valeur;
    // 2 : on appel chercheRecurrent sur chaques plateaux mit a jour avec un coup de la liste � chaque fois
    while(!coupsPossibles.empty()){
        Coup cc = coupsPossibles.front();
        coupsPossibles.pop_front();
        plat.setCouleur(cc.coup.plateauX,cc.coup.plateauY,cc.coup.sousPlateauX,cc.coup.sousPlateauY,cc.coup.couleur);
        valeur.push_back(std::pair<Coup,int>(cc,chercheReccurent(nbCoupAvance,(Couleur)((coulCourante%2)+1),plat)));
        plat.setCouleur(cc.coup.plateauX,cc.coup.plateauY,cc.coup.sousPlateauX,cc.coup.sousPlateauY,Vide);
    }
    int max = -9000;
    // 3 : on parcours valeur pour savoir quel coup a le meilleur score, et on le retourne.
    //for(list<std::pair<Coup,int>>::iterator it = valeur.begin() ; it != valeur.end() ; it++)
    for(list<std::pair<Coup,int> >::iterator it = valeur.begin() ; it != valeur.end() ; it++ ){
        if(it->second>max)final = it->first;
    }
    return final;

}

int IAStatistique::chercheReccurent(int nbCoupAvance,Couleur coulCourante,Plateau plat){
     int res = 0;
     /*
     *1 : Il y a 2 cas possible, soit nbCoupAvance == 0 , soit nbCoupAvance > 0
     *si == 0 : On tire avec le plateau courant N partis, N est definis par le #define du main "N"
     *si >0 : on place tout les coup possible dans la liste "coupsPossibles" puis on en pop 1,
     *on met le plateau a jour, puis on appel recursivment la fonction
    */
    if(nbCoupAvance==0){
        for(int i = 0 ; i < N ; i++){
            res +=joueAlea(plat,coul);
        }
    }
    return (int)(((float)res)/((float)N));
}

int IAStatistique::joueAlea(Plateau plat,Couleur coulCourante){
    /*ToDo :
     *Cr�e une instance de jeu avec l'etat : etat
     *jouer la partie jusqu'a la fin
     *Renvoyer :
        *egalit� : 0
        *victoire de coulCourante : valeur positive
        *victoire de !coulCourante : valeur negative
      */

     EtatReel etat = EtatReel(p, ss, lgligne);
     IARandom* j = new IARandom("IA random1");
     etat.ajoutJoueur(j, coulCourante);
     etat.ajoutJoueur(new IARandom("IA random2"), (Couleur)((coulCourante%2)+1));
     etat.setJoueurCourant(j);


    return 0;
}

