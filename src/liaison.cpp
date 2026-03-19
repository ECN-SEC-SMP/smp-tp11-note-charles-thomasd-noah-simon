#pragma once
#include "liaison.hpp"

// constructeurs
liaison::liaison(ville* nvVa,ville* nvVb,int nvNbRails,string nvCouleurRail)
{
    this->villes[0] = nvVa;
    this->villes[1] = nvVb;
    this->nb_rails = nvNbRails;
    this->couleur_rail = nvCouleurRail;
    this->occupe = nullptr;
}
// accesseurs
array<ville*> getVilles() const { return this->villes;}
int getNbRails() const { return this->nbRails;}
couleur_e getCouleur() const { return this->couleurRail;}
joueur* liaison::getOccupant() const { return this->occupant;}
// mutateurs
void setOccupant(joueur* nvOccupant) { this->occupant = nvOccupant;}
// methodes
bool liaison::isOccupe()
{
    bool status = (liaison::getOccupant() == nullptr);
    return status;
}
// destructeurs
liaison::~liaison(){}