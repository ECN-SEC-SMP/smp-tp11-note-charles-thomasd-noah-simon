#include "carteTicket.hpp"



CarteTicket::CarteTicket(){

}


CarteTicket::CarteTicket(Ville * vA, Ville * vB) : villes_({vA, vB}), valider_(false)
{
}

//possiblement améliorer avec une const &
CarteTicket::CarteTicket(array<Ville*,nbVilles_> v) : villes_(v),valider_(false)
{
}