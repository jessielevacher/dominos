/*
 * Pioche.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: jlevacher
 */

/*!
 * \file Pioche.cpp
 * \brief Pioche de dominos
 * \author {Jessie Levacher, Léa Manneheut}
 */

#include "Pioche.hpp"
#include "Domino.hpp"
#include "cstdlib"
#include "ctime"

int Pioche::nbDominos = 28;

/*!
 *  \brief Constructeur
 *
 *  Constructeur de la classe Pioche
 *
 */
Pioche::Pioche(){
	dominosPioche = new vector<Domino>();

	// On crée la pioche en créant tous les dominos
	for (int i=0; i < 7; i++){
		for (int j=i+1; j < 7; j++){
			Domino d(i,j);
			dominosPioche->push_back(d);
		}
	}
	for (int j=0; j < 7; j++){
				Domino d(j,j);
				dominosPioche->push_back(d);
			}
}

/*!
 * \brief Permet d'accéder au nombre de dominos
 *
 * \return le nombre de dominos
 */
int Pioche::getNbDominos(){
	return nbDominos;
}

/*!
 * \brief Permet de modifier le nombre de dominos présent dans la pioche
 *
 * \param nb : nouvelle quantité de dominos
 */
void Pioche::setNbDominos(int nb){
	nbDominos = nb;
}

/*!
 * \brief Permet d'accéder à la liste des dominos de la pioche
 *
 * \return la liste des dominos
 */
vector<Domino>* Pioche::getDominosPioche(){
	return dominosPioche;
}

/*!
 * \brief Retrait d'un domino de la pioche
 *
 * Cette méthode permet de piocher,
 * c'est-à-dire d'enlever aléatoirement un domino de la pioche,
 * si elle n'est pas vide
 *
 * \return le domino pioché
 */
Domino Pioche::retirerDominoPioche(){

	Domino dominoRetire(0,0);

	if (nbDominos==1){
		dominoRetire = dominosPioche->at(0);
		dominosPioche->erase(dominosPioche->begin());
		nbDominos--;
	}
	else if (nbDominos==0){ //pioche vide on ne fait rien
		cout <<"La pioche est vide"<< endl;
	}
	else {
		//Permet d'avoir un nombre aléatoire différent à chaque fois
		srand (time(NULL));
		//Renvoie un entier compris entre 0 et nbDominos-1
		int indice = rand() % nbDominos;

		dominoRetire = dominosPioche->at(indice);

		dominosPioche->erase(dominosPioche->begin()+indice);
		nbDominos--;
	}
	return dominoRetire;
}
