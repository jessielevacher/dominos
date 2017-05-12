/*
 * JoueurDomino.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: lguillard
 */

/*!
 * \file Pioche.hpp
 * \brief Joueur du jeu Domino
 * \author {Laetitia Guillard, Léa Manneheut}
 */

#ifndef SRC_JOUEURDOMINO_HPP_
#define SRC_JOUEURDOMINO_HPP_

#include <string>
#include <vector>
#include "Pioche.hpp"
#include "Domino.hpp"
#include "Plateau.hpp"

using namespace std;

/*!
 * \class JoueurDomino
 * \brief Classe représentant les joueurs du jeu Domino
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
	 * \brief Permet d'acc�der au pseudo du joueur
	 *
	 * \return le pseudo du joueur
	 */
	string getPseudo();

	/*!
	 * \brief Permet de modifier le pseudo du joueur
	 *
	 * \param pseudo du joueur
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
	 * La main du joueur correspond au moment o� il joue : elle vaut vrai si c'est au joueur de jouer, faux sinon.
	 *
	 * \param bool�en
	 *
	 */
	void setMain(bool);

	/*!
	 * \brief Permet de donner le nombre de dominos restants du joueur
	 *
	 * \return le nombre de dominos restants dans la liste des dominos du joueur
	 *
	 */
	int getNbDominosRestants();

	/*!
	 * \brief Permet de modifier le nombre de dominos restants du joueur
	 *
	 * \param le nouveau nombre de dominos restants
	 *
	 */
	void setNbDominosRestants(int);

	/*!
	 * \brief Permet de savoir si le joueur a gagn�
	 *
	 * \return vrai si le joueur a gagne, faux sinon
	 *
	 */
	bool getGagne();

	/*!
	 * \brief Permet de modifier la "gagne" du joueur
	 *
	 * La "gagne" apparait seulement � la fin du jeu pour savoir qui a gagn�
	 *
	 * \param bool�en qui vaut vrai si le joueur gagne, faux sinon
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
	 * \param le domino � ajouter dans la liste
	 *
	 */
	void setBackListeDominos(const Domino);

	/*!
	 * \brief Permet de modifier le pseudo du joueur
	 *
	 * La modification du pseudo se fait apr�s avoir demand� au joueur d'entr�e son pseudo au clavier
	 *
	 */
	void saisirPseudo();

	/*!
	 * \brief Permet de distribuer les dominos au joueur
	 *
	 * On retire 7 dominos de la pioche pour les ajouter dans la liste des dominos du joueur
	 *
	 * \param la pioche du jeu
	 *
	 */
	void distribuerDominos(Pioche);

	/*!
	 * \brief Permet de poser sur le plateau un domino
	 *
	 * Apr�s avoir demand� au joueur quel domino il voulait poser, on retire le domino de la liste des dominos du joueur et on l'ajoute � la liste des dominos du plateau
	 *
	 * \param le plateau de jeu et la pioche
	 *
	 * \return le plateau avec le nouveau domino
	 *
	 */
	Plateau deposerDomino(Plateau, Pioche);

	/*!
	 * \brief Permet de retirer le domino � poser de la liste des dominos du joueur
	 *
	 * Commence par chercher le domino � poser dans la liste des dominos du joueur, puis le supprime.
	 * Met � jour le nombre de dominos restants du joueur
	 *
	 * \param le domino � retirer de la liste des dominos du joueur
	 *
	 */
	void retirerDominoMain(Domino);

	/*!
	 * \brief Permet de piocher un domino dans la pioche du jeu
	 *
	 * Commence par retirer le domino de la pioche puis l'ajoute dans la liste des dominos du joueur
	 *
	 * \param la pioche du jeu
	 *
	 */
	void piocher(Pioche);

	/*!
	 * \brief Permet d'ajouter un domino dans la liste des dominos du joueur
	 *
	 * Ajoute le domino � la liste des dominos du joueur et met � jour le nombre de dominos restants
	 *
	 * \param le domino � ajouter
	 *
	 */
	void ajouterDominoMain(Domino);

	/*!
	 * \brief Permet de v�rifier que le domino � poser fait bien partie de la liste des dominos du joueur
	 *
	 * On regarde si dans la liste des dominos du joueur, le domino � poser en fait partie
	 *
	 * \param le domino � poser sur le plateau
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
	 * \brief Permet de choisir le plus grand double pr�sent dans la liste des dominos du joueur
	 *
	 * \return le plus grand double pr�sent dans la liste des dominos du joueur
	 *
	 */
	Domino plusGrandDouble();

	/*!
	 * \brief Permet d'afficher les dominos pr�sents dans la liste des dominos du joueur
	 *
	 */
	void afficherMain();
};


#endif /* SRC_JOUEURDOMINO_HPP_ */
