#pragma once
#include "couleur.hpp"
#include "carte.hpp"
#include <string>

/**
 * @brief Représente une Carte wagon dans le jeu
 * Une Carte wagon a une couleur spécifique qui est définie par l'énumération couleur_e.
 * Elle est utilisée pour emprunter les rails entre les villes sur le plateau de jeu.
 * Elle hérite de la classe Carte, ce qui permet de la traiter de manière polymorphique avec d'autres types de Cartes dans le jeu. 
 */
class CarteWagon : public Carte
{
private:
    couleur_e couleur;
public:


    /**
     * @brief Construit une nouvelle Carte wagon avec une couleur spécifique
     * 
     * @param couleur 
     */
    CarteWagon(couleur_e couleur);

    /**
     * @brief Renvoie la couleur de la Carte wagon
     * 
     * @return couleur_e 
     */
    couleur_e getCouleur();

    ~CarteWagon();
};