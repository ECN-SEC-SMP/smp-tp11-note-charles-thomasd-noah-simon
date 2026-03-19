#pragma once
#include "carte.hpp"
#include "ville.hpp"
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
    ville ville1;
    ville ville2;
    bool isTermine;
public:
    /**
     * @brief Construction d'un nouvel objet ticket
     * 
     * @param ville1 
     * @param ville2 
     */
    ticket(ville ville1, ville ville2);

    /**
     * @brief Récupère la première ville du ticket
     * 
     */
    void getVille1();

    /**
     * @brief Récupère la deuxième ville du ticket
     * 
     */
    void getVille2();

    /**
     * @brief Passe l'attribut isTermine à true pour indiquer que le ticket est complété
     * 
     */
    void setIsTermine();

    ~ticket();
};