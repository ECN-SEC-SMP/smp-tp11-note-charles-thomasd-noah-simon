#include "carteTicket.hpp"

using namespace std;

CarteTicket::CarteTicket(){

}

CarteTicket::CarteTicket(Ville * vA, Ville * vB) : villes_({vA, vB}), valider_(false)
{
}

//possiblement améliorer avec une const &
CarteTicket::CarteTicket(array<Ville*,nbVilles_> v) : villes_(v),valider_(false)
{
}

CarteTicket::~CarteTicket(){

}


array<Ville*,CarteTicket::nbVilles_> CarteTicket::getVilles() const{
    return villes_;
}

void CarteTicket::setValider(){
    valider_ = true;
}
