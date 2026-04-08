#include"partie.hpp"
#include <iostream>
#include "affichage.hpp"
#include "plateau.hpp"
#include "liaison.hpp"
#include "ville.hpp"
#include "couleur.hpp"

using namespace std;

//Declarations:
void testPlateau();

int main(int argc, char const *argv[])
{
    Partie p("./data/map.csv", "./data/tickets.csv");
    testPlateau();
    return 0;
}


void testPlateau() {
    // Création de quelques villes
    Ville* losAngeles  = new Ville("Los Angeles",  region_e::OUEST);
    Ville* lasVegas    = new Ville("Las Vegas",    region_e::OUEST);
    Ville* sanFrancisco= new Ville("San Francisco",region_e::OUEST);
    Ville* saltLake    = new Ville("Salt Lake City",region_e::CENTRE_OUEST);


    // Liaisons simples (une seule couleur)
    Liaison l1(losAngeles,  lasVegas,     couleur_e::ROUGE,   3);
    Liaison l2(sanFrancisco,saltLake,     couleur_e::VERT, 5);

    // Liaison double (même paire de villes, deux couleurs différentes)
    Liaison l3(losAngeles,  sanFrancisco, couleur_e::JAUNE,  3);
    Liaison l4(losAngeles,  sanFrancisco, couleur_e::NOIR,   3);

    // Construction du plateau
    vector<Liaison> liaisons = { l1, l2, l3, l4 };
    Plateau plateau(liaisons);

    // Test  Plateau
    Affichage aff;
    aff.plateau(plateau);

    // Nettoyage
    delete losAngeles;
    delete lasVegas;
    delete sanFrancisco;
    delete saltLake;
}