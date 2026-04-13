#pragma once
#include <array>
#include <vector>
#include <string>

#include "carteWagon.hpp"
#include "carteTicket.hpp"
#include "piocheTicket.hpp"
#include "piocheWagon.hpp"


class Joueur
{
private:
    // --- Attributs privés ---
    std::vector<CarteWagon*> main_;
    std::vector<CarteTicket*> tickets_;
    int nbTicketGagnes_;
    int nbWagonRestants_;
    couleur_e couleur_;

public:
    // --- Constructeur ---
    Joueur(couleur_e c);
    // --- Destructeur ---
    /**
     * @brief Destructeur du Joueur
     * Libère les ressources du joueur
     * Les vecteurs (main et tickets) sont automatiquement nettoyés par leur destructeur
     */
    ~Joueur();

    // --- Acesseur ---
    const std::vector<CarteWagon*>& get_main() const;//test
    const std::vector<CarteTicket*>& get_tickets() const;//test
    int get_ticketGagnes() const;
    int get_wagonRestants() const;
    couleur_e getCouleur() const;

    
    // --- Setteur ---
    void set_ticketGagnes(int newTicketGagnes);

    // --- Méthodes publique ---
    void utiliserWagon(int nb);
    void piocherCarteWagon(CarteWagon *c);

    void piocherCarteTicket(CarteTicket *c);
    std::array<CarteTicket*,2> defausser2Ticket();



};

