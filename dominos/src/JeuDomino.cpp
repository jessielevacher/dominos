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
				//joueur.retirerDominoMain(d);
			}
			else
			{
				d=jOrdi.plusGrandDouble();
				//jOrdi.retirerDominoMain(d);
			}
		}
		else
		 //ou Un domino al�atoire de la main du joueur ayant la main au premier tour si le joueur a d� �tre choisi al�atoirement
		 	 	 //On prend le premier domino, de sa main, ce qui reste al�atoire puisqu'ils ont �t� distribu�s al�atoirement
		{
			if (main.getPseudo()==joueur.getPseudo())
					{
						d=joueur.getListeDominos()->at(0);
						//joueur.retirerDominoMain(d);
					}
					else
					{
						d=jOrdi.getListeDominos()->at(0);
						//jOrdi.retirerDominoMain(d);
					}

		}

		Plateau p;
		plateau=p;
		plateau.setValInf(d.getValInf());
		plateau.setValSup(d.getValSup());
		plateau.setBackDominosPlateau(d);

		if (main.getPseudo()==joueur.getPseudo())
				main.setPseudo(jOrdi.getPseudo());
		else
			main.setPseudo(joueur.getPseudo());

}


//UTILE ??
/*void JeuDomino::poserPion(){//permet au joueur qui � la main (� qui c'est le tour de jouer) de d�poser le domino qu'il souhaite sur le plateau
	main.deposerDomino();

}

void JeuDomino::piocher(){ //permet au joueur qui � la main (� qui c'est le tour de jouer) de piocher un domino au hasard dans la pioche
	main.piocher();
}
*/


//A TESTER QUAND ON AURA LES FONCTIONS
void JeuDomino::jouerUnTour(){ //correspond au tour de jeu d'un joueur, il faut diff�rencier le tour de jeu de l'utilisateur de celui de l'ordinateur

if (main.getPseudo()==joueur.getPseudo())
	{//Pour l'utilisateur
	//Afficher le plateau, le nombre de dominos restants dans la pioche et sa liste de domino
	affichageEcranJoueur();
	//Lui demander si il souhaite d�poser un domino ou piocher
	//Si d�poser un domino alors:
		joueur.deposerDomino(plateau, pioche);
	//Si piocher alors il pioche
		joueur.piocher(pioche);
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



void JeuDomino::attribuerMain(){//On attribut la main au premier tour � un des 2 joueurs

		if (joueur.doubleExiste() && jOrdi.doubleExiste()) //On donne la main au joueur ayant le plus grand double
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



//On souhaite d�terminer le joueur qui d�tient le plus grand double
JoueurDomino JeuDomino::joueurAyantPlusGrandDouble(JoueurDomino j1, Domino d1, JoueurDomino j2, Domino d2){

	JoueurDomino j;
if (d1.getValInf()>d2.getValInf()) //Si j1 a un plus grand domino que j2 alors c'est lui qui ressort
	j=j1;
else //sinon c'est j2
	j=j2;

	return j;
}

void JeuDomino::verifierFinJeu(){//pas fait
}

//A TESTER QUAND ON AURA LES FONCTIONS D AFFICHAGE
void JeuDomino::affichageEcranJoueur(){ //Affichage �cran lorsque c'est au tour du joueur de jouer
	cout << " pioche : " << pioche.getNbDominos() << " dominos restants " << endl;
	//plateau.affichagePlateau();
	//joueur.affichageJeu();
}

//A TESTER QUAND ON AURA LES FONCTIONS D AFFICHAGE
void JeuDomino::affichageEcranOrdi(){ //Affichage �cran lorsque c'est au tour de l'ordi de jouer
	cout << " pioche : " << pioche.getNbDominos() << " dominos restants " << endl;
		//plateau.affichagePlateau();
}

//A TESTER QUAND ON AURA LES FONCTIONS
void JeuDomino::tourOrdi(){ //Intelligence artificielle
//Si il a un ou plusieurs dominos qui peuvent �tre pos� sur le plateau, alors il en pose un
	//On le choisi de fa�on � ce que le domino ayant le plus grand nombre de points soit pos�
	//de mani�re � avoir plus de chance de gagner si le jeu et bloqu� avant la fin
	bool dominoChoisi="False";
	Domino d(-1,-1);
	for (int i=0;i<jOrdi.getNbDominosRestants();++i)
	{
		if (jOrdi.getListeDominos()->at(i).getValInf()+jOrdi.getListeDominos()->at(i).getValSup()>d.getValInf()+d.getValSup())
			if (jOrdi.getListeDominos()->at(i).getValInf()==plateau.getValInf())
			{
				d=jOrdi.getListeDominos()->at(i);
				int val=jOrdi.getListeDominos()->at(i).getValInf();
				dominoChoisi="True";
			}
			else
			{
					d=jOrdi.getListeDominos()->at(i);
					int val=jOrdi.getListeDominos()->at(i).getValSup();
					dominoChoisi="True";
			}

	}
	 //S'il ne peut pas jouer, alors il pioche
	if (dominoChoisi)
		jOrdi.retirerDominoMain(d);
		//plateau.ajouterDominoPlateau(d, val);
	else
		jOrdi.piocher(pioche);
}


