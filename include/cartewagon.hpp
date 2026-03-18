#pragma once
#include "carte.hpp"
#include "couleur.hpp"
#include <string>

using namespace std;

class carteWagon : public carte
{
private:
    couleur_e couleur;
public:
    carteWagon(couleur_e couleur);
    couleur_e getCouleur();
    ~carteWagon();
};