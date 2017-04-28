/*
 * Plateau.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: mthiam
 */

#ifndef PLATEAU_HPP_
#define PLATEAU_HPP_

#include <vector>
#include <string>
#include "Domino.hpp"
using namespace std;

class Plateau{
private :
	int valInf;
	int valSup;
	vector<Domino>* dominosPlateau;

public :
	Plateau();
	int getValInf() const;
	void setValInf(int);
	int getValSup();
	void setValSup(int);
	vector<Domino>* getDominosPlateau();
	void setBackDominosPlateau(const Domino);
	void setBeginDominosPlateau(const Domino);
	void ajouterDominoPlateau(Domino, int);
	bool verifierCompatibilite(int);
	void afficherPlateau();
};

#endif /* PLATEAU_HPP_ */
