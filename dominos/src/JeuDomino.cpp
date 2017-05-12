/*
 * JeuDomino.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: lmanneheut
 */

/*!
 * \file JeuDomino.cpp
 * \brief Jeu du domino
 * \author Léa Manneheut
 */

#include "Plateau.hpp"
#include "JoueurDomino.hpp"
#include "Pioche.hpp"
#include "JeuDomino.hpp"
#include <unistd.h>

/*!
 *  \brief Constructeur
 *
 *  Constructeur de la classe JeuDomino
 *
 */
JeuDomino::JeuDomino(){
	//on crée une pioche
		Pioche pi;
		pioche=pi;

	//On crée un premier joueur
		JoueurDomino j1; //joueur anonyme tout d'abord

	//On affecte à l'attribut joueur un joueur ayant pour pseudo le pseudo choisi par l'utilisateur
		j1.saisirPseudo();
		joueur=j1;

	//Puis on crée un joueur artificiel, qui sera joué par l'ordinateur
		JoueurDomino j2;
		j2.setPseudo("ordi");
		jOrdi=j2;

	//On distribue les 7 dominos nécessaire au début de la partie à chacun des deux joueurs
		joueur.distribuerDominos(pi);
		jOrdi.distribuerDominos(pi);




	//On attribut la main au premier tour à un des 2 joueurs
		attribuerMain();


	//On crée un plateau contenant un unique domino,
		//Déterminons le domino à déposer en premier :
		//c'est à dire le domino ayant permis au joueur de gagner la main
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
		 //ou un domino aléatoire de la main du joueur ayant la main au premier tour si le joueur a du être choisi aléatoirement
		 	 	 //On prend le premier domino, de sa main, ce qui reste aléatoire puisqu'ils ont été distribués aléatoirement
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

/*!
 * \brief Un tour de jeu
 *
 * Dans le cas d'un tour de jeu du joueur, celui-ci choisit de joueur ou piocher
 * et l'action est exécutée puis on passe la main à l'ordinateur.
 * Dans le cas d'un tour de jeu de l'ordinateur, on applique la méthode tourOrdi définie
 * par la suite puis on passe la main au joueur.
 *
 */
void JeuDomino::jouerUnTour(){ //correspond au tour de jeu d'un joueur, il faut différencier le tour de jeu de l'utilisateur de celui de l'ordinateur

if (main.getPseudo()==joueur.getPseudo()) {
	//Pour l'utilisateur
	//Afficher le plateau, le nombre de dominos restants dans la pioche et sa liste de domino
	affichageEcranJoueur();
	//Lui demander si il souhaite déposer un domino ou piocher
	cout <<"Poser un domino (1)"<< endl;
	cout <<"Piocher (2)"<< endl;
	int choix;
	cin >> choix;
	if (choix==1)
	//Si déposer un domino alors:
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


/*!
 * \brief Attribution de la main au premier tour de jeu
 *
 * 4 cas se présentent :
 * 1) Les deux joueurs ont un double donc celui ayant le plus grand double prend la main ;
 * 2) Le joueur possède un double mais pas l'ordinateur donc le joueur prend la main ;
 * 3) L'ordinateur possède un double mais pas le joueur donc l'ordinateur prend la main ;
 * 4) Aucun des deux n'a de double, le joueur prend la main par défaut.
 *
 */
void JeuDomino::attribuerMain(){//On attribut la main au premier tour à l'un des 2 joueurs

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
				else //Ou à l'utilisateur si aucun des deux n'a de double dans sa liste de dominos
				{
					main=joueur;
					joueur.setMain("True");
				}

}


/*!
 * \brief Détermination du joueur ayant le plus grand double
 *
 * \param j1 : le joueur 1
 * \param d1 : le plus grand double du joueur 1
 * \param j2 : le joueur 2
 * \param d2 : le plus grand double du joueur 2
 *
 * \return le joueur ayant le plus grand double
 */
//On souhaite déterminer le joueur qui détient le plus grand double
JoueurDomino JeuDomino::joueurAyantPlusGrandDouble(JoueurDomino j1, Domino d1, JoueurDomino j2, Domino d2){

	JoueurDomino j;
if (d1.getValInf()>d2.getValInf()) //Si j1 a un plus grand domino que j2 alors c'est lui qui ressort
	j=j1;
else //sinon c'est j2
	j=j2;

	return j;
}

/*!
 * \brief On vérifie si on est à la fin du jeu
 *
 * Plusieurs situations entraînent la fin de la partie :
 * 1) Un des deux joueurs n'a plus de dominos, on le déclare gagnant ;
 * 2) La pioche est vide et aucun des deux joueurs ne peut poser de domino, la partie s'arrête.
 *
 * \return vrai si la partie est terminée, faux sinon
 */
bool JeuDomino::verifierFinJeu(){
	//Cette méthode vérifie si l'on est à la fin du jeu
	//Et si c'est le cas, alors elle attribue vrai a l'attribut "gagne" du joueur ayant gagne.

// si un des joueurs n'a plus de dominos, le jeu est fini. Sinon, si la pioche est vide et qu'aucun joueur n'a de domino compatible avec le plateau alors le jeu est fini
	bool finJeu=false; // vaut vrai si le jeu est fini
	bool joueurBloque=true;//vaut vrai si le joueur ne peut poser aucun domino
	bool ordiBloque=true;//vaut vrai si l'ordi ne peut poser aucun domino

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
						ordiBloque=false;  //si l'ordi possede un domino compatible avec le plateau
	}

	//On détermine si nous sommes a la fin du jeu
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

/*!
 * \brief Comptage et affichage des points en fin de partie
 *
 * Tout d'abord, si on est dans le cas où la pioche est vide et qu'il reste des dominos dans les mains
 * des joueurs on compte leurs points et on détermine le gagnant. Finalement on affiche si le joueur
 * a gagné, perdu ou fait match nul.
 *
 */
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
			cout << "Malheureusement l'ordinateur a été plus fort que vous : votre adversaire a gagné" << endl;
		else
		{
			if (nbPointJoueur<nbPointOrdi)
				cout << "Bien joué ! : vous êtes le gagnant " << endl;
			else
			{
				cout << "Match nul !"<< endl;
			}
		}

	}
	else if(joueur.getGagne())
	{
		cout << "Bien joué ! : vous êtes le gagnant " << endl;
	}
	else
		cout << "Malheureusement l'ordinateur a été plus fort que vous : votre adversaire a gagné" << endl;
}


/*!
 * \brief Affichage de l'écran lorsque c'est au tour du joueur
 *
 * On affiche le nombre de dominos restants dans la pioche, le plateau à jour puis la main du joueur
 *
 */
void JeuDomino::affichageEcranJoueur(){ //Affichage ecran lorsque c'est au tour du joueur de jouer

	//On précise le nombre de dominos restants dans la pioche
	if (pioche.getNbDominos()==1 || pioche.getNbDominos()==0)
	{
		cout << " Il reste " << pioche.getNbDominos() << " domino dans la pioche " << endl;
	}
	else
		{
		cout << " Il reste " << pioche.getNbDominos() << " dominos dans la pioche " << endl;
		}
	//On affiche le plateau du jeu mis à jour
	plateau.afficherPlateau();
	cout <<  endl;
	cout <<  endl;
	//Ainsi que les dominos restants dans la main du joueur
	cout << " Voici vos dominos :"<< endl;
	joueur.afficherMain();
	cout <<  endl;
	cout <<  endl;
	cout << " À vous de jouer !"<< endl;
	cout <<  endl;

}

/*!
 * \brief Affichage de l'écran lorsque c'est au tour de l'ordinateur
 *
 * On affiche le nombre de dominos restants dans la pioche et le plateau à jour. Nous n'affichons
 * pas le jeu de l'ordinateur pour que le joueur ne le voit pas.
 *
 */
void JeuDomino::affichageEcranOrdi(){ //Affichage ecran lorsque c'est au tour de l'ordi de jouer

	//On précise le nombre de dominos restants dans la pioche
	if (pioche.getNbDominos()==1 || pioche.getNbDominos()==0)
		{
			cout << " Il reste " << pioche.getNbDominos() << " domino dans la pioche " << endl;
		}
		else
			{
			cout << " Il reste " << pioche.getNbDominos() << " dominos dans la pioche " << endl;
			}
	//On affiche le plateau du jeu mis à jour
		plateau.afficherPlateau();
		cout <<  endl;
		cout << " Votre adversaire est en train de jouer.. " << endl;
	//On n'affiche pas sa main car le joueur (qui est son adversaire) ne doit pas la voir
		cout <<  endl;
		cout <<  endl;
		sleep(4);


}

/*!
 * \brief Tour de jeu de l'ordinateur
 *
 * La stratégie utilisée pour déterminer le domino à poser est la suivante :
 * on choisit le domino ayant le plus grand nombre de points qui peut aller sur le plateau.
 * Si aucun domino ne correspond, l'ordinateur pioche.
 *
 */
void JeuDomino::tourOrdi(){ //Intelligence artificielle
//Si il a un ou plusieurs dominos qui peuvent être posé sur le plateau, alors il en pose un
	//On le choisit de façon à ce que le domino ayant le plus grand nombre de points soit posé
	//de manière à avoir plus de chance de gagner si le jeu et bloqué avant la fin
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
		cout << "Il lui reste " << jOrdi.getNbDominosRestants() << " domino(s)"<< endl;
	}
	else
		{jOrdi.piocher(pioche);
		cout << "Votre adversaire a pioché. " << endl;
		cout << "Il lui reste " << jOrdi.getNbDominosRestants() << "domino(s)"<< endl;
		}
}
