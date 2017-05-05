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
#include <unistd.h>

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
						d=joueur.getListeDominos()->at(0);
						joueur.retirerDominoMain(d);
					}
					else
					{
						d=jOrdi.getListeDominos()->at(0);
						jOrdi.retirerDominoMain(d);
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




void JeuDomino::jouerUnTour(){ //correspond au tour de jeu d'un joueur, il faut diff�rencier le tour de jeu de l'utilisateur de celui de l'ordinateur

if (main.getPseudo()==joueur.getPseudo())
	{//Pour l'utilisateur
	//Afficher le plateau, le nombre de dominos restants dans la pioche et sa liste de domino
	affichageEcranJoueur();
	//Lui demander si il souhaite d�poser un domino ou piocher
	cout <<"Poser un domino (1)"<< endl;
	cout <<"Piocher (2)"<< endl;
	int choix;
	cin >> choix;
	if (choix==1)
	//Si d�poser un domino alors:
		plateau=joueur.deposerDomino(plateau, pioche);
	else
	{//Si piocher alors il pioche
		joueur.piocher(pioche);}
	//Changer de main
	main=jOrdi;
	cout << " ###### ###### ###### ######"<< endl;
		cout <<  endl;
	}
else
{//Pour l'ordinateur
	//Afficher uniquement le plateau et le nombre de dominos restants
	affichageEcranOrdi();
	//jouer un tour ordi
	tourOrdi();
	//Changer de main
	main=joueur;
	cout << " ###### ###### ###### ######"<< endl;
		cout <<  endl;
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


bool JeuDomino::verifierFinJeu(){
	//Cette m�thode v�rifie si l'on est � la fin du jeu
	//Et si c'est le cas, alors elle attribue vrai a l'attribut "gagne" du joueur ayant gagne.

// si un des joueurs n'a plus de dominos, le jeu est fini. Sinon, si la pioche est vide et qu'aucun joueur n'a de domino compatible avec le plateau alors le jeu est fini
	bool finJeu=false; // vaut vrai si le jeu est fini
	bool joueurBloque=true;//vaut vrai si le joueur ne peut poser aucun domino
	bool ordiBloque=true;//vautvrai si l'ordi ne peut poser aucun domino

	//On regarde si le joueur peut jouer
	for(int i=0;i<joueur.getNbDominosRestants();i++)
				{
					if ((plateau.verifierCompatibilite(joueur.getListeDominos()->at(i).getValInf())==true)||(plateau.verifierCompatibilite(joueur.getListeDominos()->at(i).getValSup())==true))
						joueurBloque=false;  //si joueur possede un domino compatible avec le plateau
				}
	//On regarde si l'ordi peut jouer
	for(int i=0;i<jOrdi.getNbDominosRestants();i++)
	{
	if ((plateau.verifierCompatibilite(jOrdi.getListeDominos()->at(i).getValInf())==true)||(plateau.verifierCompatibilite(jOrdi.getListeDominos()->at(i).getValSup())==true))
						finJeu=false;  //si l'ordi possede un domino compatible avec le plateau
	}

	//On d�termine si nous sommes a la fin du jeu
	if ((joueur.getNbDominosRestants()==0) ) //un des joueurs n'a plus de dominos
		{
			finJeu = true;
			joueur.setGagne(true);
		}
		else {
			if (jOrdi.getNbDominosRestants()==0)
				{
					finJeu = true;
					jOrdi.setGagne(true);
				}
			else
			{
				if (pioche.getNbDominos()==0 && joueurBloque && ordiBloque) //si la pioche est vide
					finJeu=true;
					jOrdi.setGagne(true);
					joueur.setGagne(true);
			}
		}
	return finJeu;
}

void JeuDomino::finJeu()
{
	int nbPointJoueur=0;
	int nbPointOrdi=0;

	if (joueur.getGagne() && jOrdi.getGagne())
	{//On compte le nombre de points restants sur les dominos des joueurs
		for (int i=0;i<joueur.getNbDominosRestants();i++)
		{
			nbPointJoueur=nbPointJoueur+joueur.getListeDominos()->at(i).getValInf()+joueur.getListeDominos()->at(i).getValSup();
		}

		for (int i=0;i<jOrdi.getNbDominosRestants();i++)
		{
			nbPointOrdi=nbPointOrdi+jOrdi.getListeDominos()->at(i).getValInf()+jOrdi.getListeDominos()->at(i).getValSup();
		}
		if (nbPointJoueur>nbPointOrdi)
			cout << "Malheureusement l'ordinateur a ete plus fort que vous : votre adversaire a gagne" << endl;
		else
		{
			if (nbPointJoueur<nbPointOrdi)
				cout << "Bien jou� ! : vous etes le gagnant " << endl;
			else
			{
				cout << "Match nul !"<< endl;
			}
		}

	}
	else if(joueur.getGagne())
	{
		cout << "Bien jou� ! : vous etes le gagnant " << endl;
	}
	else
		cout << "Malheureusement l'ordinateur a ete plus fort que vous : votre adversaire a gagne" << endl;
}

void JeuDomino::affichageEcranJoueur(){ //Affichage ecran lorsque c'est au tour du joueur de jouer

	//On pr�cise le nombre de dominos restants dans la pioche
	if (pioche.getNbDominos()==1 || pioche.getNbDominos()==0)
	{
		cout << " il reste " << pioche.getNbDominos() << " domino dans la pioche " << endl;
	}
	else
		{
		cout << " il reste " << pioche.getNbDominos() << " dominos dans la pioche " << endl;
		}
	//On affiche le plateau du jeu mis � jour
	plateau.afficherPlateau();
	cout <<  endl;
	cout <<  endl;
	//Ainsi que les dominos restants dans la main du joueur
	cout << " Voici vos dominos :"<< endl;
	joueur.afficherMain();
	cout <<  endl;
	cout <<  endl;
	cout << " A vous de jouer !"<< endl;
	cout <<  endl;

}


void JeuDomino::affichageEcranOrdi(){ //Affichage ecran lorsque c'est au tour de l'ordi de jouer

	//On pr�cise le nombre de dominos restants dans la pioche
	if (pioche.getNbDominos()==1 || pioche.getNbDominos()==0)
		{
			cout << " il reste " << pioche.getNbDominos() << " domino dans la pioche " << endl;
		}
		else
			{
			cout << " il reste " << pioche.getNbDominos() << " dominos dans la pioche " << endl;
			}
	//On affiche le plateau du jeu mis � jour
		plateau.afficherPlateau();
		cout <<  endl;
		cout << " Votre adversaire est en train de jouer.. " << endl;
	//On n'affiche pas sa main car le joueur (qui est son adversaire) ne doit pas la voir
		cout <<  endl;
		cout <<  endl;
		sleep(4);


}

void JeuDomino::tourOrdi(){ //Intelligence artificielle
//Si il a un ou plusieurs dominos qui peuvent �tre pos� sur le plateau, alors il en pose un
	//On le choisi de fa�on � ce que le domino ayant le plus grand nombre de points soit pos�
	//de mani�re � avoir plus de chance de gagner si le jeu et bloqu� avant la fin
	bool dominoChoisi=false;
	Domino d(-1,-1);
	int val=0;

	for (int i=0;i<jOrdi.getNbDominosRestants();++i)
	{
		if (jOrdi.getListeDominos()->at(i).getValInf()+jOrdi.getListeDominos()->at(i).getValSup()>d.getValInf()+d.getValSup())
		{
			if (jOrdi.getListeDominos()->at(i).getValInf()==plateau.getValInf())
			{
				d=jOrdi.getListeDominos()->at(i);
				val=jOrdi.getListeDominos()->at(i).getValInf();
				dominoChoisi=true;
			}
			else if (jOrdi.getListeDominos()->at(i).getValInf()==plateau.getValSup())
				{
					d=jOrdi.getListeDominos()->at(i);
					val=jOrdi.getListeDominos()->at(i).getValInf();
					dominoChoisi=true;
				}
				else if (jOrdi.getListeDominos()->at(i).getValSup()==plateau.getValInf())
						{
								d=jOrdi.getListeDominos()->at(i);
								val=jOrdi.getListeDominos()->at(i).getValSup();
								dominoChoisi=true;
						}
					else if (jOrdi.getListeDominos()->at(i).getValSup()==plateau.getValSup())
							{
									d=jOrdi.getListeDominos()->at(i);
									val=jOrdi.getListeDominos()->at(i).getValSup();
									dominoChoisi=true;
							}
		}

	}
	 //S'il ne peut pas jouer, alors il pioche
	if (dominoChoisi)
	{
		jOrdi.retirerDominoMain(d);
		plateau.ajouterDominoPlateau(d, val);
		cout << "Domino joué par votre adversaire : " << d << endl;
		cout << "Il lui reste " << jOrdi.getNbDominosRestants() << "domino(s)"<< endl;
	}
	else
		jOrdi.piocher(pioche);
		cout << "Votre adversaire a pioché. " << endl;
		cout << "Il lui reste " << jOrdi.getNbDominosRestants() << "domino(s)"<< endl;

}
