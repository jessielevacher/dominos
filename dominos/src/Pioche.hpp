/*
 * Pioche.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: jlevacher
 */

#include "Domino.hpp"
#include <vector>

#ifndef SRC_PIOCHE_HPP_
#define SRC_PIOCHE_HPP_

using namespace std;

class Pioche{
private:
	static int nbDominos;

public:
	vector<Domino>* dominosPioche;
	Pioche();
	int getNbDominos();
	void setNbDominos(int);
	Domino retirerDominoPioche();
};


#endif /* SRC_PIOCHE_HPP_ */
