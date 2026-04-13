#include "../include/joueur.hpp"
#include <iostream>

using namespace std;

/**
 * @brief Constructeur du Joueur
 * Initialise tous les attributs du joueur :
 * - main : vecteur vide de CarteWagon
 * - tickets : vecteur vide de CarteTicket  
 * - ticketGagnes : 0 au départ
 * - wagonRestants : 45 wagons au départ (nombre standard du jeu)
 * - couleur : chaîne vide à initialiser
 */
Joueur::Joueur(PiocheWagon &piocheWagon, PiocheTicket& piocheTicket, couleur_e c)
{
    for (int i = 0; i < 4; i++) {
        // Piocher une carte wagon et la convertir en CarteWagon
        Carte * carte = piocheWagon.piocher(); 
        CarteWagon* carteWagon = dynamic_cast<CarteWagon*>(carte);
        main_.push_back(carteWagon);
    }

    for (int i = 0; i < 1; i++) {
        // Piocher une carte ticket et la convertir en CarteTicket
        Carte * carte = piocheTicket.piocher(); // Récupère unique_ptr<Carte>
        CarteTicket* carteTicket = dynamic_cast<CarteTicket*>(carte);
        tickets_.push_back(carteTicket); // Déréférencer et ajouter
    }

    nbTicketGagnes_ = 0;
    nbWagonRestants_ = 45;
    couleur_ = c;
}

/**
 * @brief Destructeur du Joueur
 * Libère les ressources du joueur
 * Les vecteurs (main et tickets) sont automatiquement nettoyés par leur destructeur
 */
Joueur::~Joueur()
{
    // Les vecteurs sont automatiquement détruits via leur destructeur
    // Pas de pointeurs à libérer manuellement
}

const vector<CarteWagon*>& Joueur::get_main() const{
    return main_;
}

const vector<CarteTicket*>& Joueur::get_tickets() const{
    return tickets_;
}
const int Joueur::get_ticketGagnes() const{
    return nbTicketGagnes_;
}
const int Joueur::get_wagonRestants() const{
    return nbWagonRestants_;
}
const couleur_e Joueur::getCouleur(){
        return couleur_;
}

void Joueur::set_ticketGagnes(int newTicketGagnes){
    nbTicketGagnes_ = newTicketGagnes;
}


void Joueur::utiliserWagon(){
    nbWagonRestants_--;
}