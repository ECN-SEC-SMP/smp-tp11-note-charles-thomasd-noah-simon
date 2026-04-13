#pragma once
#include <stdlib.h>
#include <vector>
#include<string>

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
    Joueur(PiocheWagon &piocheWagon, PiocheTicket& piocheTicket, couleur_e c);
    // --- Destructeur ---
    ~Joueur();

    // --- Acesseur ---
    const vector<CarteWagon*>& get_main() const;//test
    const vector<CarteTicket*>& get_tickets() const;//test
    const int get_ticketGagnes() const;
    const int get_wagonRestants() const;
    const couleur_e getCouleur();

    // --- Setteur ---
    void set_ticketGagnes(int newTicketGagnes);

    // --- Méthodes publique ---
    void utiliserWagon();
};

