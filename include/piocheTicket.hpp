#pragma once
#include "carteTicket.hpp"
#include "pioche.hpp"
#include <vector>

using namespace std;

class PiocheTicket : Pioche {
private:
    


public:
    // --- Constructeur par défault ---
    PiocheTicket();
    // --- Constructeur ---
    PiocheTicket(vector<CarteTicket*> vecteurTickets);
    // --- Destructeur ---
    ~PiocheTicket();

    // --- Méthodes héritées ---
    void ajouterTicket(CarteTicket* c);
    bool estVide() const override;
    Carte * piocher() override;
};
