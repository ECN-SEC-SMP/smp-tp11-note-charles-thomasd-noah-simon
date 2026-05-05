#ifndef AFFICHAGE_HPP
#define AFFICHAGE_HPP

// --- public ---
#include <vector>

// --- priver ---
#include "plateau.hpp"
#include "joueur.hpp"

class Affichage{
private:
    // --- Attributs privés ---
    vector<Liaison> liaisons;

    // --- Méthode privés ---
    /**
     * @brief affiche la region
     * @param cote 
     */
    void region(region_e cote);

    /**
     * @brief affiche la region de la ville
     * @param cote 
     */
    void region(const Ville *v);

    /**
     * @brief Affiche le statut d'une liaison (occupée par un joueur ou vide).
     * @param l La liaison à analyser.
     * 
     * @note Affiche "[vide]" en gris si libre, ou le nom du joueur en couleur si occupée.
     */
    void statusLiaison(const Liaison &l);

    /**
     * @brief Affiche le statut de deux liaisons doubles (voies doubles).
     * @param l1 La première liaison.
     * @param l2 La deuxième liaison.
     * 
     * @note Pour chaque liaisons affiche "[vide]" en gris si libre, ou le nom du joueur en couleur 
     */
    void statusLiaison(const Liaison &l1, const Liaison &l2);

    /**
     * @brief Affiche  les rails d'une liaison simple.
     * @param l1 La liaison à afficher.
     */
    void liaison(const Liaison &l1);

    /**
     * @brief Affiche graphiquement les rails de deux liaisons parallèles.
     * @param l1 La première liaison.
     * @param l2 La deuxième liaison.
     */
    void liaison(const Liaison &l1, const Liaison &l2);

    /**
     * @brief Affiche le nom d'une ville de manière formatée.
     * @param v Pointeur vers la ville à afficher.
     * @note Gère le cas où le pointeur est nul pour éviter un crash.
     */
    void ville(const Ville *v);

    public:
    // --- Lifecycle (Constructeurs / Destructeur) ---
    Affichage();
    ~Affichage();

    // --- API Public ---
    /**
     * @brief affiche le plateau mis  jour
     * @param p 
     */
    void plateau(const Plateau &p);

    /**
     * @brief affiche le plateau mis  jour
     * @param p 
     */
    void nbJoueursPartie();


    void partieInitialise(unsigned int nbJ);
    void choixTourJoueur(const Joueur &j);
    void choixLiaisonDouble(const Joueur &j);
    void choixLiaison(const Joueur &j);




    // /**
    //  * @brief Affiche la main du joueur
    //  * 
    //  * @return true 
    //  * @return false 
    //  */
    // void mainJoueur(const Joueur &j);

    // /**
    //  * @brief Affiche les tickets du joueurs
    //  * 
    //  * @return true 
    //  * @return false 
    //  */
    // void tickets(const Joueur &j);

    // /**
    //  * @brief Affiche le nombre de point du joueur
    //  * 
    //  * @return true 
    //  * @return false 
    //  */
    // void score(const Joueur &j);


    // /**
    //  * @brief Affiche le nombre de wagon restant du joueur
    //  * 
    //  * @return true 
    //  * @return false 
    //  */
    // void wagonRestant(const Joueur &j);
};

#endif // --- PLATEAU_H ---