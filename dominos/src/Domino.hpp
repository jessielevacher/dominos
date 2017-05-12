/*
 * Domino.hpp
 *
 *  Created on: 11 avr. 2017
 *      Author: lmanneheut
 */

#ifndef DOMINO_HPP_
#define DOMINO_HPP_

/*!
 * \file Domino.hpp
 * \brief Domino
 * \author {Léa Manneheut, Jessie Levacher}
 */

#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

/*!
 * \class Domino
 * \brief Classe représentant un domino
 *
 *  La classe gère les dominos
 */

class Domino{
	private:
		int valInf; /*!< Valeur inférieure du domino*/
		int valSup; /*!< Valeur supérieure du domino*/

	public:
		/*!
		*  \brief Constructeur
		*
		*  Constructeur de la classe Domino
		*
		*  \param vI : Valeur inférieure présente sur le domino
		*  \param vS : Valeur supérieure présente sur le domino
		*
		*/
		Domino(const int,const int); //const = le paramètre du constructeur ne sera pas modifié

		/*!
		 * \brief Permet d'accéder à la valeur inférieure du domino
		 *
		 * \return la valeur inférieure du domino
		 */
		int getValInf() const;

		/*!
		 * \brief Permet de modifier la valeur inférieure du domino
		 *
		 * \param vI : nouvelle valeur inférieure du domino
		 */
		void setValInf(const int);

		/*!
		 * \brief Permet d'accéder à la valeur supérieure du domino
		 *
		 * \return la valeur supérieure du domino
		 */
		int getValSup() const;

		/*!
		 * \brief Permet de modifier la valeur supérieure du domino
		 *
		 * \param vS : nouvelle valeur supérieure du domino
		 */
		void setValSup(const int);

		/*!
		 * \brief Permet d'afficher le domino sous la forme [nb1;nb2]
		 */
		friend ostream& operator<<(ostream&, const Domino&);
};




#endif /* DOMINO_HPP_ */
