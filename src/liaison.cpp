#include "liaison.hpp"

// constructeurs
Liaison::Liaison(Ville* nvVa,Ville* nvVb, couleur_e couleurRail, unsigned int nvNbRails)
{
    this->villes = {nvVa,nvVb};
    this->nbRails = nvNbRails;
    this->couleurRail = couleurRail;
    this->occupant = nullptr;
}

// accesseurs
const array<Ville*,2> & Liaison::getVilles() const {
     return this->villes;
}

int Liaison::getNbRails() const { 
    return this->nbRails;
}

couleur_e Liaison::getCouleur() const {
    return this->couleurRail;
}

Joueur* Liaison::getOccupant() const {
    return this->occupant;
}

// mutateurs
void Liaison::setOccupant(Joueur* nvOccupant) {
    this->occupant = nvOccupant;
}

// methodes
bool Liaison::isOccupe() const
{
    bool status = !(Liaison::getOccupant() == nullptr);
    return status;
}

// destructeurs
Liaison::~Liaison(){
    // for (unsigned int i = 0; i < villes.size(); i++){
    //     delete villes[i];
    // }
}