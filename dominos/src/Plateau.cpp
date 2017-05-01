/*
 * Plateau.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: mthiam
 */


#include "Plateau.hpp"
#include <vector>


/*Plateau::Plateau(Domino dom){
	valInf=dom.getValInf();
	valSup=dom.getValSup();
	dominosPlateau=new vector<Domino>();
	dominosPlateau->at(0)=dom;
}*/

Plateau::Plateau(){
	valInf=NULL;
	valSup=NULL;
	dominosPlateau=new vector<Domino>();

}

void Plateau::setValInf(int vI){
	valInf=vI;
}

int Plateau::getValInf() const{
	return valInf;
}

int Plateau::getValSup(){
	return valSup;
}

void Plateau::setValSup(int vS){
	valSup=vS;
}

vector<Domino>* Plateau::getDominosPlateau(){
	return dominosPlateau;
}

void Plateau::setBackDominosPlateau(const Domino d){
	 dominosPlateau->push_back(d);

}

void Plateau::setBeginDominosPlateau(const Domino d){
	vector<Domino>::iterator iterator = dominosPlateau->begin();

	 dominosPlateau->insert(iterator+(0),d);

}

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

bool Plateau::verifierCompatibilite(int jonction){
		if (jonction == getValInf())
			return true;
		else if (jonction == getValSup())
			return true;
		else return false;

}

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



