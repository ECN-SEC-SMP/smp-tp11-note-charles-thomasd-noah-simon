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
    // --- Attributs privés ---
    array<Ville*,2> villes;
    couleur_e couleurRail;
    Joueur* occupant;
    unsigned int nbRails;

public:
    // --- constructeurs ---
    Liaison(Ville* nvVa,Ville* nvVb, couleur_e couleurRail, unsigned int nvNbRails);

    // --- destructeurs ---
    ~Liaison();

    // --- accesseurs ---
    const array<Ville*,2> &getVilles() const;
    unsigned int getNbRails() const;
    couleur_e getCouleur() const;
    Joueur* getOccupant() const;
    

    //test

    // --- mutateurs ---
    void setOccupant(Joueur *nvOccupant);

    // --- methodes ---
    bool isOccupe() const;

    bool operator==(const Liaison &l2) const { 
        const auto &v2 = l2.getVilles();
        return (villes[0] == v2[0] && villes[1] == v2[1])   // sens normal
            || (villes[0] == v2[1] && villes[1] == v2[0]);  // sens inverse
    }
};

