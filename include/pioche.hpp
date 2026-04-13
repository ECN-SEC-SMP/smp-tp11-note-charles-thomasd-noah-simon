#pragma once
#include "carte.hpp"
#include <memory>
#include <vector>

using namespace std;

class Pioche {
private:

protected:
    vector<Carte*> pioche_;

public:
    // --- Constructeur ---
    Pioche();
    // --- Destructeur ---
    ~Pioche();

    // --- Méthodes vrituel ---
    virtual Carte * piocher() = 0;
    virtual bool estVide() const = 0;
};

