#include <stdlib.h>
#include <vector>

using namespace std;

#include "plateau.hpp"
#include "joueur.hpp"
#include "pioche.hpp"
#include "piocheTicket.hpp"
#include "piocheWagon.hpp"


class partie
{
private:
    Plateau plat;
    vector<Joueur> joueurs;
    PiocheTicket piocheTicket;
    PiocheWagon piocheWagon;
public:
    partie(string fichier);
    
    ~partie();
};


