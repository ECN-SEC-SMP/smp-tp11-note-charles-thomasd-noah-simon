#ifndef PLATEAU_HPP
#define PLATEAU_HPP

//public
#include <vector>
#include <array>
#include <string>
#include <stdlib.h>
//priver
#include "liaison.hpp"
#include "ville.hpp"



using namespace std;


class Plateau {
private:
    // Attributs privés
    vector<Liaison> liaisons;
    
public:
    // Constructeur
    Plateau(vector<vector<string>>);
    
    // Destructeur
    ~Plateau();

    // Méthodes publiques
    bool getLiaisonOccupe() const;


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
    bool putWagon(Liaison l, Joueur j) ;
    
};

#endif // PLATEAU_H