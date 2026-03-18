#include "plateau.hpp"


Plateau::Plateau(){

}

Plateau::~Plateau(){
    
}

bool Plateau::getLiaisonOccupe(){
    
}

bool Plateau::isLink(array<Ville*> villeIsLink, Joueur * j)const{
    
}


bool Plateau::putWagon(liaison l,Joueur j){
    if (l.isOccupe() != nullptr) return false;
    else {
        l.setOccupant(j);
        return true;
    }
}