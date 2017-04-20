/*
 * testPioche.cpp
 *
 *  Created on: 18 avr. 2017
 *      Author: L�a
 */

#include "Pioche.hpp"
#include "Domino.hpp"

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

void testPioche() //test le constructeur de JeuDomino
{
	Pioche p;

	//affiche tous les éléments de la pioche
	for (int i=0; i < p.getDominosPioche()->size(); i=i+1) {
		cout << "[" << p.getDominosPioche()->at(i).getValInf() << ";" << p.getDominosPioche()->at(i).getValSup() << "]" << endl;
	}

	//d représente le domino supprimé de la pioche
	Domino d = p.retirerDominoPioche();
	cout << "[" << d.getValInf() << ";" << d.getValSup() << "]" << endl;

	//affiche tous les éléments de la pioche après avoir enlevé un élément
	for (int i=0; i < p.getDominosPioche()->size(); i=i+1) {
		cout << "[" << p.getDominosPioche()->at(i).getValInf() << ";" << p.getDominosPioche()->at(i).getValSup() << "]" << endl;
	}

}

/*int main()
{
	testPioche();
	return 0;
}*/

