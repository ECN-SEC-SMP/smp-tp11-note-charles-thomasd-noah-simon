#include "carteWagon.hpp"

// --- Lifecycle (Constructeurs / Destructeur) ---
CarteWagon::CarteWagon(couleur_e c) : couleur(c){
}

CarteWagon::~CarteWagon(){
    
}

// --- Méthodes publiques ---
couleur_e CarteWagon::getCouleur(){
    return couleur;
}

