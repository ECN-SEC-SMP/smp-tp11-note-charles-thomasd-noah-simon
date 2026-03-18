#include <stdlib.h>
#include <vector>

using namespace std;

#include "plateau.h"
#include "joueur.h"
#include "pioche.h"


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


