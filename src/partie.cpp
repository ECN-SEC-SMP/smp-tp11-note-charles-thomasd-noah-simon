#include "partie.hpp"
#include "csvReader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <memory>

using namespace std;


partie::partie(string mapCVS, string ticketCSV){ 

    Reader reader;
    auto mapData = reader(mapCVS);
    // Charger le plateau à partir du fichier CSV
    plat = Plateau(mapData);

    // Charger les tickets à partir du fichier CSV
    auto ticketData = reader(ticketCSV);
    piocheTicket = PiocheTicket(ticketData);

    // Initialiser la pioche de wagons (par exemple, avec 110 cartes)
    piocheWagon = PiocheWagon();

   //choix du nombre de joueurs
    int numPlayers=0; 
    cout << "Entrez le nombre de joueurs (2-4) : ";
    cin >> numPlayers;
    for (int i = 0; i < numPlayers; ++i) {
        joueurs.emplace_back("Joueur " + to_string(i + 1)); // Crée des joueurs avec des noms génériques
    }
    
    cout << "Partie initialisée avec " << numPlayers << " joueurs." << endl;

}



partie::~partie() {
    // Les objets seront automatiquement nettoyés
    // (les vecteurs seront vidés automatiquement)
}
