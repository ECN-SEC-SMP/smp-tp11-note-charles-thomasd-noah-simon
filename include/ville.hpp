#pragma once
#include <string>
using namespace std;


enum class region_e{
    OUEST,
    CENTRE_OUEST,
    CENTRE_EST,
    EST,
    DEFAULT_REGION
}


class Ville
{
private:
    string nom;
    region_e region_
public:
    Ville();
    Ville(string nvNom);
    Ville(string nvNom,region_e c);
    ~Ville();
};

const region_e convertRegion(std::string c);