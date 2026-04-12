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
};

