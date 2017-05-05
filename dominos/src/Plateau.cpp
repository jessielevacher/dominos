/*
 * Plateau.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: {Mareme}
 */


#include "Plateau.hpp"
#include <vector>


/*Plateau::Plateau(Domino dom){
	valInf=dom.getValInf();
	valSup=dom.getValSup();
	dominosPlateau=new vector<Domino>();
	dominosPlateau->at(0)=dom;
}*/

/*!
*  \brief Constructeur
*
*  Constructeur de la classe Plateau
*
*/
Plateau::Plateau(){
	valInf=NULL;
	valSup=NULL;
	dominosPlateau=new vector<Domino>();

}

/*!
* \brief Permet de modifier à la valeur inférieure du plateau
*
* \param nouvelle valeur inférieure du plateau
*/
void Plateau::setValInf(int vI){
	valInf=vI;
}

/*!
* \brief Permet d'accéder à la valeur inférieure du plateau
*
* \return la valeur inférieure du plateau
*/
int Plateau::getValInf() const{
	return valInf;
}

/*!
* \brief Permet d'accéder à la valeur supérieure du plateau
*
* \return la valeur supérieure du plateau
*/
int Plateau::getValSup(){
	return valSup;
}

/*!
* \brief Permet de modifier à la valeur supérieure du plateau
*
* \param nouvelle valeur supérieure du plateau
*/
void Plateau::setValSup(int vS){
	valSup=vS;
}

/*!
* \brief Permet de poser un domino à la fin du vecteur de dominos du plateau
*
* \param domino à poser
*/
vector<Domino>* Plateau::getDominosPlateau(){
	return dominosPlateau;
}

/*!
* \brief Permet de poser un domino à la fin du vecteur de dominos du plateau
*
* \param domino à poser
*/
void Plateau::setBackDominosPlateau(const Domino d){
	 dominosPlateau->push_back(d);

}

/*!
* \brief Permet de poser un domino au début du vecteur de dominos du plateau
*
*Se positionne au début du vecteur de domino et y insére le domino à ajouter
*
* \param domino à poser
*/
void Plateau::setBeginDominosPlateau(const Domino d){
	vector<Domino>::iterator iterator = dominosPlateau->begin();

	 dominosPlateau->insert(iterator+(0),d);

}

/*!
* \brief Permet d'ajouter un domino sur le plateau en faisant la jonction avec un côté du domino
*
* \param domino à poser
* \param côté du domino que l'on veut poser
*/
void Plateau::ajouterDominoPlateau(Domino d, int jonction){
	//on regarde si la jonction est avec la valInf du plateau
	if (jonction == getValInf()) {
		//on regarde si la jonction se fait avec la valInf ou valSup du domino a poser
		if (jonction == d.getValInf())
			setValInf(d.getValSup());
		else setValInf(d.getValInf());
		//on ajoute le domino au debut du plateau
		setBeginDominosPlateau(d);
	} else {
		if (jonction == d.getValInf())
			setValSup(d.getValSup());
		else setValSup(d.getValInf());
		//on ajouter le domino a� la fin du plateau
		setBackDominosPlateau(d);
	}
}

/*!
* \brief Vérifie qu'il est possible de poser le domino choisi suivant le côté choisi
*
* \param côté du domino avec lequel on fait la jonction
*/
bool Plateau::verifierCompatibilite(int jonction){//v�rifie que la jonction choisie par le joueur est bien compatible avec le plateau actuel

		if (jonction == getValInf())
			return true;
		else if (jonction == getValSup())
			return true;
		else return false;

}

/*!
* \brief Affiche les dominos du plateau sur la console
*
* On parcourt le vecteur de dominos en comparant les dominos deux à deux.
* Si la jonction se fait entre la valeur supérieure du premier domino et la valeur inférieure du deuxieme domino, alors on
* passe aux dominos suivants. Sinon si la jonction se fait entre la valeur supérieure du premier domino et la valeur supérieure
* du deuxieme domino, alors on permute les valeurs inférieure et supérieure du deuxieme domino. Sinon si la jonction se fait
* entre la valeur inférieure du premier domino et la valeur inférieure du deuxieme domino, alors on permutte les valeurs inférieure
* et supérieure du premier domino. Sinon, si la jonction se fait entre la valeur inférieure du premier domino et la valeur
* supérieure du deuxieme domino, on permutte les valeurs inférieure et supérieure des deux dominos.
* Après parcours, on affiche le vecteur de dominos.
*
*/
void Plateau::afficherPlateau(){
	//On va afficher les dominos 2 à 2 en comparant les val inf et les val sup pour ordonner le vecteur de dominos du plateau

	vector<Domino>* temp;
	temp = this->getDominosPlateau();
	int i=0;
	int temporaire;
	int tmp;

	while(i<temp->size()-1)
	{

		if ((temp->at(i).getValSup())==(temp->at(i+1).getValInf())){
			i=i+1;
		} else {
			if (temp->at(i).getValSup() == temp->at(i+1).getValSup()){// on permette les valeurs du deuxieme domino
				temporaire = temp->at(i+1).getValInf();
				temp->at(i+1).setValInf(temp->at(i+1).getValSup());
				temp->at(i+1).setValSup(temporaire);
			} else {
				if((temp->at(i).getValInf())==(temp->at(i+1).getValInf())) {
					tmp = temp->at(i).getValSup();
					temp->at(i).setValSup(temp->at(i).getValInf());
					temp->at(i).setValInf(tmp);
				} else {
					if (temp->at(i).getValInf()==temp->at(i+1).getValSup()) {// on permutte les valeurs des deux dominos
						tmp = temp->at(i).getValSup();
						temp->at(i).setValSup(temp->at(i).getValInf());
						temp->at(i).setValInf(tmp);
						int tmp = temp->at(i+1).getValSup();
						temp->at(i+1).setValSup(temp->at(i+1).getValInf());
						temp->at(i+1).setValInf(tmp);
					}
				}
				}
			}
	}

	cout <<"Le plateau : \n"<<endl;
	//cout<< "Tête de la file de domino --- ";
	for (int j=0; j<temp->size();j=j+1){
		cout << temp->at(j);
	}
	//cout<<" --- Queue de la file de domino";


}



