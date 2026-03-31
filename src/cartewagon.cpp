#include "carteWagon.hpp"

CarteWagon::CarteWagon(couleur_e couleur) : couleur(couleur){
    this->couleur = couleur;
}

couleur_e CarteWagon::getCouleur(){
    return couleur;
}

CarteWagon::~CarteWagon(){}