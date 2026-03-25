#include "ticket.hpp"

Ticket::Ticket(ville* ville1, ville* ville2) : isTermine(false){
    this->villes = {ville1, ville2};
}

array<ville*,2> Ticket::getVilles(){
    return villes;
}

void Ticket::setIsTermine(){
    isTermine = true;
}

Ticket::~Ticket(){}