/*
 * Pioche.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: jlevacher
 */

#include "Pioche.hpp"

int Pioche::nbDominos = 28;

Pioche::Pioche(){

}

int Pioche::getNbDominos(){
	return nbDominos;
}

void Pioche::setNbDominos(int nb){
	nbDominos = nb;
}


