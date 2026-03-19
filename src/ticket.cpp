#include "ticket.hpp"

ticket::ticket(ville ville1, ville ville2) : carte(), ville1(ville1), ville2(ville2), isTermine(false){
    this->ville1 = ville1;
    this->ville2 = ville2;
}

void ticket::setIsTermine(){
    isTermine = true;
}

ticket::~ticket(){}