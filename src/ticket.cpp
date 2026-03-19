#include "ticket.hpp"

ticket::ticket(ville* ville1, ville* ville2) : carte(), isTermine(false){
    this->villes = {ville1, ville2};
}

array<ville*,2> ticket::getVilles(){
    return villes;
}

void ticket::setIsTermine(){
    isTermine = true;
}

ticket::~ticket(){}