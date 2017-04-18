/*
 * Pioche.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: jlevacher
 */

#include "Pioche.hpp"
#include "Domino.hpp"

int Pioche::nbDominos = 28;

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

int Pioche::getNbDominos(){
	return nbDominos;
}

void Pioche::setNbDominos(int nb){
	nbDominos = nb;
}
