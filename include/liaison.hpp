#pragma once
#include "ville.hpp"
#include <string>
#include <vector>
#include <array>
#include "couleur.hpp"
#include "joueur.hpp"
using namespace std;

class liaison
{
private:
    array<ville*> villes;
    int nbRails;
    couleur_e couleurRail;
    joueur* occupant;
public:
    // constructeurs
    liaison(ville* nvVa,ville* nvVb,int nvNbRails,string couleurRail);
    // accesseurs
    array<ville*> getVilles() const;
    int getNbRails() const;
    couleur_e getCouleur() const;
    joueur* getOccupant() const;
    // mutateurs
    void setOccupant(joueur* nvOccupant);
    // methodes
    bool isOccupe();
    // destructeurs
    ~liaison();
};

