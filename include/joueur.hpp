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

    couleur_e getCouleur(){
        return couleur;
    }
};

