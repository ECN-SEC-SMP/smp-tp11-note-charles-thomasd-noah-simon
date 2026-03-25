#include "cartewagon.hpp"

carteWagon::carteWagon(couleur_e couleur) : couleur(couleur){
    this->couleur = couleur;
}

couleur_e carteWagon::getCouleur(){
    return couleur;
}

carteWagon::~carteWagon(){}