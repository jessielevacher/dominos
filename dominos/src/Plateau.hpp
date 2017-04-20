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
public :
	vector<Domino>* dominosPlateau;
	Plateau();
	int getValInf() const;
	void setValInf(int);
	int getValSup();
	void setValSup(int);
	void ajouterDominoPlateau(Domino, int);
	void modifierBorne(int);
	bool verifierCompatiblite(int);
};

#endif /* PLATEAU_HPP_ */
