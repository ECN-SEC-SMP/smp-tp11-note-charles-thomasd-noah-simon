#ifndef PLATEAU_HPP
#define PLATEAU_HPP

// --- public ---
#include <vector>
#include <string>
#include <array>

// --- priver ---
#include "liaison.hpp"
#include "ville.hpp"

class Plateau {
private:
    // --- Attributs privés ---
    std::vector<Liaison> liaisons_;
    
public:
    // --- Constructeur par défault ---
    Plateau();
    // --- Constructeur ---
    Plateau(std::vector<Liaison> data);
    
    // --- Destructeur : ---
    ~Plateau();

    // --- Accesseur : ---
    bool getLiaisonOccupe(Liaison l) const;
    const std::vector<Liaison> & getLiaisons() const;



    // --- Méthodes : --- 
    

    /**
     * @brief Ville relier par un joueur spécifique
     * 
     * @param villeIsLink 
     * @param j 
     * 
     * @return true 
     * @return false 
     */
    bool isLink(const array<const Ville*,2> &villes, const Joueur *j) const;

    /**
     * @brief Vérifie si 2 Ville sont reliées par un joueur spécifique
     * 
     * @param vA 
     * @param vB 
     * @param j 
     * @return true 
     * @return false 
     */
    bool isLink(const Ville &vA, const Ville &vB, const Joueur *j) const;


    /**
     * @brief 
     * 
     * @param l 
     * @param j 
     * @return true 
     * @return false 
     */
    bool putWagon(Liaison *l, Joueur &j);

    
};

#endif // --- PLATEAU_H ---