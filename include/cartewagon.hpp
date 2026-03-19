#pragma once
#include "carte.hpp"
#include "couleur.hpp"
#include <string>

using namespace std;

/**
 * @brief Représente une carte wagon dans le jeu
 * Une carte wagon a une couleur spécifique qui est définie par l'énumération couleur_e.
 * Elle est utilisée pour emprunter les rails entre les villes sur le plateau de jeu.
 * Elle hérite de la classe carte, ce qui permet de la traiter de manière polymorphique avec d'autres types de cartes dans le jeu. 
 */
class carteWagon : public carte
{
private:
    couleur_e couleur;
public:
    /**
     * @brief Construit une nouvelle carte wagon avec une couleur spécifique
     * 
     * @param couleur 
     */
    carteWagon(couleur_e couleur);

    /**
     * @brief Renvoie la couleur de la carte wagon
     * 
     * @return couleur_e 
     */
    couleur_e getCouleur();

    ~carteWagon();
};