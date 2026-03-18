#include <stdlib.h>
#include <vector>
#include<string>

using namespace std;

#include "carte.h"

class Joueur
{
private:
    vector<CarteWagon> main;
    vector<Ticket> tickets;
    int ticketGagnes;
    string couleur;
    int wagonRestants;

public:
    Joueur();

    ~Joueur();
};

