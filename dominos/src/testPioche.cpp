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

void testPioche()
{
	Pioche p;

	//affiche tous les éléments de la pioche
	for (int i=0; i < p.getDominosPioche()->size(); i=i+1) {
		cout << p.getDominosPioche()->at(i) << endl;
	}

	//affiche le domino supprimé de la pioche
	cout << p.retirerDominoPioche() << endl;

	//affiche tous les éléments de la pioche après avoir enlevé un élément
	for (int i=0; i < p.getDominosPioche()->size(); i=i+1) {
		cout << p.getDominosPioche()->at(i) << endl;
	}

}

/*int main()
{
	testPioche();
	return 0;
}*/

