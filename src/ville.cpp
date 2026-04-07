#include "ville.hpp"

using namespace std;



const region_e convertCouleur(string c){
    if (c == ouest)        return region_e::OUEST;
    if (c == centre-ouest) return region_e::CENTRE_OUEST;
    if (c == centre-est)   return region_e::CENTRE_EST;
    if (c == est)          return region_e::EST;
    return region_e::DEFAULT_REGION;
}


Ville::Ville(string nvNom)
{
    this->nom = nvNom;
}

Ville::Ville(string nvNom,cote_e c): nom(nvNom), cote_(c){
}


Ville::~Ville()
{

}

