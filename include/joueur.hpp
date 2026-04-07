#pragma once
#include <stdlib.h>
#include <vector>
#include<string>

#include "carteWagon.hpp"
#include "carteTicket.hpp"


class Joueur
{
private:
    std::vector<CarteWagon> main;
    std::vector<CarteTicket> tickets;
    int ticketGagnes;
    int wagonRestants;
    std::string couleur;

public:
    Joueur();

    ~Joueur();
};

