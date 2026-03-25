#include <stdlib.h>
#include <vector>

using namespace std;

#include "plateau.hpp"
#include "joueur.hpp"
#include "pioche.hpp"


class partie
{
private:
    Plateau plat;
    vector<Joueur> joueurs;
    Pioche piocheTicket;
    Pioche piocheWagon;
public:
    partie(string fichier);
    
    ~partie();
};


