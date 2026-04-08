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
Joueur::Joueur(PiocheWagon& piocheWagon, PiocheTicket& piocheTicket, couleur_e c)
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

    couleur = c;
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
