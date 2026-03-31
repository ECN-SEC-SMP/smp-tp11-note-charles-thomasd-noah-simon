#pragma once
#include <stdlib.h>
#include <vector>
#include<string>

using namespace std;

#include "carteWagon.hpp"
#include "carteTicket.hpp"


class Joueur
{
private:
    vector<CarteWagon> main;
    vector<CarteTicket> tickets;
    int ticketGagnes;
    int wagonRestants;
    string couleur;

public:
    Joueur();

    ~Joueur();
};

