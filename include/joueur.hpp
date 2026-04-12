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
    std::vector<CarteWagon> main;
    std::vector<CarteTicket> tickets;
    int ticketGagnes;
    int wagonRestants;
    couleur_e couleur;

public:
    Joueur(PiocheWagon& piocheWagon, PiocheTicket& piocheTicket, couleur_e c);

    ~Joueur();

    const vector<CarteWagon>* get_main() const;
    const vector<CarteTicket>* get_tickets() const;
    const int get_ticketGagnes() const;
    couleur_e getCouleur(){
        return couleur;
    }


    void set_main(vector<CarteWagon> &newMain);
    void set_tickets(vector<CarteTicket> &newTickets);
    void set_ticketGagnes(int &newTicketGagnes);
    void set_wagonRestants(int &newWagonRestants);
    void set_couleur(string &newCouleur);

};

