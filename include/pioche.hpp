#include "cartewagon.hpp"
#include "ticket.hpp"
#include <vector>

using namespace std;

class Pioche {
private:
    vector<carteWagon> Trains;
    vector<carteWagon> Defausse;
    vector<Ticket> Tickets;

public:
    Pioche();
    void resetPiocheWagon(vector<carteWagon> &defausse);
    void defausseWagon(const carteWagon& carte);
    carteWagon piocherWagon(vector<carteWagon> &pioche);
    Ticket piocherTicket(vector<Ticket> &pioche);
    bool estVide() const;
};

vector<carteWagon> genWagons();