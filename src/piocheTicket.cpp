#include "piocheTicket.hpp"

using namespace std;


// --- Lifecycle (Constructeurs / Destructeur) ---
PiocheTicket::PiocheTicket(){

}

PiocheTicket::PiocheTicket(vector<CarteTicket*> vecteurTickets) {
    for (CarteTicket* c : vecteurTickets) {
        pioche_.push_back(c);//déplade de la defausse vers la
    }
}


PiocheTicket::~PiocheTicket() {

}

// --- Méthode Publique ---
Carte * PiocheTicket::piocher() {
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

void PiocheTicket::ajouterTicket(CarteTicket* c){
    if (c == nullptr) return;
    pioche_.push_back(c);
}
