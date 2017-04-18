/*
 * testsClasseDomino.cpp
 *
 *  Created on: 16 avr. 2017
 *      Author: Léa
 */

#include "Domino.hpp"
#include <iostream>
using namespace std;

void testConstructeurDomino() //test le constructeur de la classe domino et les méthodes getValInf et GetValSup
{
	Domino a(0,6);
	int vInf=a.getValInf();
	int vSup=a.getValSup();
	cout << " valeur inférieure du domino : " << vInf << endl;
	cout << " valeur supérieure du domino : " << vSup << endl;
}


void testSet()
{
	Domino a(0,6);

	a.setValInf(5);
	a.setValSup(7);
	int vInf=a.getValInf();
	int vSup=a.getValSup();
		cout << " valeur inférieure du domino : " << vInf << endl;
		cout << " valeur supérieure du domino : " << vSup << endl;
}


/*int main()
{
	//testConstructeurDomino();
	testSet();
	return 0;
}*/



