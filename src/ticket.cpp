#include "ticket.hpp"

ticketVille::ticketVille() : carte(), ville1(""), ville2(""), estTermine(false) {}

void ticketVille::setEstTermine(){
    estTermine = true;
}