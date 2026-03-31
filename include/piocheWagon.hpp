#include "carteWagon.hpp"
#include "pioche.hpp"
#include <vector>

using namespace std;

class PiocheWagon : Pioche{
private:
    vector<CarteWagon> pioche_;
    vector<CarteWagon> defausse_;


    /**
     * @brief Génère les cartes wagon
     * 
     * @return vector<carteWagon> 
     */
    void genWagons();

public:
    /**
     * @brief Constructeur de la classe PiocheWagon
     * 
     * @note génère les cartes wagon 
     */
    PiocheWagon();
    ~PiocheWagon();


    /**
     * @brief Réinitialise la pioche de cartes wagon lorsque celle-ci est vide
     * Les cartes utilisées et placées dans la défausse (supprimées) deviennent la nouvelle pioche. 
     */
    void resetPioche();
    void addDefausse(const CarteWagon& carte);


    //**Vérifie si la pioche est vide */
    bool estVide() const override;

    /**
     * @brief Piocher une carte wagon de la pioche pour la donner à un joueur
     * et la supprime de la pioche
     * 
     * @return carteWagon 
     */
    unique_ptr<Carte> piocher() override;
};

