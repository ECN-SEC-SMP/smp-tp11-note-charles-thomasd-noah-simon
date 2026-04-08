#include "piocheWagon.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;


mt19937 rng(random_device{}());

/******* Private function *******/
void PiocheWagon::genWagons() {
    pioche_.clear(); // reset le vecteur 
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 10; ++j) {
            pioche_.push_back(CarteWagon(static_cast<couleur_e>(j))); // Ajout des cartes wagon de différentes couleurs
        }
    }
    for (int i = 0; i < 12; ++i) {
        pioche_.push_back(CarteWagon(couleur_e::MULTICOLORE)); // Ajout des locomotives
    }
    // Mélange des cartes wagon
    shuffle(pioche_.begin(), pioche_.end(), rng);
}
/********************************/


/******* Public function *******/

PiocheWagon::PiocheWagon() {
    // Initialisation de la pioche avec des cartes wagon 
    genWagons();
}

PiocheWagon::~PiocheWagon(){
};


unique_ptr<Carte> PiocheWagon::piocher() {
    if (pioche_.empty()) {
        if (defausse_.empty()){
            return nullptr; // on ne retourne pas de carte
        }else {
            resetPioche();
        }
    }
    CarteWagon carte = pioche_.back(); //Copy la carte
    pioche_.pop_back(); // supprime la carte du vecteur
    return make_unique<Carte>(carte);
}


void PiocheWagon::addDefausse(const CarteWagon& carte) {
    defausse_.push_back(carte);
}


void PiocheWagon::resetPioche() {
    pioche_ = defausse_;
    shuffle(pioche_.begin(), pioche_.end(), rng); //Melange
    defausse_.clear(); //vide la defausse
}


bool PiocheWagon::estVide() const {
    return pioche_.empty();
}   


/********************************/

