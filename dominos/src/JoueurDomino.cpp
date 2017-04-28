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

vector<Domino>* JoueurDomino::getListeDominos(){
	return listeDominos;
}

void JoueurDomino::setBackListeDominos(const Domino d){
	 listeDominos->push_back(d);

}

void JoueurDomino::saisirPseudo() {
	string id;
	cout << "Vous avez d�cid� de jouer, entrez votre pseudo :" << endl;
	cin >> id;
	setPseudo(id);
}

void JoueurDomino::distribuerDominos(Pioche p){
	Domino d(0,0);
	for(int i=0;i<7;++i)
	{
		d=p.retirerDominoPioche();
		ajouterDominoMain(d);
	}

}

void JoueurDomino::deposerDomino() {
	int vi, vs, jonc;
	cout << "Quel domino souhaiter vous poser ?" << endl;
	cout << "ValSup : ";
	cin >> vs;
	cout << "ValInf : ";
	cin >> vi;
	cout << "Coté pour la jonction :";
	cin >>jonc;

	Domino dominoChanger(vi, vs);

	retirerDominoMain(dominoChanger);

}
void JoueurDomino::retirerDominoMain(Domino d){
	bool arret=false;
	int i=0;
	while (arret!=true && i<nbDominosRestants){
		if (listeDominos->at(i).getValInf()==d.getValInf() && listeDominos->at(i).getValSup()==d.getValSup()) {
			listeDominos->erase(listeDominos->begin()+i);
			arret=true;
		}
		i++;
	}
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
	bool a=false;
	int i=0;
	while (!a && i<nbDominosRestants)
	{
		if (listeDominos->at(i).getValInf()==listeDominos->at(i).getValSup())
		{
		a=true;
		}
		++i;
	}
			return a;
}

Domino JoueurDomino::plusGrandDouble(){
	Domino d(0,0);

	for (int i=0; i<nbDominosRestants; ++i)
	{
		if (listeDominos->at(i).getValInf()==listeDominos->at(i).getValSup() && listeDominos->at(i).getValInf()>d.getValInf())
		{
			d.setValInf(listeDominos->at(i).getValInf());
			d.setValSup(listeDominos->at(i).getValSup());
		}
	}
	return d;
}

