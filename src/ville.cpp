#include "ville.hpp"

using namespace std;


region_e convertRegion(string c){
    if (c == "ouest")        return region_e::OUEST;
    if (c == "centre-ouest") return region_e::CENTRE_OUEST;
    if (c == "centre-est")   return region_e::CENTRE_EST;
    if (c == "est")          return region_e::EST;
    return region_e::DEFAULT_REGION;
}


// --- Lifecycle (Constructeurs / Destructeur) ---
Ville::Ville(){
}

Ville::Ville(string nvNom)
{
    this->nom_ = nvNom;
}

Ville::Ville(string nvNom,region_e c): nom_(nvNom), region_(c){
}


Ville::~Ville(){
}

// --- Méthode Publique ---
string Ville::getNom() const {
    return nom_;
}

region_e Ville::getRegion() const{
    return region_;
}

