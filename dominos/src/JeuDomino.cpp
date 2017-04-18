/*
 * JeuDomino.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: lmanneheut
 */

#include "Plateau.hpp"
#include "JoueurDomino.hpp"
#include "Pioche.hpp"
#include "JeuDomino.hpp"

JeuDomino::JeuDomino(){ //constructeur
/*	Domino d(0,0);
	Plateau p(d);
	JoueurDomino j1;
	Pioche pi;

	 plateau=new Plateau p(d);
	 joueur=j1;
	 jOrdi=j1;
	 main=j1;
	 pioche=pi;
*/


	//on cr�e une pioche
		Pioche pi;
		pioche=pi;

	//On cr�e un premier joueur
		JoueurDomino j1; //joueur anonyme tout d'abord
		//On affecte � l'attribut joueur un joueur ayant pour pseudo le pseudo choisi par l'utilisateur
		cout << " Veuillez entrer le pseudo sous lequel vous souhaitez jouer : " << endl;
		string pseudo;
		cin >> pseudo ;
		j1.setPseudo(pseudo);
		joueur=j1;

	//Puis on cr�e un joueur artificiel, qui sera jou� par l'ordinateur
		JoueurDomino j2;
		j2.setPseudo("ordi");
		jOrdi=j2;

	//On distribue les 7 dominos n�cessaire au d�but de la partie � chacun des deux joueurs
		joueur.distribuerDominos(pi);
		jOrdi.distribuerDominos(pi);

	//On attribut la main au premier tour � un des 2 joueurs
		attribuerMain();


	//On cr�e un plateau contenant un unique domino,
		//D�terminons le domino � d�poser en premier :

		 // c'est � dire le domino ayant permis au joueur de gagner la main
		Domino d(0,0);
		if (main.doubleExiste())
		{
			if (main.getPseudo()==joueur.getPseudo())
			{
				d=joueur.plusGrandDouble();
				joueur.retirerDominoMain(d);
			}
			else
			{
				d=jOrdi.plusGrandDouble();
				jOrdi.retirerDominoMain(d);
			}
		}
		else
		 //ou Un domino al�atoire de la main du joueur ayant la main au premier tour si le joueur a d� �tre choisi al�atoirement
		 	 	 //On prend le premier domino, de sa main, ce qui reste al�atoire puisqu'ils ont �t� distribu�s al�atoirement
		{
			if (main.getPseudo()==joueur.getPseudo())
					{
						d=joueur.listeDominos->at(0);
						joueur.retirerDominoMain(d);
					}
					else
					{
						d=jOrdi.listeDominos->at(0);
						jOrdi.retirerDominoMain(d);
					}

		}
		/*Plateau p(d);
		plateau=p;*/


}


//A TESTER
void JeuDomino::lancerJeu(){ //pas fait

//on cr�e une pioche
	Pioche pi;
	pioche=pi;

//On cr�e un premier joueur
	JoueurDomino j1; //joueur anonyme tout d'abord
	//On affecte � l'attribut joueur un joueur ayant pour pseudo le pseudo choisi par l'utilisateur
	cout << " Veuillez entrer le pseudo sous lequel vous souhaitez jouer : " << endl;
	string pseudo;
	cin >> pseudo ;
	j1.setPseudo(pseudo);
	joueur=j1;

//Puis on cr�e un joueur artificiel, qui sera jou� par l'ordinateur
	JoueurDomino j2;
	j2.setPseudo("ordi");
	jOrdi=j2;

//On distribue les 7 dominos n�cessaire au d�but de la partie � chacun des deux joueurs
	joueur.distribuerDominos(pi);
	jOrdi.distribuerDominos(pi);

//On attribut la main au premier tour � un des 2 joueurs
	attribuerMain();


//On cr�e un plateau contenant un unique domino,
	//D�terminons le domino � d�poser en premier :

	 // c'est � dire le domino ayant permis au joueur de gagner la main
	Domino d(0,0);
	if (main.doubleExiste())
	{
		if (main.getPseudo()==joueur.getPseudo())
		{
			d=joueur.plusGrandDouble();
			joueur.retirerDominoMain(d);
		}
		else
		{
			d=jOrdi.plusGrandDouble();
			jOrdi.retirerDominoMain(d);
		}
	}
	else
	 //ou Un domino al�atoire de la main du joueur ayant la main au premier tour si le joueur a d� �tre choisi al�atoirement
	 	 	 //On prend le premier domino, de sa main, ce qui reste al�atoire puisqu'ils ont �t� distribu�s al�atoirement
	{
		if (main.getPseudo()==joueur.getPseudo())
				{
					d=joueur.listeDominos->at(0);
					joueur.retirerDominoMain(d);
				}
				else
				{
					d=jOrdi.listeDominos->at(0);
					jOrdi.retirerDominoMain(d);
				}

	}
	/*Plateau p(d);
	plateau=p;*/


}

