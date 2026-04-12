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
    std::vector<CarteWagon*> main;
    std::vector<CarteTicket*> tickets;
    int nbticketGagnes;
    int wagonRestants;
    couleur_e couleur;

public:
    // --- Constructeur ---
    Joueur(PiocheWagon& piochWeagon, PiocheTicket& piocheTicket, couleur_e c);
    // --- Destructeur ---
    ~Joueur();


    couleur_e getCouleur(){
        return couleur;
    }
};

