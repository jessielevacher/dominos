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
 * \file JoueurDomino.cpp
 * \brief Joueur domino
 * \author {L�a Manneheut, La�titia Guillard}
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
 * \brief Permet d'acc�der au pseudo du joueur
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
 * \return vrai si c'est au joueur de jouer, faux sinon
 *
 */
bool JoueurDomino::getMain() {
	return main;
}

/*!
 * \brief Permet de modifier la main du joueur
 *
 * La main du joueur correspond au moment o� il joue : elle vaut vrai si c'est au joueur de jouer, faux sinon.
 *
 * \param bool�en
 *
 */
void JoueurDomino::setMain(bool m) {
	main=m;
}

/*!
 * \brief Permet de donner le nombre de dominos restants du joueur
 *
 * \return le nombre de dominos restants dans la liste des dominos du joueur
 *
 */
int JoueurDomino::getNbDominosRestants() {
	return nbDominosRestants;
}

/*!
 * \brief Permet de modifier le nombre de dominos restants du joueur
 *
 * \param le nouveau nombre de dominos restants
 *
 */
void JoueurDomino::setNbDominosRestants(int n) {
	nbDominosRestants=n;
}

/*!
 * \brief Permet de savoir si le joueur a gagn�
 *
 * \return vrai si le joueur a gagne, faux sinon
 *
 */
bool JoueurDomino::getGagne() {
	return gagne;
}

/*!
 * \brief Permet de modifier la "gagne" du joueur
 *
 * La "gagne" apparait seulement � la fin du jeu pour savoir qui a gagn�
 *
 * \param bool�en qui vaut vrai si le joueur gagne, faux sinon
 *
 */
void JoueurDomino::setGagne(bool g) {
	gagne=g;
}

/*!
 * \brief Permet de donner la liste des dominos du joueur
 *
 * \return la liste des dominos du joueur
 *
 */
vector<Domino>* JoueurDomino::getListeDominos(){
	return listeDominos;
}

/*!
 * \brief Permet d'ajouter un domino en fin de liste des dominos du joueur
 *
 * \param le domino � ajouter dans la liste
 *
 */
void JoueurDomino::setBackListeDominos(const Domino d){
	 listeDominos->push_back(d);

}

/*!
 * \brief Permet de modifier le pseudo du joueur
 *
 * La modification du pseudo se fait apr�s avoir demand� au joueur d'entr�e son pseudo au clavier
 *
 */
void JoueurDomino::saisirPseudo() {
	string id;
	cout << "Vous avez d�cid� de jouer, entrez votre pseudo :" << endl;
	cin >> id;
	setPseudo(id);
}

/*!
 * \brief Permet de distribuer les dominos au joueur
 *
 * On retire 7 dominos de la pioche pour les ajouter dans la liste des dominos du joueur
 *
 * \param la pioche du jeu
 *
 */
void JoueurDomino::distribuerDominos(Pioche p){
	Domino d(0,0);
	for(int i=0;i<7;++i)
	{
		d=p.retirerDominoPioche();
		ajouterDominoMain(d);
	}

}

/*!
 * \brief Permet de poser sur le plateau un domino
 *
 * Apr�s avoir demand� au joueur quel domino il voulait poser, on retire le domino de la liste des dominos du joueur et on l'ajoute � la liste des dominos du plateau
 *
 * \param le plateau de jeu et la pioche
 *
 * \return le plateau avec le nouveau domino
 *
 */
Plateau JoueurDomino::deposerDomino(Plateau plat, Pioche p) {
	int vi, vs, jonc;
	cout << "Quel domino souhaiter vous poser ?" << endl;
	cout << "ValInf : ";
	cin >> vi;
	cout << "ValSup : ";
	cin >> vs;
	cout << "Cot� pour la jonction :";
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

/*!
 * \brief Permet de v�rifier que le domino � poser fait bien partie de la liste des dominos du joueur
 *
 * On regarde si dans la liste des dominos du joueur, le domino � poser en fait partie
 *
 * \param le domino � poser sur le plateau
 *
 * \return vrai si le domino fait partie de la liste des dominos du joueur, faux sinon
 *
 */
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

/*!
 * \brief Permet de retirer le domino � poser de la liste des dominos du joueur
 *
 * Commence par chercher le domino � poser dans la liste des dominos du joueur, puis le supprime.
 * Met � jour le nombre de dominos restants du joueur
 *
 * \param le domino � retirer de la liste des dominos du joueur
 *
 */
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

/*!
 * \brief Permet de piocher un domino dans la pioche du jeu
 *
 * Commence par retirer le domino de la pioche puis l'ajoute dans la liste des dominos du joueur
 *
 * \param la pioche du jeu
 *
 */
void JoueurDomino::piocher(Pioche p){

	Domino d=p.retirerDominoPioche();
	ajouterDominoMain(d);
}

/*!
 * \brief Permet d'ajouter un domino dans la liste des dominos du joueur
 *
 * Ajoute le domino � la liste des dominos du joueur et met � jour le nombre de dominos restants
 *
 * \param le domino � ajouter
 *
 */
void JoueurDomino::ajouterDominoMain(Domino d){
	listeDominos->push_back(d);
	nbDominosRestants++;
}

/*!
 * \brief Permet de savoir si il existe un double dans la liste des dominos du joueur
 *
 * \return vrai si il y a au moins un double dans la liste des dominos, faux sinon
 *
 */
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

/*!
 * \brief Permet de choisir le plus grand double pr�sent dans la liste des dominos du joueur
 *
 * \return le plus grand double pr�sent dans la liste des dominos du joueur
 *
 */
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

/*!
 * \brief Permet d'afficher les dominos pr�sents dans la liste des dominos du joueur
 *
 */
void JoueurDomino::afficherMain()
{
	for (int i=0;i<nbDominosRestants; ++i)
		{ cout << listeDominos->at(i);

		}
}
