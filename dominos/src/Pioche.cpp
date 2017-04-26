/*
 * Pioche.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: jlevacher
 */

#include "Pioche.hpp"
#include "Domino.hpp"
#include "cstdlib"
#include "ctime"

int Pioche::nbDominos = 28;

Pioche::Pioche(){
	dominosPioche = new vector<Domino>();

	// On cr�e la pioche en cr�ant tous les dominos
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

int Pioche::getNbDominos(){
	return nbDominos;
}

void Pioche::setNbDominos(int nb){
	nbDominos = nb;
}

vector<Domino>* Pioche::getDominosPioche(){
	return dominosPioche;
}

Domino Pioche::retirerDominoPioche(){
	//Permet d'avoir un nombre aléatoire différent à chaque fois
	//sinon indice = 15 à chaque fois
	srand (time(NULL));
	//Renvoie un entier compris entre 0 et nbDominos-1
	int indice = rand() % nbDominos;

	Domino dominoRetire = dominosPioche->at(indice);

	dominosPioche->erase(dominosPioche->begin()+indice);

	nbDominos--;

	return dominoRetire;
}
