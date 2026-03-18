#include "ticket.hpp"

ticketVille::ticketVille(ville ville1, ville ville2) : carte(), ville1(ville1), ville2(ville2), estTermine(false){
    this->ville1 = ville1;
    this->ville2 = ville2;
}

void ticketVille::setEstTermine(){
    estTermine = true;
}