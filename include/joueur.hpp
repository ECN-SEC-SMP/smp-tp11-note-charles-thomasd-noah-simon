#pragma once
#include <stdlib.h>
#include <vector>
#include<string>

using namespace std;

#include "carteWagon.hpp"
#include "carteTicket.hpp"
#include "piocheTicket.hpp"
#include "piocheWagon.hpp"


class Joueur
{
private:
    vector<CarteWagon> main;
    vector<CarteTicket> tickets;
    int ticketGagnes;
    int wagonRestants;
    string couleur;

public:
    Joueur(PiocheWagon& piocheWagon, PiocheTicket& piocheTicket, string Jcouleur);

    ~Joueur();

    const vector<CarteWagon>* get_main() const;
    const vector<CarteTicket>* get_tickets() const;
    const int* get_ticketGagnes() const;
    const int* get_wagonRestants() const;
    const string* get_couleur() const;

    void set_main(vector<CarteWagon> &newMain);
    void set_tickets(vector<CarteTicket> &newTickets);
    void set_ticketGagnes(int &newTicketGagnes);
    void set_wagonRestants(int &newWagonRestants);
    void set_couleur(string &newCouleur);

};

