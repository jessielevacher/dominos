/*
 * testAffichage.cpp
 *
 */


#include "Domino.hpp"
#include "Plateau.hpp"
#include <iostream>
using namespace std;


void testAffichageDomino()
{
	Domino d(2,1);
	Domino a(1,2);
	cout << "domino (2,1) : "<< d << endl;
	cout << "val inf de d(2,1) "<< d.getValInf()<< endl;
	cout << "val sup de d(2,1) "<< d.getValSup()<< "\n"<<endl;

	cout << "domino (1,2) : "<< a << endl;
	cout << "val inf de a(1,2) "<< a.getValInf()<< endl;
	cout << "val sup de a(1,2) "<< a.getValSup()<< endl;
}


void testafficherPlateau(){
			//On crée un plateau
			Plateau plateau;

			//On crée les dominos
			Domino i(6,6);
			Domino d(6,1);
			Domino a(2,1);
			Domino b(2,4);
			Domino e(1,6);
			Domino c(4,1);

			//On affecte les valInf et valSup
			plateau.setBackDominosPlateau(i);
			plateau.setValInf(6);
			plateau.setValSup(6);

			//On pose les dominos sur le plateau
			plateau.setBeginDominosPlateau(d);
			plateau.setBeginDominosPlateau(a);
			plateau.setBeginDominosPlateau(b);
			plateau.setBackDominosPlateau(e);
			plateau.setBackDominosPlateau(c);

			//On affiche le plateau
			plateau.afficherPlateau();

}

/*int main(){
	//testAffichageDomino();
	testafficherPlateau();
}
*/
