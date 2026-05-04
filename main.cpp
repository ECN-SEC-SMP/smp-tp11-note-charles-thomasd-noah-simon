#include"partie.hpp"
#include <iostream>
#include "affichage.hpp"
#include "plateau.hpp"
#include "liaison.hpp"
#include "ville.hpp"
#include "couleur.hpp"

using namespace std;

int main()
{
    Partie p("./data/map.csv", "./data/ticket.csv");
    p.initialiser();
    p.lancer();


    return 0;
}