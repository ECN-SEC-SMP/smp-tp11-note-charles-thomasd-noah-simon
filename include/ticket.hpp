#pragma once
#include "ville.hpp"
#include <array>
#include <string>

using namespace std;

/**
 * @brief La classe Ticket représente une Carte Ticket dans le jeu.
 * Elle hérite de la classe Carte et contient deux objets ville
 * représentant les villes qui doivent être connectées, ainsi qu'un 
 * attribut booléen pour indiquer si le Ticket est complété ou non. 
 */
class Ticket
{
private:
    array<Ville*,2> villes;
    bool isTermine;
    
public:
    /**
     * @brief Construction d'un nouvel objet Ticket
     * 
     * @param ville1
     * @param ville2
     */
    Ticket(ville* ville1, ville* ville2);

    /**
     * @brief Récupère les villes du Ticket
     * 
     */
    array<Ville*,2> getVilles();

    /**
     * @brief Passe l'attribut isTermine à true pour indiquer que le Ticket est complété
     * 
     */
    void setIsTermine();

    ~Ticket();
};