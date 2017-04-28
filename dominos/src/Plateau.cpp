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

vector<Domino>* Plateau::getDominosPlateau(){
	return dominosPlateau;
}

void Plateau::setBackDominosPlateau(const Domino d){
	 dominosPlateau->push_back(d);

}

void Plateau::setBeginDominosPlateau(const Domino d){
	vector<Domino>::iterator iterator = dominosPlateau->begin();

	 dominosPlateau->insert(iterator+(0),d);

}

void Plateau::ajouterDominoPlateau(Domino d, int jonction){//pas fait
	//on regarde si la jonction est avec la valInf du plateau
	if (jonction == getValInf()) {
		//on regarde si la jonction se fait avec la valInf ou valSup du domino a poser
		if (jonction == d.getValInf())
			setValInf(d.getValSup());
		else setValInf(d.getValInf());
		//on ajoute le domino au début du plateau
		cout << "begin" << endl;
		setBeginDominosPlateau(d);
	} else {
		if (jonction == d.getValInf())
			setValSup(d.getValSup());
		else setValSup(d.getValInf());
		//on ajouter le domino à la fin du plateau
		cout << "back" << endl;
		setBackDominosPlateau(d);
	}
}

bool Plateau::verifierCompatiblite(int val){//pas fait
	bool a="True";
	return a;
}



