#pragma once
#include "ville.hpp"
#include "carte.hpp"
#include <array>
#include <string>


using namespace std;

/**
 * @brief La classe Ticket représente une Carte Ticket dans le jeu.
 * Elle hérite de la classe Carte et contient deux objets ville
 * représentant les villes qui doivent être connectées, ainsi qu'un 
 * attribut booléen pour indiquer si le Ticket est complété ou non. 
 */
class CarteTicket : public Carte
{
private:
    static constexpr unsigned int nbVilles_ = 2;
    array<Ville*,nbVilles_> villes_;
    bool valider_;
    
public:
    /**
     * @brief Construction d'un nouvel objet Ticket
     * 
     * @param 
     */
    CarteTicket();
    CarteTicket(Ville * vA, Ville * vB);
    CarteTicket(array<Ville*,nbVilles_> v);

    /**
     * @brief Récupère les villes du Ticket
     * 
     */
    array<Ville*,nbVilles_> getVilles();

    /**
     * @brief Passe l'attribut isTermine à true pour indiquer que le Ticket est complété
     * 
     */
    void setValider();

    ~CarteTicket();
};