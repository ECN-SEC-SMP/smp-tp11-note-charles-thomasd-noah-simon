#include <vector>

#include "affichage.hpp"
#include "plateau.hpp"
#include "joueur.hpp"
#include "pioche.hpp"
#include "piocheTicket.hpp"
#include "piocheWagon.hpp"
#include "csvReader.hpp"


class Partie
{
private:
    Affichage display;
    Plateau plat_;
    std::vector<Joueur*> joueurs_;
    PiocheTicket piocheTicket_;
    PiocheWagon piocheWagon_;

    void choixNbJoueur();
    void distribuerCarte();
    unsigned int choixTourJoueur();
    void distribuerCarteWagon(Joueur * j, unsigned int nb = 1);
    void distribuerCarteTicket(Joueur * j, unsigned int nb = 1);
    void passerTour(Joueur * j);

public:
    Partie();
    Partie(string mapCVS, string ticketCSV);
    
    void initialiser();
    void lancer();
    
    ~Partie();
};


