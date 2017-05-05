/*
 * main.cpp
 *
 *  Created on: 5 mai 2017
 *      Author: lmanneheut
 */

#include "JeuDomino.hpp"

int main()
{
	JeuDomino jeu; //On cr�e un jeu

	while (!jeu.verifierFinJeu())
	{
		jeu.jouerUnTour();
	}
	jeu.finJeu();
}


