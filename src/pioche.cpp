#include "pioche.hpp"
#include <algorithm>
#include <random>
#include <vector>

Pioche::Pioche() {
    // Initialisation de la pioche avec des cartes wagon et des tickets
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 10; ++j) {
            Trains.push_back(static_cast<couleur_e>(j)); // Ajout des cartes wagon de différentes couleurs
        }
    }
    for (int i = 0; i < 12; ++i) {
        Trains.push_back(static_cast<couleur_e>(MULTICOLORE)); // Ajout des locomotives
    }
    // Mélange des cartes wagon
    std::mt19937 rng(std::random_device{}());
    std::shuffle(Trains.begin(), Trains.end(), rng);

    // Initialisation des tickets (depuis ticket.csv)
    // Récupération des données depuis le fichier CSV et création des objets Ticket

    for(int i = 1; i < 33; ++i) {
        
    }
}