/*void JeuDomino::poserPion(){//permet au joueur qui � la main (� qui c'est le tour de jouer) de d�poser le domino qu'il souhaite sur le plateau
	main.deposerDomino();

}

void JeuDomino::piocher(){ //permet au joueur qui � la main (� qui c'est le tour de jouer) de piocher un domino au hasard dans la pioche
	main.piocher();
}
*/

void JeuDomino::verifierFinJeu(){
	//pas fait
}

void JeuDomino::jouerUnTour(){ //correspond au tour de jeu d'un joueur, il faut diff�rencier le tour de jeu de l'utilisateur de celui de l'ordinateur

if (main.getPseudo()==joueur.getPseudo())
	{//Pour l'utilisateur
	//Afficher le plateau, le nombre de dominos restants dans la pioche et sa liste de domino
	affichageEcranJoueur();
	//Lui demander si il souhaite d�poser un domino ou piocher
	//Si d�poser un domino alors:
		joueur.deposerDomino();
	//Si piocher alors il pioche
		joueur.piocher();
	//Changer de main
	main=jOrdi;
	}
else
{//Pour l'ordinateur
	//Afficher uniquement le plateau et le nombre de dominos restants
	affichageEcranOrdi();
	//jouer un tour ordi
	tourOrdi();
	//Changer de main
	main=joueur;
}
}


//A TESTER
void JeuDomino::attribuerMain(){//On attribut la main au premier tour � un des 2 joueurs

		if (!joueur.doubleExiste() && !jOrdi.doubleExiste()) //On donne la main au joueur ayant le plus grand double
		{
			main=joueurAyantPlusGrandDouble(joueur,joueur.plusGrandDouble(),jOrdi, jOrdi.plusGrandDouble());

		}
		else if (joueur.doubleExiste())
			{
				main=joueur;
				joueur.setMain("True");
			}
			else if (jOrdi.doubleExiste())
				{
					main=jOrdi;
					jOrdi.setMain("True");
				}
				else //Ou � l'utilisateur si aucun des deux n'a de double dans sa liste de dominos
				{
					main=joueur;
					joueur.setMain("True");
				}

}


//A TESTER
//On souhaite d�terminer le joueur qui d�tient le plus grand double
JoueurDomino JeuDomino::joueurAyantPlusGrandDouble(JoueurDomino j1, Domino d1, JoueurDomino j2, Domino d2){

	Domino d(0,0);
	JoueurDomino j=j1;

//On cherche le plus grand double dans la main du premier joueur
	for ( int i = 0; i < j1.getNbDominosRestants(); ++i )
	{
		if ((j1.listeDominos->at(i).getValInf() == j1.listeDominos->at(i).getValSup()) && (j1.listeDominos->at(i).getValSup() > d.getValInf()))
			{
				d.setValInf(j1.listeDominos->at(i).getValInf());
				d.setValSup(j1.listeDominos->at(i).getValSup());
			}
	}

// Si le deuxi�me joueur a un double plus grand que le premier joueur alors on garde le joueur 2
	int i=0;
	while ( ( i < j2.getNbDominosRestants()) && (j.getPseudo()!=j2.getPseudo())  )
		{
			++i;
			if ((j2.listeDominos->at(i).getValInf() == j2.listeDominos->at(i).getValSup()) && (j2.listeDominos->at(i).getValSup() > d.getValInf()))
				{
					d.setValInf(j2.listeDominos->at(i).getValInf());
					d.setValSup(j2.listeDominos->at(i).getValSup());
					j=j2;
				}
		}


	return j;
}

void JeuDomino::affichageEcranJoueur(){
	//pas fait
}

void JeuDomino::affichageEcranOrdi(){
	//pas fait
}

void JeuDomino::tourOrdi(){ //Intelligence artificielle
	//pas fait
}


