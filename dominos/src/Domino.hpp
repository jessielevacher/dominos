/*
 * Domino.hpp
 *
 *  Created on: 11 avr. 2017
 *      Author: lmanneheut
 */

#ifndef DOMINO_HPP_
#define DOMINO_HPP_

#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;

class Domino{
	private:
		int valInf;
		int valSup;

	public:
		Domino(const int,const int); //const= le paramètre du constructeur ne sera pas modifié
		int getValInf() const;
		void setValInf(const int);
		int getValSup() const;
		void setValSup(const int);
		string toString() const;
};




#endif /* DOMINO_HPP_ */
