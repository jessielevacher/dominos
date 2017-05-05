/*
 * JoueurDomino.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: lguillard
 */

#include "JoueurDomino.hpp"
#include "Pioche.hpp"
#include "Domino.hpp"
#include "Plateau.hpp"

/*!
 * \file Domino.cpp
 * \brief Domino
 * \author {Léa Manneheut, Laëtitia Guillard}
 */

using namespace std;

/*!
*  \brief Constructeur
*
*  Constructeur de la classe JoueurDomino.
*
*/
JoueurDomino::JoueurDomino(){
	pseudo="null";
	main=false;
	nbDominosRestants=0;
	gagne=false;
	listeDominos=new vector<Domino>();;
}

/*!
 * \brief Permet d'accéder au pseudo du joueur
 *
 * \return le pseudo du joueur
 */
string JoueurDomino::getPseudo() {
	return pseudo;
}

/*!
 * \brief Permet de modifier le pseudo du joueur
 *
 * \param pseudo du joueur
 *
 */
void JoueurDomino::setPseudo(string p) {
	pseudo=p;
}

/*!
 * \brief Permet de savoir si c'est au joueur de jouer
 *
 * \return un booléen (vrai si c'est au joueur de jouer, faux sinon)
 *
 */
bool JoueurDomino::getMain() {
	return main;
}

/*!
 * \brief Permet de modifier la main du joueur
 *
 * \param booléen
 *
 */
void JoueurDomino::setMain(bool m) {
	main=m;
}

/*!
 * \brief Permet de donner le nombre de dominos restants du joueur
 *
 * \return le nombre de dominos restants
 *
 */
int JoueurDomino::getNbDominosRestants() {
	return nbDominosRestants;
}


/*!
 * \brief Permet de modifier nombre de dominos restants du joueur
 *
 * \param nombre de dominos
 *
 */
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

Plateau JoueurDomino::deposerDomino(Plateau plat, Pioche p) {
	int vi, vs, jonc;
	cout << "Quel domino souhaiter vous poser ?" << endl;
	cout << "ValInf : ";
	cin >> vi;
	cout << "ValSup : ";
	cin >> vs;
	cout << "Coté pour la jonction :";
	cin >> jonc;

	Domino dominoChanger(vi, vs);

	if (verifierDominoMain(dominoChanger)) {
		if (jonc == vi) {
			if (plat.verifierCompatibilite(dominoChanger.getValInf())) {
				retirerDominoMain(dominoChanger);
				plat.ajouterDominoPlateau(dominoChanger, dominoChanger.getValInf());
			} else
				piocher(p);
		}
		else {
				if (plat.verifierCompatibilite(dominoChanger.getValSup())) {
					retirerDominoMain(dominoChanger);
					plat.ajouterDominoPlateau(dominoChanger, dominoChanger.getValSup());
				} else
					piocher(p);
		}
	} else piocher(p);

	return plat;
}


bool JoueurDomino::verifierDominoMain(Domino d){
	bool arret=false;
	int i=0;
	while (arret!=true && i<nbDominosRestants) {
		if (getListeDominos()->at(i).getValInf()==d.getValInf() && getListeDominos()->at(i).getValSup()==d.getValSup())
			arret=true;
		else i++;
	}
	return arret;
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

void JoueurDomino::afficherMain()
{
	for (int i=0;i<nbDominosRestants; ++i)
		{ cout << listeDominos->at(i);

		}
}

