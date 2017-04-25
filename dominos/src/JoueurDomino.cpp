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
	listeDominos=new vector<Domino>();
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
	cout << "Vous avez decide de jouer, entrez votre pseudo :" << endl;
	cin >> id;
	setPseudo(id);
}

void JoueurDomino::distribuerDominos(Pioche p){
	Domino d(0,0);
	for(int i;i<7;++i)
	{
		d=p.retirerDominoPioche();
		ajouterDominoMain(d);
		nbDominosRestants++;
	}

}

void JoueurDomino::deposerDomino() {//pas fait

}
void JoueurDomino::retirerDominoMain(Domino d){//pas fait

	nbDominosRestants--;
}
void JoueurDomino::piocher(Pioche p){

	Domino d=p.retirerDominoPioche();
	ajouterDominoMain(d);
	nbDominosRestants++;
}

void JoueurDomino::ajouterDominoMain(Domino d){
	listeDominos->push_back(d);
	nbDominosRestants++;
}

bool JoueurDomino::doubleExiste(){
	bool a="False";
	int i=0;
	while (!a && i<nbDominosRestants)
	{
		i++;
		if (listeDominos->at(i).getValInf()==listeDominos->at(i).getValSup())
		a="True";
	}
			return a;
}

Domino JoueurDomino::plusGrandDouble(){
	Domino d(-1,-1);

	for (int i; i<nbDominosRestants; ++i)
	{
		if (listeDominos->at(i).getValInf()==listeDominos->at(i).getValSup() && listeDominos->at(i).getValInf()>d.getValInf())
		{
			d.setValInf(listeDominos->at(i).getValInf());
			d.setValSup(listeDominos->at(i).getValSup());
		}
	}
	return d;
}
