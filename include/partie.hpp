#include <stdlib.h>
#include <vector>

using namespace std;

#include "plateau.hpp"
#include "joueur.hpp"
#include "pioche.hpp"
#include "piocheTicket.hpp"
#include "piocheWagon.hpp"
#include "csvReader.hpp"


class Partie
{
private:
    Plateau plat;
    vector<Joueur> joueurs;
    PiocheTicket piocheTicket;
    PiocheWagon piocheWagon;
public:
    Partie();
    Partie(string mapCVS, string ticketCSV);
    
    ~Partie();
};


