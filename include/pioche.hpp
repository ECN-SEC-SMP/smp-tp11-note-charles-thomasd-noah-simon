#include "cartewagon.hpp"
#include "ticket.hpp"
#include <vector>

using namespace std;

class Pioche {
private:
    vector<carteWagon> Trains;
    vector<Ticket> Tickets;

public:
    Pioche();
    void ajouterCarte(const Carte& Carte);
    carteWagon piocherCarte();
    Ticket piocherTicket();
    bool estVide() const;
};