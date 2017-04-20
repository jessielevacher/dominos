/*
 * Plateau.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: mthiam
 */


#include "Plateau.hpp"
#include <vector>

int Plateau::getValInf() const{
	return valInf;
}

/*Plateau::Plateau(Domino dom){
	valInf=dom.getValInf();
	valSup=dom.getValSup();
	dominosPlateau=new vector<Domino>();
	dominosPlateau->at(0)=dom;
}*/

Plateau::Plateau(){
	valInf=NULL;
	valSup=NULL;
	dominosPlateau=new vector<Domino>();

}

void Plateau::setValInf(int vI){
	valInf=vI;
}

int Plateau::getValSup(){
	return valSup;
}

void Plateau::setValSup(int vS){
	valSup=vS;
}

void Plateau::ajouterDominoPlateau(Domino d, int val){

}

void Plateau::modifierBorne(int val){

}

bool Plateau::verifierCompatiblite(int val){
	bool a="True";
	return a;
}



