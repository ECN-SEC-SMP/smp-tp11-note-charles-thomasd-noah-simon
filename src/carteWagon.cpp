#include "cartewagon.hpp"

/**
 * @brief Construit une nouvelle carte Wagon
 * 
 * @param couleur
 */
carteWagon::carteWagon(couleur_e couleur) : carte(), couleur(couleur){
    this->couleur = couleur;
}

/**
 * @brief Retourne la couleur de la carte Wagon
 * 
 * @return couleur_e 
 */
couleur_e carteWagon::getCouleur(){
    return couleur;
}

carteWagon::~carteWagon(){}