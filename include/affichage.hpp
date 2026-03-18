#ifndef AFFICHAGE_HPP
#define AFFICHAGE_HPP

//public
#include <vector>

//priver
#include "plateau.hpp"
#include "joueurs.hpp"


using namespace std;


class Affichage{
private:
    // Attributs privés
    vector<liaison> liaisons;
    
public:
    // Constructeur
    Affichage();
    
    // Destructeur
    ~Affichage();

    // Méthodes publiques
    /**
     * @brief affiche le plateau mis  jour
     * 
     * @param p 
     */
    void showPlateau(Plateau p);

    /**
     * @brief Affiche la main du joueur
     * 
     * @return true 
     * @return false 
     */
    void showMain(Joueur j);

    /**
     * @brief Affiche les tickets du joueurs
     * 
     * @return true 
     * @return false 
     */
    void showTickets(Joueur j);

    /**
     * @brief Affiche le nombre de point du joueur
     * 
     * @return true 
     * @return false 
     */
    void showTicketGagnant(Joueur j);


    /**
     * @brief Affiche le nombre de wagon restant du joueur
     * 
     * @return true 
     * @return false 
     */
    void showWagonRestant(Joueur j);

    
    
};

#endif // PLATEAU_H