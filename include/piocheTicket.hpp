#include "carteTicket.hpp"
#include "pioche.hpp"
#include <vector>

using namespace std;

class PiocheTicket : Pioche {
private:
    vector<CarteTicket> pioche_;


public:
    /**
     * @brief Constructeur de la classe Pioche ticket
     * 
     */
    PiocheTicket();

    ~PiocheTicket();

    //de la classe fille
    bool estVide() const override;
    unique_ptr<Carte> piocher() override;
};
