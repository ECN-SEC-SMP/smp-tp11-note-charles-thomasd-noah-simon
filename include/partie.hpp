#include <vector>

#include "affichage.hpp"
#include "plateau.hpp"
#include "joueur.hpp"
#include "pioche.hpp"
#include "piocheTicket.hpp"
#include "piocheWagon.hpp"
#include "csvReader.hpp"
#include "input.hpp"


class Partie
{
private:
    Affichage display;
    Input in;
    Plateau plat_;
    std::vector<Joueur*> joueurs_;
    PiocheTicket piocheTicket_;
    PiocheWagon piocheWagon_;

    void choixNbJoueur();
    void distribuerCartes();
    void tourJoueur(Joueur * j);
    void distribuerCarteWagon(Joueur * j, unsigned int nb = 1);
    void distribuerCarteTicket(Joueur * j, unsigned int nb = 1);
    void passerTour(Joueur * j);
    void poserWagon(Joueur * j);

public:
    Partie();
    Partie(string mapCVS, string ticketCSV);
    
    void initialiser();
    void lancer();
    
    ~Partie();
};


