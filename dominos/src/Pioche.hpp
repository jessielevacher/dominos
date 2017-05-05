/*
 * Pioche.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: jlevacher
 */

#include "Domino.hpp"
#include <vector>

/*!
 * \file Pioche.hpp
 * \brief Pioche de dominos
 * \author {Jessie Levacher, Léa Manneheut}
 */

#ifndef SRC_PIOCHE_HPP_
#define SRC_PIOCHE_HPP_

using namespace std;

/*!
 * \class Pioche
 * \brief Classe représentant la pioche du jeu du domino
 *
 *  La classe gère la pioche de dominos
 */

class Pioche{

private:
	static int nbDominos; /*!< Nombre de dominos présents dans la pioche*/
	vector<Domino>* dominosPioche; /*!< Liste des dominos dans la pioche*/

public:
	/*!
	 *  \brief Constructeur
	 *
	 *  Constructeur de la classe Pioche
	 *
	 */
	Pioche();

	/*!
	 * \brief Permet d'accéder au nombre de dominos
	 *
	 * \return le nombre de dominos
	 */
	int getNbDominos();

	/*!
	 * \brief Permet de modifier le nombre de dominos présent dans la pioche
	 *
	 * \param nouvelle quantité de dominos
	 */
	void setNbDominos(int);

	/*!
	 * \brief Permet d'accéder à la liste des dominos de la pioche
	 *
	 * \return la liste des dominos
	 */
	vector<Domino>* getDominosPioche();

	/*!
	 * \brief Retrait d'un domino de la pioche
	 *
	 * \return le domino pioché
	 */
	Domino retirerDominoPioche();
};


#endif /* SRC_PIOCHE_HPP_ */
