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

	/*//affiche tous les éléments de la pioche
	for (int i=0; i < p.getDominosPioche()->size(); i=i+1) {
		cout << p.getDominosPioche()->at(i) << endl;
	}

	//affiche le domino supprimé de la pioche
	cout << p.retirerDominoPioche() << endl;

	//affiche tous les éléments de la pioche après avoir enlevé un élément
	for (int i=0; i < p.getDominosPioche()->size(); i=i+1) {
		cout << p.getDominosPioche()->at(i) << endl;
	}
	*/

//v�rifions le cas o� il ne reste qu'un domino dans la pioche

/*	for (int i=0; i<27;i++)
	{
		p.retirerDominoPioche();
	}

	cout << p.getDominosPioche()->size() << endl; //ici il doit rester 1 domino dans la pioche

	for (int i=0; i < p.getDominosPioche()->size(); i=i+1) {
			cout << p.getDominosPioche()->at(i) << endl;
		}

	p.retirerDominoPioche();//ici il ne reste bien qu'un domino dans la pioche

	cout << "il n'y a plus de dominos dans la pioche " << p.getDominosPioche()->size() << endl;

		for (int i=0; i < p.getDominosPioche()->size(); i=i+1) {
				cout << p.getDominosPioche()->at(i) << endl;
			}
*/

//v�rifions le cas o� il ne reste aucun domino dans la pioche

	for (int i=0; i<28;i++)
		{
			p.retirerDominoPioche();
		}

		cout << p.getDominosPioche()->size() << endl; //ici il ne reste bien aucun dans la pioche

		for (int i=0; i < p.getDominosPioche()->size(); i=i+1) {
				cout << p.getDominosPioche()->at(i) << endl;
			}

		p.retirerDominoPioche();

		cout << "nb dominos dans la pioche " << p.getDominosPioche()->size() << endl; //on verifie que la pioche est toujours vide

			for (int i=0; i < p.getDominosPioche()->size(); i=i+1) {
					cout << p.getDominosPioche()->at(i) << endl;
				}
}

int main()
{
	testPioche();
	return 0;
}

