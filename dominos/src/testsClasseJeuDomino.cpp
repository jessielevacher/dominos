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

//Vérifions la main du joueur après distribution de la pioche et depot du premier domino sur le plateau
	cout << " dominos du joueur " << endl;
	for (int i=0;i<7;i++)
	cout << jeu.joueur.getListeDominos()->at(i) <<endl;

	//Vérifions la main de l'ordi après distribution de la pioche
	cout << " dominos de l'ordi " << endl;
		for (int i=0;i<7;i++)
		cout << jeu.jOrdi.getListeDominos()->at(i) <<endl;




//Pour vérifier l'initialisation du plateau
	cout << " bornes du plateau: " << jeu.plateau.getValInf() << "-" << jeu.plateau.getValSup() << endl;
	cout << " domino déposer sur le plateau en premier: " <<  	jeu.plateau.getDominosPlateau()->at(0)  <<endl;



	cout << " la main est au joueur : " << jeu.main.getPseudo() << endl;



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


void testaffichageEcranJoueur()
{
	JeuDomino jeu;

	jeu.affichageEcranJoueur();

}

void testaffichageEcranOrdi()
{
	JeuDomino jeu;

	jeu.affichageEcranOrdi();

	cout << "bonjour"<<endl;

}

void testjouerUnTour()
{
	JeuDomino jeu;
	cout << "la main est � " << jeu.main.getPseudo() <<endl;

	jeu.jouerUnTour();
	jeu.jouerUnTour();
	jeu.jouerUnTour();

}


void testverifierFinJeu()
{
	JeuDomino jeu;
	string fin;

//On n'est pas � la fin du jeu ni pioche ni jeu des joueurs vide
	/*bool a=jeu.verifierFinJeu();
	if (a)
	{
		fin="vrai";
	}
	else
	{
		fin="faux";
	}
	cout << "fin du jeu " << fin << endl;*/

//Pioche vide mais joueurs peuvent encore jouer : pas fin du jeu

	/*jeu.joueur.distribuerDominos(jeu.pioche);
	jeu.jOrdi.distribuerDominos(jeu.pioche);

		cout << "dominos restants dans la pioche :" << jeu.pioche.getNbDominos() << endl;

	bool a=jeu.verifierFinJeu();
	if (a)
	{
		fin="vrai";
	}
	else
	{
		fin="faux";
	}
	cout << "fin du jeu " << fin << endl;*/

//Pioche vide et main des joueurs non vide mais les joueurs ne peuvent plus jouer : bloqu�, fin du jeu


	jeu.plateau.afficherPlateau();
	cout<< endl;

	for (int i=0;i<14;i++)
	{
		jeu.pioche.retirerDominoPioche();
	}
	cout << "dominos restants dans la pioche :" << jeu.pioche.getNbDominos() << endl;

	int c = jeu.joueur.getNbDominosRestants();
	for (int i=0;i<jeu.joueur.getNbDominosRestants()-1;i++)
	{
	jeu.joueur.getListeDominos()->erase(jeu.joueur.getListeDominos()->begin());
	c--;
	}
	jeu.joueur.setNbDominosRestants(c);

	int b=jeu.jOrdi.getNbDominosRestants();
	for (int i=0;i<jeu.jOrdi.getNbDominosRestants()-1;i++)
		{
	jeu.jOrdi.getListeDominos()->erase(jeu.jOrdi.getListeDominos()->begin());
	b--;
	}
	jeu.jOrdi.setNbDominosRestants(b);

	jeu.joueur.afficherMain();
	cout<< endl;

	jeu.jOrdi.afficherMain();
	cout<< endl;



	bool a=jeu.verifierFinJeu();
		if (a)
		{
			fin="vrai";
		}
		else
		{
			fin="faux";
		}
		cout << "fin du jeu " << fin << endl;

//Jeu d'un joueur vide et pioche vide : Fin jeu*/


 /*for (int i=0;i<14;i++)
	{
		jeu.pioche.retirerDominoPioche();
	}
	cout << "dominos restants dans la pioche :" << jeu.pioche.getNbDominos() << endl;


	int c = jeu.joueur.getNbDominosRestants();//on vide le jeu du joueur
		for (int i=0;i<jeu.joueur.getNbDominosRestants();i++)
		{
		jeu.joueur.getListeDominos()->erase(jeu.joueur.getListeDominos()->begin());
		c--;
		}
		jeu.joueur.setNbDominosRestants(c);

		cout << jeu.joueur.getNbDominosRestants() << endl;

		bool a=jeu.verifierFinJeu();//on verifie si on est bien a la fin du jeu
				if (a)
				{
					fin="vrai";
				}
				else
				{
					fin="faux";
				}
				cout << "fin du jeu " << fin << endl;*/


//Jeu d'un joueur vide et pioche non vide : Fin jeu

	/*int c = jeu.jOrdi.getNbDominosRestants();//on vide le jeu du joueur
			for (int i=0;i<jeu.jOrdi.getNbDominosRestants();i++)
			{
			jeu.jOrdi.getListeDominos()->erase(jeu.jOrdi.getListeDominos()->begin());
			c--;
			}
			jeu.jOrdi.setNbDominosRestants(c);

			cout << jeu.jOrdi.getNbDominosRestants() << endl;

			bool a=jeu.verifierFinJeu();//on verifie si on est bien a la fin du jeu
							if (a)
							{
								fin="vrai";
							}
							else
							{
								fin="faux";
							}
							cout << "fin du jeu " << fin << endl;*/




}


int main()
{
	//testLancerJeu();
	//testattribuerMain();
	//testjoueurAyantPlusGrandDouble();
	//testtourordi();
	//testaffichageEcranJoueur();
	//testaffichageEcranOrdi();
	//testjouerUnTour();
	testverifierFinJeu();
	return 0;
}




