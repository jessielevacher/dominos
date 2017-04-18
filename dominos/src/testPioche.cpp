/*
 * testPioche.cpp
 *
 *  Created on: 18 avr. 2017
 *      Author: Léa
 */


#include "Pioche.hpp"

void testPioche() //test le constructeur de JeuDomino
{
	Pioche p;

	cout << " 1er domino : " << p.dominosPioche->at(0).getValInf() << endl;
	cout << " 1er domino : " << p.dominosPioche->at(0).getValSup() << endl;
	cout << " 2eme domino : " << p.dominosPioche->at(1).getValInf() << endl;
	cout << " 2emecdomino : " << p.dominosPioche->at(1).getValSup() << endl;
	cout << " 3eme domino : " << p.dominosPioche->at(2).getValInf()  << endl;
	cout << " 3eme domino : " << p.dominosPioche->at(2).getValSup()  << endl;
	cout << " 6eme domino : " << p.dominosPioche->at(5).getValSup()  << endl;
	cout << " 6eme domino : " << p.dominosPioche->at(5).getValInf()  << endl;
	cout << " 7eme domino : " << p.dominosPioche->at(6).getValSup()  << endl;
	cout << " 7eme domino : " << p.dominosPioche->at(6).getValInf()  << endl;
	cout << " 28eme domino : " << p.dominosPioche->at(27).getValSup()  << endl;
	cout << " 28eme domino : " << p.dominosPioche->at(27).getValInf()  << endl;
}

/*int main()
{
	testPioche();
	return 0;
}*/

