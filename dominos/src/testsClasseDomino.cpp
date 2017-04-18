/*
 * testsClasseDomino.cpp
 *
 *  Created on: 16 avr. 2017
 *      Author: L�a
 */

#include "Domino.hpp"
#include <iostream>
using namespace std;

void testConstructeurDomino() //test le constructeur de la classe domino et les m�thodes getValInf et GetValSup
{
	Domino a(0,6);
	int vInf=a.getValInf();
	int vSup=a.getValSup();
	cout << " valeur inf�rieure du domino : " << vInf << endl;
	cout << " valeur sup�rieure du domino : " << vSup << endl;
}


void testSet()
{
	Domino a(0,6);

	a.setValInf(5);
	a.setValSup(7);
	int vInf=a.getValInf();
	int vSup=a.getValSup();
		cout << " valeur inf�rieure du domino : " << vInf << endl;
		cout << " valeur sup�rieure du domino : " << vSup << endl;
}


/*int main()
{
	//testConstructeurDomino();
	testSet();
	return 0;
}*/



