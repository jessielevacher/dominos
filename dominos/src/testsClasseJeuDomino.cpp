/*
 * testsClasseJeuDomino.cpp
 *
 *  Created on: 16 avr. 2017
 *      Author: L�a
 */


#include "JeuDomino.hpp"
#include <iostream>
using namespace std;

//Testons les m�thodes de la classe JeuDomino

//!!!!!A VOIR
void testLancerJeu() //test le constructeur de JeuDomino
{
	JeuDomino jeu;

	//Pour v�rifier l'attribution de la main
	cout << " la main est au joueur : " << jeu.main.getPseudo() << endl;

/*
 //partie de code � ajouter dans le code du constructeur � la place de distribuerDominos()
//On cr�e 2 joueurs d�tenant chacun un double, jOrdi � le plus grand donc doit avoir la main
//on peut inverser d et d1 pour donner la main au joueur
	Domino d(0,0);
		Domino d1(2,2);
			joueur.ajouterDominoMain(d);
			d.setValInf(4);
			joueur.ajouterDominoMain(d);
			jOrdi.ajouterDominoMain(d1);
			d1.setValInf(4);
			jOrdi.ajouterDominoMain(d1);


//On cr�e 2 joueurs d�tenant aucun double -->main pour l'utilisateur
Domino d(1,0);
		Domino d1(2,3);
			joueur.ajouterDominoMain(d);
			d.setValInf(4);
			joueur.ajouterDominoMain(d);
			jOrdi.ajouterDominoMain(d1);
			d1.setValInf(4);
			jOrdi.ajouterDominoMain(d1);

 //On cr�e 2 joueurs et seul l'ordi a des doubles
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

//Vérifions la main du joueur après distribution de la pioche
/*
	cout << " joueur " << endl;
	cout << " domino 1: " << jeu.joueur.listeDominos->at(0).getValInf() << jeu.joueur.listeDominos->at(0).getValSup() << endl;
	cout << " domino 2: " << jeu.joueur.listeDominos->at(1).getValInf() << jeu.joueur.listeDominos->at(1).getValSup() << endl;
	cout << " domino 3: " << jeu.joueur.listeDominos->at(2).getValInf() << jeu.joueur.listeDominos->at(2).getValSup() << endl;
	cout << " domino 4: " << jeu.joueur.listeDominos->at(3).getValInf() << jeu.joueur.listeDominos->at(3).getValSup() << endl;
	cout << " domino 5: " << jeu.joueur.listeDominos->at(4).getValInf() << jeu.joueur.listeDominos->at(4).getValSup() << endl;
	cout << " domino 6: " << jeu.joueur.listeDominos->at(5).getValInf() << jeu.joueur.listeDominos->at(5).getValSup() << endl;
	cout << " domino 7: " << jeu.joueur.listeDominos->at(6).getValInf() << jeu.joueur.listeDominos->at(6).getValSup() << endl;

	cout << " ordi " << endl;
	cout << " domino 1: " << jeu.jOrdi.listeDominos->at(0).getValInf() << jeu.jOrdi.listeDominos->at(0).getValSup() << endl;
			cout << " domino 2: " << jeu.jOrdi.listeDominos->at(1).getValInf() << jeu.jOrdi.listeDominos->at(1).getValSup() << endl;
			cout << " domino 3: " << jeu.jOrdi.listeDominos->at(2).getValInf() << jeu.jOrdi.listeDominos->at(2).getValSup() << endl;
			cout << " domino 4: " << jeu.jOrdi.listeDominos->at(3).getValInf() << jeu.jOrdi.listeDominos->at(3).getValSup() << endl;
			cout << " domino 5: " << jeu.jOrdi.listeDominos->at(4).getValInf() << jeu.jOrdi.listeDominos->at(4).getValSup() << endl;
			cout << " domino 6: " << jeu.jOrdi.listeDominos->at(5).getValInf() << jeu.jOrdi.listeDominos->at(5).getValSup() << endl;
			cout << " domino 7: " << jeu.jOrdi.listeDominos->at(6).getValInf() << jeu.jOrdi.listeDominos->at(6).getValSup() << endl;
*/


//Pour vérifier l'initialisation du plateau
	cout << " bornes du plateau: " << jeu.plateau.getValInf() << jeu.plateau.getValSup() << endl;
	cout << " domino déposer sur le plateau en premier: " <<  	jeu.plateau.dominosPlateau->at(0).getValInf() << jeu.plateau.dominosPlateau->at(0).getValSup() <<endl;


}


void testjoueurAyantPlusGrandDouble() //test la m�thode qui doit retourner qui des 2 joueurs d�tient le plus grand double
{
	JeuDomino jeu;
	//On crée 2 joueurs d�tenant chacun un double, jOrdi � le plus grand donc doit avoir la main
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

