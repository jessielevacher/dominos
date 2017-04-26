/*
 * Domino.cpp
 *
 *  Created on: 11 avr. 2017
 *      Author: lmanneheut
 */


#include "Domino.hpp"
#include <string>

Domino::Domino(const int vI,const int vS){ //constructeur

	valInf=vI;
	valSup=vS;

}

int Domino::getValInf() const{
	return valInf;
}

void Domino::setValInf(const int vI) {
	valInf=vI;
}

int Domino::getValSup() const{
	return valSup;
}

void Domino::setValSup(const int vS) {
	valSup=vS;
}

ostream& operator<<(ostream& os, const Domino& d) {
	os << "[" << d.valInf << ";" << d.valSup << "]";
	return os;
}


