/*
 * JoueurDomino.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: lguillard
 */

#ifndef SRC_JOUEURDOMINO_HPP_
#define SRC_JOUEURDOMINO_HPP_

#include <string>

using namespace std;

class JoueurDomino {

private :
	string pseudo;
	bool main;
	int nbDominosRestants;
	bool gagne;

public :
	JoueurDomino();
	string getPseudo();
	void setPseudo(string p);
	bool getMain();
	void setMain(bool m);
	int getNbDominosRestants();
	void setNbDominosRestants(int n);
	bool getGagne();
	void setGagne(bool g);
	void saisirPseudo();
	void distribuerDominos(Pioche p);
	void deposerDomino();
	void retirerDominoMain(Domino d);
	void piocher();
	void ajouterDominoMain(Domino d);
};



#endif /* SRC_JOUEURDOMINO_HPP_ */
