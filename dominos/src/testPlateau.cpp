/*
 * testPlateau.cpp
 *
 *  Created on: 12 mai 2017
 *      Author: lguillard
 */

#include "JeuDomino.hpp"
#include "Plateau.hpp"
#include <iostream>
using namespace std;

void testDeposerDomino() {

	JeuDomino jeu;

	//on affiche les bornes du plateau
	cout << " bornes du plateau: " << jeu.plateau.getValInf() << "-" << jeu.plateau.getValSup() << endl;

	//on affiche le domino a poser
	cout << " domino déposer sur le plateau en premier: " <<  	jeu.plateau.getDominosPlateau()->at(0)  <<endl;

	//affiche tous les dominos du joueur
	for (int i=0;i<jeu.joueur.getNbDominosRestants();i++)
		cout << jeu.joueur.getListeDominos()->at(i) << endl;

	cout << "--------" << endl;

	//demande au joueur quel domino il souhaite poser, vérifie si c'est possible au quel cas le domino est posé sur le plateau
	//et retiré de la liste de dominos du joueur
	//sinon le joueur se voit un domino ajouter dans sa liste de domino
	jeu.joueur.deposerDomino(jeu.plateau, jeu.pioche);

	//affiche les dominos du joueur sans celui qui vient d'être posé ou avec un autre domino si le joueur s'est trompé
	for (int i=0;i<jeu.joueur.getNbDominosRestants();i++)
			cout << jeu.joueur.getListeDominos()->at(i) << endl;

	cout << "-----------" << endl;

	//affiche les dominos du plateau avec le domino qui vient d'être posé ou pas (si le joueur s'est trompé)
	for (int i=0;i<jeu.plateau.getDominosPlateau()->size();i++)
						cout << jeu.plateau.getDominosPlateau()->at(i) << endl;

}


void testAjouterDominoPlateau() {
	Plateau plat;

	//On affiche les bornes du plateau à la création
	cout << " bornes du plateau: " << plat.getValInf() << "-" << plat.getValSup() << endl;

	//On crée un domino à ajouter au plateau vide
	Domino d(2,5);

	//on ajoute au plateau
	plat.setBackDominosPlateau(d);

	//On modifie les bornes du plateau avec le domino qu'on vient de poser
	plat.setValInf(2);
	plat.setValSup(5);

	//affiche les dominos du plateau
	for (int i=0;i<plat.getDominosPlateau()->size();i++)
			cout << plat.getDominosPlateau()->at(i) << endl;

	//affiche les nouvelles bornes du plateau pour vérifier que valInf et valSup on été modifié
	cout << " bornes du plateau: " << plat.getValInf() << "-" << plat.getValSup() << endl;

	//On crée un nouveau domino qui peut être posé sur le plateau à droite
	Domino d1(1,5);

	cout << "--------" << endl;

	//on ajoute ce domino avec la jonction 5
	plat.ajouterDominoPlateau(d1, 5);

	//on affiche les nouvelles bornes du plateau pour vérifier que la valSup du plateau a bien été modifié
	cout << " bornes du plateau: " << plat.getValInf() << "-" << plat.getValSup() << endl;

	//On crée un autre domino qui peut être posé à droite sur le plateau
	Domino d2(2,6);

	//on ajoute le domino sur le plateau
	plat.ajouterDominoPlateau(d2, 2);

	//on affiche les nouvelles bornes du plateau pour vérifier que la valInf du plateau a bien été modifié
	cout << " bornes du plateau: " << plat.getValInf() << "-" << plat.getValSup() << endl;

	//on affiche les dominos du plateau tous positionnés dans le bon sens et sur le bon coté du plateau
	for (int i=0;i<plat.getDominosPlateau()->size();i++)
					cout << plat.getDominosPlateau()->at(i) << endl;
}

/*int main() {

	testDeposerDomino();
	//testAjouterDominoPlateau();

	return 0;

}*/
