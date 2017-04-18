/*
 * JoueurDomino.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: lguillard
 */

#include "JoueurDomino.hpp"
#include "Pioche.hpp"
#include "Domino.hpp"

using namespace std;

JoueurDomino::JoueurDomino(){
	pseudo="null";
	main=false;
	nbDominosRestants=0;
	gagne=false;
	listeDominos=new vector<Domino>();;
}


string JoueurDomino::getPseudo() {
	return pseudo;
}

void JoueurDomino::setPseudo(string p) {
	pseudo=p;
}

bool JoueurDomino::getMain() {
	return main;
}

void JoueurDomino::setMain(bool m) {
	main=m;
}

int JoueurDomino::getNbDominosRestants() {
	return nbDominosRestants;
}

void JoueurDomino::setNbDominosRestants(int n) {
	nbDominosRestants=n;
}

bool JoueurDomino::getGagne() {
	return gagne;
}

void JoueurDomino::setGagne(bool g) {
	gagne=g;
}

void JoueurDomino::saisirPseudo() {
	string id;
	cout << "Vous avez décidé de jouer, entrez votre pseudo :" << endl;
	cin >> id;
	setPseudo(id);
}

void JoueurDomino::distribuerDominos(Pioche p){

}

void JoueurDomino::deposerDomino() {

}
void JoueurDomino::retirerDominoMain(Domino d){

}
void JoueurDomino::piocher(){

}
void JoueurDomino::ajouterDominoMain(Domino d){

}

bool JoueurDomino::doubleExiste(){
	bool a="True";
			return a;
}

Domino JoueurDomino::plusGrandDouble(){
	Domino d(0,0);
	return d;
}

