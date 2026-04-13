#pragma once
#include "ville.hpp"
#include "carte.hpp"
#include <array>
#include <string>


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
    //On pourrait faire en sorte que le joueur doivent relier 3 ville dans le futur 
    std::array<Ville*,nbVilles_> villes_;
    bool valider_;
    
public:
    /**
     * @brief Construction d'un nouvel objet Ticket
     * 
     * @param 
     */
    CarteTicket();
    CarteTicket(Ville * vA, Ville * vB);
    CarteTicket(std::array<Ville*,nbVilles_> v);

    ~CarteTicket();


    /**
     * @brief Récupère les villes du Ticket
     * 
     */
    std::array<Ville*,nbVilles_> getVilles() const ;


    
    /**
     * @brief Passe l'attribut valider_ à true pour indiquer que le Ticket est complété
     * 
     */
    void setValider();

    bool isValider() const;

};