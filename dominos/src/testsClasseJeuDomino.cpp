/*
 * testsClasseJeuDomino.cpp
 *
 *  Created on: 16 avr. 2017
 *      Author: Léa
 */


#include "JeuDomino.hpp"
#include <iostream>
using namespace std;

//Testons les méthodes de la classe JeuDomino

//!!!!!A VOIR
void testLancerJeu() //test le constructeur de JeuDomino
{
	JeuDomino jeu;

	//Pour vérifier l'attribution de la main
	cout << " la main est au joueur : " << jeu.main.getPseudo() << endl;

/*
 //partie de code à ajouter dans le code du constructeur à la place de distribuerDominos()
//On crée 2 joueurs détenant chacun un double, jOrdi à le plus grand donc doit avoir la main
//on peut inverser d et d1 pour donner la main au joueur
	Domino d(0,0);
		Domino d1(2,2);
			joueur.ajouterDominoMain(d);
			d.setValInf(4);
			joueur.ajouterDominoMain(d);
			jOrdi.ajouterDominoMain(d1);
			d1.setValInf(4);
			jOrdi.ajouterDominoMain(d1);


//On crée 2 joueurs détenant aucun double -->main pour l'utilisateur
Domino d(1,0);
		Domino d1(2,3);
			joueur.ajouterDominoMain(d);
			d.setValInf(4);
			joueur.ajouterDominoMain(d);
			jOrdi.ajouterDominoMain(d1);
			d1.setValInf(4);
			jOrdi.ajouterDominoMain(d1);

 //On crée 2 joueurs et seul l'ordi a des doubles
  Domino d1(0,0);
				for(int i=0;i<7;++i){
						d1.setValInf(i);
						d1.setValSup(i);
					jOrdi.ajouterDominoMain(d1);

					}

					for(int i=0;i<6;++i){
							d1.setValInf(i+1);
							d1.setValSup(i);
						joueur.ajouterDominoMain(d1);

						}
					d1.setValInf(2);
					d1.setValSup(0);
					jOrdi.ajouterDominoMain(d1);
 */

//Pour vérifier l'initialisation du plateau
	cout << " bornes du plateau: " << jeu.plateau.getValInf() << jeu.plateau.getValSup() << endl;
	cout << " domino déposer sur le plateau en premier: " <<  	jeu.plateau.dominosPlateau->at(0).getValInf() << jeu.plateau.dominosPlateau->at(0).getValSup() <<endl;


}


void testjoueurAyantPlusGrandDouble() //test la méthode qui doit retourner qui des 2 joueurs détient le plus grand double
{
	JeuDomino jeu;
	//On crée 2 joueurs détenant chacun un double, jOrdi à le plus grand donc doit avoir la main
	//on peut inverser d et d1 pour donner la main au joueur
		Domino d(0,0);
			Domino d1(2,2);
				jeu.joueur.ajouterDominoMain(d1);
				d1.setValInf(4);
				jeu.joueur.ajouterDominoMain(d1);
				jeu.jOrdi.ajouterDominoMain(d);
				d.setValInf(4);
				jeu.jOrdi.ajouterDominoMain(d);

				d.setValInf(0);
				d.setValSup(0);
				d1.setValInf(2);
				d1.setValSup(2);

				JoueurDomino j=jeu.joueurAyantPlusGrandDouble(jeu.joueur,d1,jeu.jOrdi,d);
cout << " le joueur ayant le plus grand double est : " << j.getPseudo() << endl;
}



int main()
{
	testLancerJeu();
	//testattribuerMain();
	//testjoueurAyantPlusGrandDouble();
	return 0;
}

