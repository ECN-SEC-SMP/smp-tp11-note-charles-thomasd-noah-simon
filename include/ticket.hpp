#pragma once
#include "carte.hpp"
#include "ville.hpp"
#include <array>
#include <string>

using namespace std;

/**
 * @brief La classe ticket représente une carte ticket dans le jeu.
 * Elle hérite de la classe carte et contient deux objets ville
 * représentant les villes qui doivent être connectées, ainsi qu'un 
 * attribut booléen pour indiquer si le ticket est complété ou non. 
 */
class ticket : public carte
{
private:
    array<ville*,2> villes;
    bool isTermine;
public:
    /**
     * @brief Construction d'un nouvel objet ticket
     * 
     * @param ville1
     * @param ville2
     */
    ticket(ville* ville1, ville* ville2);

    /**
     * @brief Récupère les villes du ticket
     * 
     */
    array<ville*,2> getVilles();

    /**
     * @brief Passe l'attribut isTermine à true pour indiquer que le ticket est complété
     * 
     */
    void setIsTermine();

    ~ticket();
};