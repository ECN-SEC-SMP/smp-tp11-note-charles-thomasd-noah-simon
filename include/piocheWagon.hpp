#pragma once
#include "carteWagon.hpp"
#include "pioche.hpp"
#include <vector>

using namespace std;

class PiocheWagon : Pioche{
private:
    // --- Attributs privés ---
    vector<CarteWagon*> defausse_;

    // --- Méthodes privées ---
    /**
     * @brief Génère les cartes wagon
     * 
     * @return vector<carteWagon> 
     */
    void genWagons();

public:
    // --- Constructeur par défault ---
    PiocheWagon();
    // --- Destructeur ---
    ~PiocheWagon();


    // --- Méthodes publiques --- 

    /**
     * @brief Réinitialise la pioche de cartes wagon lorsque celle-ci est vide
     * Les cartes utilisées et placées dans la défausse (supprimées) deviennent la nouvelle pioche. 
     */
    void resetPioche();

    /**
     * @brief ajoute une carte jouer à la défausse
     * 
     * @param c 
     */
    void addDefausse(CarteWagon *c);



    // --- Méthodes héritées ---
    /**
     * @brief Vérifie si la pioche est vide
     * 
     * @return true 
     * @return false 
     */
    bool estVide() const override;

    /**
     * @brief Piocher une carte wagon de la pioche pour la donner à un joueur
     * et la supprime de la pioche
     * 
     * @return carteWagon 
     */
    const Carte * piocher() override;
};

