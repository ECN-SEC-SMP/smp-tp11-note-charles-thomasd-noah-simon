#include "Cartewagon.hpp"

carteWagon::carteWagon(couleur_e couleur) : Carte(), couleur(couleur){
    this->couleur = couleur;
}

couleur_e carteWagon::getCouleur(){
    return couleur;
}

carteWagon::~carteWagon(){}