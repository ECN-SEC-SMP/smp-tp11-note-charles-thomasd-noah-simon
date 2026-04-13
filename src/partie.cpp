#include "partie.hpp"
#include "csvReader.hpp"
#include <iostream>
#include <map>
#include <memory>

// --- Méthode Privées ---
void Partie::choixNbJoueur(){
    unsigned int nbJoueur = 0; 
    while (nbJoueur > 2 && nbJoueur < 4)
    {
        display.nbJoueursPartie();
        cin >> nbJoueur;
    }
    
    //Création des joueurs avec couleur basic
    for (unsigned int i = 0; i < nbJoueur; i++) {
        //les joueurs pioches leur carte en même temps
        joueurs_.push_back(new Joueur(static_cast<couleur_e>(i)));
    }
}

void Partie::distribuerCarte(){
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

unsigned int Partie::choixTourJoueur(){
    unsigned int actionJoueur = 0;
    while (actionJoueur > 0 && actionJoueur < 4)
    {
        cin >> actionJoueur;
    }
    return actionJoueur;
}


void Partie::distribuerCarteWagon(Joueur * j, unsigned int nb){
    if ( j == nullptr) return;

    for (unsigned int i = 0; i < nb; i++) {
        Carte * carte = piocheTicket_.piocher(); // Récupère unique_ptr<Carte>
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
    // Les objets seront automatiquement nettoyés
    // (les vecteurs seront vidés automatiquement)
}

// --- Méthode Publique ---
void Partie::initialiser(){
   //choix du nombre de joueurs
   choixNbJoueur();
   distribuerCarte();

   display.partieInitialise(joueurs_.size());
}

void Partie::lancer(){
    for(auto &j : joueurs_){
        display.choixActionJoueur(*j);
        switch (choixTourJoueur())
        {
            case 1 :
                distribuerCarteWagon(j,2);
            break;

            case 2 :
                /* code */
            break;

            case 3 :
                passerTour(j);
            break;
        
            default:
            break;
        }
    } 
}




