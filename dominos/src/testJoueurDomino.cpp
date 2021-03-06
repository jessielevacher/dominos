/*
 * testJoueurDomino.cpp
 *
 *  Created on: 18 avr. 2017
 *      Author: L�a
 */

#include "JoueurDomino.hpp"

void testSetPseudo()
{
	JoueurDomino j;
	string ok="lea";
	j.setPseudo(ok);

	string p=j.getPseudo();

		cout << " nom du joueur: " << p << endl;

}

void testajouterDominoMain()
{
	JoueurDomino j;
	cout << " nb dominos du joueur : " << j.getNbDominosRestants() << endl;

	Domino d1(5,4);
	j.ajouterDominoMain(d1);

	cout << " 1er domino : " << j.getListeDominos()->at(0)<< endl;
	cout << " nb dominos du joueur : " << j.getNbDominosRestants() << endl;

}

void testdoubleExist()
{
	JoueurDomino j;
int a;
//Doit �tre faux
	Domino d1(5,4);
	j.ajouterDominoMain(d1);

		d1.setValInf(3);
		j.ajouterDominoMain(d1);

		if (j.doubleExiste())
			 a=0;
		else
			 a=4;

		cout << " il y a un double : " << a << endl;

//Doit �tre vrai
	d1.setValInf(4);
	j.ajouterDominoMain(d1);

	if (j.doubleExiste())
				 a=0;
			else
				 a=4;

	cout << " il y a un double : " << a << endl;
}


void testplusGrandDouble()
{
	JoueurDomino j;
//On lui cr�e un jeu avec un unique double (0,0)
	Domino d(-2,-2);
	Domino d1(5,0);
		j.ajouterDominoMain(d1);

			d1.setValInf(0);
			j.ajouterDominoMain(d1);

//Doit �tre (0,0)

			d=j.plusGrandDouble();
			cout << " plus grand double: " << d.getValInf() << d.getValSup() << endl;

//Doit �tre (5,5)
			//On ajoute 2 dominos dont 1 double (5,5)
	d1.setValSup(5);
	j.ajouterDominoMain(d1);

	d1.setValInf(5);
		j.ajouterDominoMain(d1);

		d=j.plusGrandDouble();
		cout << " plus grand double: " << d.getValInf() << d.getValSup() << endl;

	//Doit �tre (5,5)
//on ajoute un double (3,3)
		d1.setValSup(3);
		d1.setValInf(3);
		j.ajouterDominoMain(d1);

		d=j.plusGrandDouble();
		cout << " plus grand double: " << d.getValInf() << d.getValSup() << endl;

}

void testdistribuerdomino()
{
	Pioche p;
	JoueurDomino j;
	cout << " nb dominos du joueur : " << j.getNbDominosRestants() << endl;


	j.distribuerDominos(p);

	cout << " dominos du joueur " << endl;
		for (int i=0;i<7;i++)
		cout << j.getListeDominos()->at(i) <<endl;

	cout << " nb dominos du joueur : " << j.getNbDominosRestants() << endl;

}

void testafficherMain()
{
	Domino d(1,2);
	JoueurDomino j;

	j.ajouterDominoMain(d);
	d.setValInf(5);
	j.ajouterDominoMain(d);
	d.setValSup(3);
	j.ajouterDominoMain(d);

	j.afficherMain();
}


/*int main()
{

	//testSetPseudo();
	//testajouterDominoMain();
	//testdoubleExist();
	//testplusGrandDouble();
	//testdistribuerdomino();
	testafficherMain();
		return 0;
}
*/


