#include "piocheTicket.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;



PiocheTicket::PiocheTicket() {
    // Initialisation de la pioche avec des tickets

}

PiocheTicket::~PiocheTicket() {

}


unique_ptr<Carte> PiocheTicket::piocher() {
    if (pioche_.empty()) {
        return nullptr; // plus de carte
    }
    CarteTicket ticket = pioche_.back();
    pioche_.pop_back();
    return make_unique<Carte>(ticket);;
}

bool PiocheTicket::estVide() const {
    return pioche_.empty();
}   