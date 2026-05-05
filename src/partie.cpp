#include "partie.hpp"
#include "csvReader.hpp"
#include <iostream>
#include <map>
#include <memory>

// --- Méthode Privées ---
void Partie::choixNbJoueur(){
    display.nbJoueursPartie();
    unsigned int nbJoueur = in.entier(2,4); 
    
    //Création des joueurs avec des couleurs basic
    //ajouter choix de couleur ?
    for (unsigned int i = 0; i < nbJoueur; i++) {
        //les joueurs pioches leur carte en même temps
        joueurs_.push_back(new Joueur(static_cast<couleur_e>(i)));
    }
}

void Partie::distribuerCartes(){
    //Pour tous les joueurs
    for(const auto &j : joueurs_){
        if (j != nullptr)
        {
            // Piocher 4 une carte wagon 
            distribuerCarteWagon(j,4);

            // Piocher 2 carte ticket et la convertir en CarteTicket
            distribuerCarteTicket(j,2);
        }   
    }
}



void Partie::distribuerCarteWagon(Joueur * j, unsigned int nb){
    if ( j == nullptr) return;

    for (unsigned int i = 0; i < nb; i++) {
        Carte * carte = piocheWagon_.piocher(); // Récupère unique_ptr<Carte>
        j->piocherCarteWagon(dynamic_cast<CarteWagon*>(carte));
    }
}


void Partie::distribuerCarteTicket(Joueur * j, unsigned int nb){
    if ( j == nullptr) return;

    for (unsigned int i = 0; i < nb; i++) {
        Carte * carte = piocheTicket_.piocher(); // Récupère unique_ptr<Carte>
        j->piocherCarteTicket(dynamic_cast<CarteTicket*>(carte));
    }
}


void Partie::poserWagon(Joueur* j) {
    if (j == nullptr) return;

    auto& liaisons = plat_.getLiaisons();
    auto indexMap = plat_.getIndexMap(); 

    //Affichage du plateau de jeux
    display.plateau(plat_);
    display.choixLiaison(*j);
    unsigned int choix = in.entier(1, indexMap.size()) - 1;
    unsigned int indexReel = indexMap[choix];

    // Liaison double ?
    if (indexReel + 1 < liaisons.size() && liaisons[indexReel] == liaisons[indexReel + 1]) {
        display.choixLiaisonDouble(*j);
        unsigned int voie = in.entier(1,2);
        if (!plat_.putWagon(&liaisons[indexReel + (voie - 1)], *j))
        {
           //empêcher le joueur de poser le wagon 
        }
    } else {
        if (!plat_.putWagon(&liaisons[indexReel], *j))
        {
            
        }
    }
}


void Partie::tourJoueur(Joueur *j){
    if (j == nullptr) return;
    display.choixTourJoueur(*j);
        switch (in.entier(1,3))
        {
            case 1 :
                distribuerCarteWagon(j,2);
            break;

            case 2 :
                poserWagon(j);
            break;

            case 3 :
                passerTour(j);
            break;
        
            default:
            break;
        }
}


void Partie::passerTour(Joueur * j){
    if ( j == nullptr) return;
    //defausser ticket du joueur
    auto ticketDefausseTab  = j->defausser2Ticket();

    //remettre les tickets dans la pioches 
    for(auto t : ticketDefausseTab){
        if (t != nullptr)
        {
            piocheTicket_.ajouterTicket(t);
        } 
    }

    //piocher des nouveaux ticket
    distribuerCarteTicket(j,2);
}




// --- Lifecycle (Constructeurs / Destructeur) ---
Partie::Partie(string mapCVS, string ticketCSV){ 
    Reader reader;
    // Charger le plateau à partir du fichier CSV
    plat_ = Plateau(reader.readMaps(mapCVS));

    // Charger les tickets à partir du fichier CSV
    piocheTicket_ = PiocheTicket(reader.readTickets(ticketCSV));

    // Initialiser la pioche de wagons
    piocheWagon_ = PiocheWagon();
}

Partie::~Partie() {
    for(const auto &j : joueurs_){
        delete j;
    }
}

// --- Méthode Publique ---
void Partie::initialiser(){
   //choix du nombre de joueurs
   choixNbJoueur();
   distribuerCartes();

   display.partieInitialise(joueurs_.size());
}

void Partie::lancer(){
    for(auto &j : joueurs_){
        tourJoueur(j);
    } 
}




