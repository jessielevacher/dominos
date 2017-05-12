/*
 * Pioche.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: jlevacher
 */

#ifndef SRC_PIOCHE_HPP_
#define SRC_PIOCHE_HPP_

/*!
 * \file Pioche.hpp
 * \brief Pioche de dominos
 * \author {Jessie Levacher, Léa Manneheut}
 */

#include "Domino.hpp"
#include <vector>

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
	 * \param nb : nouvelle quantité de dominos
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
	 * Cette méthode permet de piocher,
	 * c'est-à-dire d'enlever aléatoirement un domino de la pioche,
	 * si elle n'est pas vide
	 *
	 * \return le domino pioché
	 */
	Domino retirerDominoPioche();
};


#endif /* SRC_PIOCHE_HPP_ */
