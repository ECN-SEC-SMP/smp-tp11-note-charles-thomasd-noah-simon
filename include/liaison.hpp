#pragma once
#include "ville.hpp"
#include <string>
#include <vector>
#include <array>
#include "couleur.hpp"
#include "joueur.hpp"

using namespace std;

class Liaison
{
private:
    array<Ville*,2> villes;
    couleur_e couleurRail;
    Joueur* occupant;
    int nbRails;


public:
    // constructeurs
    Liaison(Ville* nvVa,Ville* nvVb, couleur_e couleurRail, unsigned int nvNbRails);

    // destructeurs
    ~Liaison();

    // accesseurs
    array<Ville*,2> getVilles() const;
    int getNbRails() const;
    couleur_e getCouleur() const;
    Joueur* getOccupant() const;

    // mutateurs
    void setOccupant(Joueur* nvOccupant);

    // methodes
    bool isOccupe() const;

};

