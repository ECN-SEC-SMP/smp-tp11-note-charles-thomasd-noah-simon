#include "ville.hpp"

using namespace std;


region_e convertRegion(string c){
    if (c == "ouest")        return region_e::OUEST;
    if (c == "centre-ouest") return region_e::CENTRE_OUEST;
    if (c == "centre-est")   return region_e::CENTRE_EST;
    if (c == "est")          return region_e::EST;
    return region_e::DEFAULT_REGION;
}

bool isEquivalentLiaison(const array<Ville*,2> & vTab1, const array<Ville*,2> & vTab2) {
   return (*vTab1[0] == *vTab2[0] && *vTab1[1] == *vTab2[1]) 
   || (*vTab1[0] == *vTab2[1] && *vTab1[1] == *vTab2[0]);
}

Ville::Ville(){
}

Ville::Ville(string nvNom)
{
    this->nom = nvNom;
}

Ville::Ville(string nvNom,region_e c): nom(nvNom), region_(c){
}


Ville::~Ville(){
}

