#ifndef AFFICHAGE_HPP
#define AFFICHAGE_HPP

//public
#include <vector>

//priver
#include "plateau.hpp"
#include "joueur.hpp"

class Affichage{
private:
    // Attributs privés
    vector<Liaison> liaisons;

    //méthodes privés
    
    void region(region_e cote);
    void statusLiaison(const Liaison &l);
    void statusLiaison(const Liaison &l1, const Liaison &l2);
    void liaison(const Liaison &l1);
    void liaison(const Liaison &l1, const Liaison &l2);
    void ville(const Ville *v);

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
    void plateau(Plateau &p);

    /**
     * @brief Affiche la main du joueur
     * 
     * @return true 
     * @return false 
     */
    void mainJoueur(Joueur j);

    /**
     * @brief Affiche les tickets du joueurs
     * 
     * @return true 
     * @return false 
     */
    void tickets(Joueur j);

    /**
     * @brief Affiche le nombre de point du joueur
     * 
     * @return true 
     * @return false 
     */
    void score(Joueur j);


    /**
     * @brief Affiche le nombre de wagon restant du joueur
     * 
     * @return true 
     * @return false 
     */
    void wagonRestant(Joueur j);

    
    
};

#endif // PLATEAU_H