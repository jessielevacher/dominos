/*
 * Domino.cpp
 *
 *  Created on: 11 avr. 2017
 *      Author: lmanneheut
 */


#include "Domino.hpp"

Domino::Domino(const int vI,const int vS){ //constructeur

	valInf=vI;
	valSup=vS;

}

int Domino::getValInf() const{
	return valInf;
}

void Domino::setValInf(const int vI) {
	valSup=vI;
}

int Domino::getValSup() const{
	return valSup;
}

void Domino::setValSup(const int vS) {
	valSup=vS;
}


