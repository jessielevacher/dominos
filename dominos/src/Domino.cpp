/*
 * Domino.cpp
 *
 *  Created on: 11 avr. 2017
 *      Author: lmanneheut
 */

/*!
 * \file Domino.cpp
 * \brief Domino
 * \author {Léa Manneheut, Jessie Levacher}
 */

#include "Domino.hpp"
#include <string>

/*!
*  \brief Constructeur
*
*  Constructeur de la classe Domino
*
*  \param Valeur inférieure présente sur le domino
*  \param Valeur supérieure présente sur le domino
*
*/
Domino::Domino(const int vI,const int vS){ //constructeur

	valInf=vI;
	valSup=vS;

}

/*!
 * \brief Permet d'accéder à la valeur inférieure du domino
 *
 * \return la valeur inférieure du domino
 */
int Domino::getValInf() const{
	return valInf;
}

/*!
 * \brief Permet de modifier la valeur inférieure du domino
 *
 * \param nouvelle valeur inférieure du domino
 */
void Domino::setValInf(const int vI) {
	valInf=vI;
}

/*!
 * \brief Permet d'accéder à la valeur supérieure du domino
 *
 * \return la valeur supérieure du domino
 */
int Domino::getValSup() const{
	return valSup;
}

/*!
 * \brief Permet de modifier la valeur supérieure du domino
 *
 * \param nouvelle valeur supérieure du domino
 */
void Domino::setValSup(const int vS) {
	valSup=vS;
}

/*!
 * \brief Permet d'afficher le domino sous la forme [nb1;nb2]
 */
ostream& operator<<(ostream& os, const Domino& d) {
	os << "[" << d.valInf << ";" << d.valSup << "]";
	return os;
}


