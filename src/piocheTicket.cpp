#include "piocheTicket.hpp"

using namespace std;

// --- Constructeur par défault ---
PiocheTicket::PiocheTicket(){

}

// --- Constructeur ---
PiocheTicket::PiocheTicket(vector<CarteTicket*> vecteurTickets) {
    for (CarteTicket* c : vecteurTickets) {
        pioche_.push_back(c);//déplade de la defausse vers la
    }
}



// --- Destructeur ---
PiocheTicket::~PiocheTicket() {

}


const Carte * PiocheTicket::piocher() {
    if (pioche_.empty()) {
        return nullptr; // plus de carte à piocher
    }
    Carte *ticketPtr = pioche_.back();
    pioche_.pop_back();
    return ticketPtr;
}

bool PiocheTicket::estVide() const {
    return pioche_.empty();
}   