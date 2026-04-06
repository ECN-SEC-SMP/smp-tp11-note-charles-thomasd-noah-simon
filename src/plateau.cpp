#include "plateau.hpp"


Plateau::Plateau(){

}

Plateau::~Plateau(){
    
}

bool Plateau::getLiaisonOccupe() const{
    
}

bool Plateau::isLink(array<Ville*,2> villeIsLink, Joueur * j)const{
    
}


bool Plateau::putWagon(Liaison l,Joueur j){
    if (l.isOccupe()) return false;
    else {
        l.setOccupant(&j);
        return true;
    }
}