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
Joueur::Joueur(PiocheWagon& piocheWagon, PiocheTicket& piocheTicket, string Jcouleur)
{
    main = vector<CarteWagon>();

    for (int i = 0; i < 4; i++) {
        // Piocher une carte wagon et la convertir en CarteWagon
        auto carte = piocheWagon.piocher(); // Récupère unique_ptr<Carte>
        CarteWagon* carteWagon = dynamic_cast<CarteWagon*>(carte.get());
            main.push_back(*carteWagon); // Déréférencer et ajouter
    }


    tickets = vector<CarteTicket>();

    for (int i = 0; i < 1; i++) {
        // Piocher une carte ticket et la convertir en CarteTicket
        auto carte_ = piocheTicket.piocher(); // Récupère unique_ptr<Carte>
        CarteTicket* carteTicket = dynamic_cast<CarteTicket*>(carte_.get());
            tickets.push_back(*carteTicket); // Déréférencer et ajouter
    }

    ticketGagnes = 0;

    wagonRestants = 45;

    couleur=Jcouleur;


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

const vector<CarteWagon>* Joueur::get_main() const{
    return &main;
}

const vector<CarteTicket>* Joueur::get_tickets() const{
    return &tickets;
}
const int* Joueur::get_ticketGagnes() const{
    return &ticketGagnes;
}
const int* Joueur::get_wagonRestants() const{
    return &wagonRestants;
}
const string* Joueur::get_couleur() const{
    return &couleur;
}

void Joueur::set_main(vector<CarteWagon> &newMain){
    main = newMain;
}
void Joueur::set_tickets(vector<CarteTicket> &newTickets){
    tickets = newTickets;
}
void Joueur::set_ticketGagnes(int &newTicketGagnes){
    ticketGagnes = newTicketGagnes;
}
void Joueur::set_wagonRestants(int &newWagonRestants){
    wagonRestants = newWagonRestants;
}
void Joueur::set_couleur(string &newCouleur){
    couleur = newCouleur;
}
