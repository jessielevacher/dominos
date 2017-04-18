/*
 * JoueurDomino.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: lguillard
 */

#ifndef SRC_JOUEURDOMINO_HPP_
#define SRC_JOUEURDOMINO_HPP_

#include <string>
#include <vector>
#include "Pioche.hpp"
#include "Domino.hpp"

using namespace std;

class JoueurDomino{

private :
	string pseudo;
	bool main;
	int nbDominosRestants;
	bool gagne;

public :
	vector<Domino>* listeDominos;
	JoueurDomino();
	string getPseudo();
	void setPseudo(string);
	bool getMain();
	void setMain(bool);
	int getNbDominosRestants();
	void setNbDominosRestants(int);
	bool getGagne();
	void setGagne(bool);
	void saisirPseudo();
	void distribuerDominos(Pioche);
	void deposerDomino();
	void retirerDominoMain(Domino);
	void piocher(Pioche);
	void ajouterDominoMain(Domino);

	bool doubleExiste();
	Domino plusGrandDouble();
};



#endif /* SRC_JOUEURDOMINO_HPP_ */
