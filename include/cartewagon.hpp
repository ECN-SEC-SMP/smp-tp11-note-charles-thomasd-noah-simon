#pragma once
#include "carte.hpp"
#include <string>

using namespace std;

class carteWagon : public carte
{
private:
    string couleur;
public:
    carteWagon(string couleur);
    string getCouleur();
    ~carteWagon();
};