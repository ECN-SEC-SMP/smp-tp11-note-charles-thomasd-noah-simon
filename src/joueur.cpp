#include "joueur.hpp"
#include <iostream>

using namespace std;

// --- Lifecycle (Constructeurs / Destructeur) ---
Joueur::Joueur(couleur_e c){
    nbTicketGagnes_ = 0;
    nbWagonRestants_ = 20;
    couleur_ = c;
}


Joueur::~Joueur()
{
    // Les vecteurs sont automatiquement détruits via leur destructeur
    // Pas de pointeurs à libérer manuellement
}


// --- Méthode Publique ---
const vector<CarteWagon*>& Joueur::get_main() const{
    return main_;
}

const vector<CarteTicket*>& Joueur::get_tickets() const{
    return tickets_;
}
int Joueur::get_ticketGagnes() const{
    return nbTicketGagnes_;
}
int Joueur::get_wagonRestants() const{
    return nbWagonRestants_;
}
couleur_e Joueur::getCouleur() const{
        return couleur_;
}

void Joueur::set_ticketGagnes(int newTicketGagnes){
    nbTicketGagnes_ = newTicketGagnes;
}


void Joueur::utiliserWagon(int nb){
    nbWagonRestants_=- nb;
}

void Joueur::piocherCarteWagon(CarteWagon *c) {
    if (c == nullptr) return;
    main_.push_back(c);
}


void Joueur::piocherCarteTicket(CarteTicket *c) {
    tickets_.push_back(c);
}

array<CarteTicket*,2> Joueur::defausser2Ticket(){
    array<CarteTicket*,2> ticketTab {nullptr, nullptr};
    unsigned int cpt = 0;

    for (unsigned int i = 0; i < tickets_.size(); i++)
    {
        //On vérifie quelle ticket ne sont pas valider
        if ((!tickets_[i]->isValider()) && cpt < 2)
        {
            ticketTab[cpt] = tickets_[i]; //Ajoute dans le tableau 
            tickets_.erase(tickets_.begin() + i); // suprime des tickets du joueur
            cpt++;
        }
        if (cpt == 2) return ticketTab;
    }
    return ticketTab;
}