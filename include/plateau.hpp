#ifndef PLATEAU_HPP
#define PLATEAU_HPP

// --- public ---
#include <vector>
#include <array>
#include <string>
#include <stdlib.h>
#include <array>
#include <queue>
#include <algorithm>
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
    bool isLink(array<Ville*,2> villeIsLink, Joueur * j) const;

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