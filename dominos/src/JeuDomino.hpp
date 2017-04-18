/*
 * JeuDomino.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: lmanneheut
 */

#ifndef SRC_JEUDOMINO_HPP_
#define SRC_JEUDOMINO_HPP_


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

class JeuDomino{
	private:
		JoueurDomino joueur;
		JoueurDomino jOrdi;
		JoueurDomino main;
		Pioche pioche;
		//Plateau plateau;

	public:
		JeuDomino();
		void lancerJeu();
		void poserPion();
		void piocher();
		void verifierFinJeu();
		void jouerUnTour();
		void tourOrdi();
		void attribuerMain();
		JoueurDomino joueurAyantPlusGrandDouble(JoueurDomino, Domino, JoueurDomino, Domino);
		void affichageEcranJoueur();
		void affichageEcranOrdi();
};


#endif /* SRC_JEUDOMINO_HPP_ */
