/*
 * JoueurDomino.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: lguillard
 */

#ifndef SRC_JOUEURDOMINO_HPP_
#define SRC_JOUEURDOMINO_HPP_

/*!
 * \file JoueurDomino.hpp
 * \brief Joueur du jeu domino
 * \author {Laetitia Guillard, Léa Manneheut}
 */

#include <string>
#include <vector>
#include "Pioche.hpp"
#include "Domino.hpp"
#include "Plateau.hpp"

using namespace std;

/*!
 * \class JoueurDomino
 * \brief Classe représentant les joueurs du jeu domino
 *
 *  La classe gère les joueurs du jeu Domino
 */

class JoueurDomino{

private :
	string pseudo; /*!< Pseudo du joueur*/
	bool main; /*!< Représente la main du joueur*/
	int nbDominosRestants; /*!< Nombre de domino restant dans le jeu du joueur*/
	bool gagne; /*!< Représente la gagne du joueur*/
	vector<Domino>* listeDominos; /*!< Liste des dominos du joueur*/

public :
	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe JoueurDomino.
	*
	*/
	JoueurDomino();

	/*!
	 * \brief Permet d'accéder au pseudo du joueur
	 *
	 * \return le pseudo du joueur
	 */
	string getPseudo();

	/*!
	 * \brief Permet de modifier le pseudo du joueur
	 *
	 * \param p : pseudo du joueur
	 *
	 */
	void setPseudo(string);

	/*!
	 * \brief Permet de savoir si c'est au joueur de jouer
	 *
	 * \return vrai si c'est au joueur de jouer, faux sinon
	 *
	 */
	bool getMain();

	/*!
	 * \brief Permet de modifier la main du joueur
	 *
	 * La main du joueur correspond au moment où il joue : elle vaut vrai si c'est au joueur de jouer, faux sinon.
	 *
	 * \param booléen
	 *
	 */
	void setMain(bool);

	/*!
	 * \brief Permet de donner le nombre de dominos restants du joueur
	 *
	 * \return m : le nombre de dominos restants dans la liste des dominos du joueur
	 *
	 */
	int getNbDominosRestants();

	/*!
	 * \brief Permet de modifier le nombre de dominos restants du joueur
	 *
	 * \param n : le nouveau nombre de dominos restants
	 *
	 */
	void setNbDominosRestants(int);

	/*!
	 * \brief Permet de savoir si le joueur a gagné
	 *
	 * \return vrai si le joueur a gagne, faux sinon
	 *
	 */
	bool getGagne();

	/*!
	 * \brief Permet de modifier la "gagne" du joueur
	 *
	 * La "gagne" apparait seulement à la fin du jeu pour savoir qui a gagné
	 *
	 * \param g : booléen qui vaut vrai si le joueur gagne, faux sinon
	 *
	 */
	void setGagne(bool);

	/*!
	 * \brief Permet de donner la liste des dominos du joueur
	 *
	 * \return la liste des dominos du joueur
	 *
	 */
	vector<Domino>* getListeDominos();

	/*!
	 * \brief Permet d'ajouter un domino en fin de liste des dominos du joueur
	 *
	 * \param d : le domino à ajouter dans la liste
	 *
	 */
	void setBackListeDominos(const Domino);

	/*!
	 * \brief Permet de modifier le pseudo du joueur
	 *
	 * La modification du pseudo se fait aprés avoir demandé au joueur d'entrer son pseudo au clavier
	 *
	 */
	void saisirPseudo();

	/*!
	 * \brief Permet de distribuer les dominos au joueur
	 *
	 * On retire 7 dominos de la pioche pour les ajouter dans la liste des dominos du joueur
	 *
	 * \param p : la pioche du jeu
	 *
	 */
	void distribuerDominos(Pioche);

	/*!
	 * \brief Permet de poser sur le plateau un domino
	 *
	 * Après avoir demandé au joueur quel domino il voulait poser, on retire le domino de la liste des dominos du joueur et on l'ajoute � la liste des dominos du plateau
	 *
	 * \param plat : le plateau de jeu
	 * \param p : la pioche
	 *
	 * \return le plateau avec le nouveau domino
	 *
	 */
	Plateau deposerDomino(Plateau, Pioche);

	/*!
	 * \brief Permet de retirer le domino à poser de la liste des dominos du joueur
	 *
	 * Commence par chercher le domino à poser dans la liste des dominos du joueur, puis le supprime.
	 * Met à jour le nombre de dominos restants du joueur
	 *
	 * \param d : le domino à retirer de la liste des dominos du joueur
	 *
	 */
	void retirerDominoMain(Domino);

	/*!
	 * \brief Permet de piocher un domino dans la pioche du jeu
	 *
	 * Commence par retirer le domino de la pioche puis l'ajoute dans la liste des dominos du joueur
	 *
	 * \param p : la pioche du jeu
	 *
	 */
	void piocher(Pioche);

	/*!
	 * \brief Permet d'ajouter un domino dans la liste des dominos du joueur
	 *
	 * Ajoute le domino à la liste des dominos du joueur et met à jour le nombre de dominos restants
	 *
	 * \param d : le domino à ajouter
	 *
	 */
	void ajouterDominoMain(Domino);

	/*!
	 * \brief Permet de vérifier que le domino à poser fait bien partie de la liste des dominos du joueur
	 *
	 * On regarde si dans la liste des dominos du joueur, le domino à poser en fait partie
	 *
	 * \param le domino à poser sur le plateau
	 *
	 * \return vrai si le domino fait partie de la liste des dominos du joueur, faux sinon
	 *
	 */
	bool verifierDominoMain(Domino);

	/*!
	 * \brief Permet de savoir si il existe un double dans la liste des dominos du joueur
	 *
	 * \return vrai si il y a au moins un double dans la liste des dominos, faux sinon
	 *
	 */
	bool doubleExiste();

	/*!
	 * \brief Permet de choisir le plus grand double présent dans la liste des dominos du joueur
	 *
	 * \return le plus grand double présent dans la liste des dominos du joueur
	 *
	 */
	Domino plusGrandDouble();

	/*!
	 * \brief Permet d'afficher les dominos présents dans la liste des dominos du joueur
	 *
	 */
	void afficherMain();
};


#endif /* SRC_JOUEURDOMINO_HPP_ */
