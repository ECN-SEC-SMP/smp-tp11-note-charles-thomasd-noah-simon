#include "carteTicket.hpp"


CarteTicket::CarteTicket(){
   //this->villes = {ville1, ville2};
}

CarteTicket::~CarteTicket(){}


array<Ville*,2> CarteTicket::getVilles(){
    return villes;
}

void CarteTicket::setIsTermine(){
    isTermine = true;
}

