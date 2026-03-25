#include "pioche.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;

/**
 * @brief Constructeur de la classe Pioche
 * 
 * @todo Ecrire la fonction d'initialisation de la pioche des tickets avec la fonction de Simon pour les CSV
 */
Pioche::Pioche() {
    // Initialisation de la pioche avec des cartes wagon et des tickets
    Trains = genWagons();
    // Tickets
}

/**
 * @brief Génère les cartes wagon
 * 
 * @return vector<carteWagon> 
 */
vector<carteWagon> genWagons() {
    vector<carteWagon> wagons;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 10; ++j) {
            wagons.push_back(carteWagon(static_cast<couleur_e>(j))); // Ajout des cartes wagon de différentes couleurs
        }
    }
    for (int i = 0; i < 12; ++i) {
        wagons.push_back(carteWagon(MULTICOLORE)); // Ajout des locomotives
    }
    // Mélange des cartes wagon
    mt19937 rng(random_device{}());
    shuffle(wagons.begin(), wagons.end(), rng);
    return wagons;
}

/**
 * @brief Piocher une carte wagon de la pioche pour la donner à un joueur
 * et la supprime de la pioche
 * 
 * @param pioche 
 * @return carteWagon 
 */
carteWagon piocherWagon(vector<carteWagon> &pioche) {
    if (pioche.empty()) {
        cout << "La pioche de cartes wagon est vide." << endl;
    }
    carteWagon carte = pioche.back();
    pioche.pop_back();
    return carte;
}

/**
 * @brief Piocher un ticket de la pioche pour la donner à un joueur
 * et le supprime de la pioche
 * 
 * @param pioche 
 * @return Ticket 
 */
Ticket piocherTicket(vector<Ticket> &pioche) {
    if (pioche.empty()) {
        cout << "La pioche de tickets est vide." << endl;
    }
    Ticket ticket = pioche.back();
    pioche.pop_back();
    return ticket;
}

/**
 * @brief 
 * 
 */
void Pioche::defausseWagon(const carteWagon& carte) {
    Defausse.push_back(carte);
}

/**
 * @brief Réinitialise la pioche de cartes wagon lorsque celle-ci est vide
 * Les cartes utilisées et placées dans la défausse (supprimées) deviennent la nouvelle pioche. 
 */
void Pioche::resetPiocheWagon(vector<carteWagon> &defausse) {
    Trains = defausse;
    shuffle(Trains.begin(), Trains.end(), mt19937(random_device{}()));
    defausse.clear();
}