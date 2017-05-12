/*
 * JeuDomino.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: lmanneheut
 */

#ifndef SRC_JEUDOMINO_HPP_
#define SRC_JEUDOMINO_HPP_

/*!
 * \file JeuDomino.hpp
 * \brief Jeu du domino
 * \author Léa Manneheut
 */

#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;

#include "Plateau.hpp"
#include "JoueurDomino.hpp"
#include "Pioche.hpp"
#include "Domino.hpp"


/*!
 * \class JeuDomino
 * \brief Classe représentant le jeu du domino
 *
 *  La classe gère le jeu du domino
 */
class JeuDomino{

	public:
		JoueurDomino joueur; /*!< Joueur*/
		JoueurDomino jOrdi; /*!< Ordinateur*/
		JoueurDomino main; /*!< Symbolise le joueur ayant la main*/
		Pioche pioche; /*!< Pioche du jeu*/
		Plateau plateau; /*!< Plateau du jeu*/


	public:
		/*!
		 *  \brief Constructeur
		 *
		 *  Constructeur de la classe JeuDomino
		 *
		 */
		JeuDomino();

		/*!
		 * \brief Un tour de jeu
		 *
		 * Dans le cas d'un tour de jeu du joueur, celui-ci choisit de joueur ou piocher
		 * et l'action est exécutée puis on passe la main à l'ordinateur.
		 * Dans le cas d'un tour de jeu de l'ordinateur, on applique la méthode tourOrdi définie
		 * par la suite puis on passe la main au joueur.
		 *
		 */
		void jouerUnTour();

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
		void attribuerMain();

		/*!
		 * \brief Détermination du joueur ayant le plus grand double
		 *
		 * \param Le joueur 1
		 * \param Le plus grand double du joueur 1
		 * \param Le joueur 2
		 * \param Le plus grand double du joueur 2
		 *
		 * \return le joueur ayant le plus grand double
		 */
		//On souhaite déterminer le joueur qui détient le plus grand double
		JoueurDomino joueurAyantPlusGrandDouble(JoueurDomino, Domino, JoueurDomino, Domino);

		/*!
		 * \brief On vérifie si on est à la fin du jeu
		 *
		 * Plusieurs situations entraînent la fin de la partie :
		 * 1) Un des deux joueurs n'a plus de dominos, on le déclare gagnant ;
		 * 2) La pioche est vide et aucun des deux joueurs ne peut poser de domino, la partie s'arrête.
		 *
		 * \return vrai si la partie est terminée, faux sinon
		 */
		bool verifierFinJeu();

		/*!
		 * \brief Comptage et affichage des points en fin de partie
		 *
		 * Tout d'abord, si on est dans le cas où la pioche est vide et qu'il reste des dominos dans les mains
		 * des joueurs on compte leurs points et on détermine le gagnant. Finalement on affiche si le joueur
		 * a gagné, perdu ou fait match nul.
		 *
		 */
		void finJeu();

		/*!
		 * \brief Affichage de l'écran lorsque c'est au tour du joueur
		 *
		 * On affiche le nombre de dominos restants dans la pioche, le plateau à jour puis la main du joueur
		 *
		 */
		void affichageEcranJoueur();

		/*!
		 * \brief Affichage de l'écran lorsque c'est au tour de l'ordinateur
		 *
		 * On affiche le nombre de dominos restants dans la pioche et le plateau à jour. Nous n'affichons
		 * pas le jeu de l'ordinateur pour que le joueur ne le voit pas.
		 *
		 */
		void affichageEcranOrdi();

		/*!
		 * \brief Tour de jeu de l'ordinateur
		 *
		 * La stratégie utilisée pour déterminer le domino à poser est la suivante :
		 * on choisit le domino ayant le plus grand nombre de points qui peut aller sur le plateau.
		 * Si aucun domino ne correspond, l'ordinateur pioche.
		 *
		 */
		void tourOrdi();
};


#endif /* SRC_JEUDOMINO_HPP_ */
