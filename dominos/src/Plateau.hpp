/*
 * Plateau.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: {Mareme}
 */

#ifndef PLATEAU_HPP_
#define PLATEAU_HPP_

#include <vector>
#include <string>
#include "Domino.hpp"

using namespace std;

/*!
 * \class Plateau
 *
 * \brief Classe représentant le plateau de jeu
 *
 *  La classe gère le plateau du jeu
 */

class Plateau{
private :
	int valInf; /*!< Valeur inférieure du plateau*/
	int valSup; /*!< Valeur supérieure du plateau*/
	vector<Domino>* dominosPlateau; /*!< Vecteur des dominos posés sur le plateau*/

public :
	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe Plateau
	*
	*/
	Plateau();

	/*!
	* \brief Permet d'accéder à la valeur inférieure du plateau
	*
	* \return la valeur inférieure du plateau
	*/
	int getValInf() const;

	/*!
	* \brief Permet de modifier à la valeur inférieure du plateau
	*
	* \param nouvelle valeur inférieure du plateau
	*/
	void setValInf(int);

	/*!
	* \brief Permet d'accéder à la valeur supérieure du plateau
	*
	* \return la valeur supérieure du plateau
	*/
	int getValSup();

	/*!
	* \brief Permet de modifier à la valeur supérieure du plateau
	*
	* \param nouvelle valeur supérieure du plateau
	*/
	void setValSup(int);

	/*!
	* \brief Permet de récupérer la liste de dominos du plateau
	*
	* \return liste de dominos
	*/
	vector<Domino>* getDominosPlateau();

	/*!
	* \brief Permet de poser un domino à la fin du vecteur de dominos du plateau
	*
	* \param domino à poser
	*/
	void setBackDominosPlateau(const Domino);

	/*!
	* \brief Permet de poser un domino au début du vecteur de dominos du plateau
	*
	* Se positionne au début du vecteur de domino et y insére le domino à ajouter
	*
	* \param domino à poser
	*/
	void setBeginDominosPlateau(const Domino);

	/*!
	* \brief Permet d'ajouter un domino sur le plateau en faisant la jonction avec un côté du domino
	*
	* \param domino à poser
	* \param côté du domino que l'on veut poser
	*/
	void ajouterDominoPlateau(Domino, int);

	/*!
	* \brief Vérifie qu'il est possible de poser le domino choisi suivant le côté choisi
	*
	* \param côté du domino avec lequel on fait la jonction
	*
	* \return vrai si le domino est compatible, faux sinon
	*/
	bool verifierCompatibilite(int);

	/*!
	* \brief Affiche les dominos du plateau sur la console
	*/
	void afficherPlateau();
};

#endif /* PLATEAU_HPP_ */
