#include "carteTicket.hpp"

CarteTicket::CarteTicket(Ville* ville1, Ville* ville2) : isTermine(false){
    this->villes = {ville1, ville2};
}

CarteTicket::~CarteTicket(){}


array<Ville*,2> CarteTicket::getVilles(){
    return villes;
}

void CarteTicket::setIsTermine(){
    isTermine = true;
}

