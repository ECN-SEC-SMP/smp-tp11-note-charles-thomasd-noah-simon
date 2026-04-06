#include <iostream>
#include <fstream>
#include <sstream>
#include "liaison.hpp"
#include "ville.hpp"
#include "csvReader.hpp"

using namespace std;


vector<Liaison> Reader::operator()(string path) {
    vector<Liaison> csvParser;
    string line, csvWordData;

    ifstream file(path); //Ouvre le fichier

    //Vérification si le fichier est ouvert
    if (!file) { 
        cerr << "Erreur: Impossible d'ouvrir le fichier " << path << endl;
        return csvParser;
    }

    getline(file, line); // passe la première ligne
    while (getline(file, line)) {
        istringstream iss(line); // Séparation en ligne
        //tableau contenant city_a[0],city_b[1],color[2],lenght[3]
        array<string,4> liaisonCar;

        unsigned short cpt = 0;
        while (getline(iss, csvWordData, ',') && cpt < 4){  // séparateur virgule 
            liaisonCar[cpt] = csvWordData;
            cpt++;
        }

        //Conversion
        Ville * vA = new Ville(liaisonCar[0]);
        Ville * vB = new Ville(liaisonCar[1]);
        couleur_e colorLiaison = colorConverteur(liaisonCar[2]);
        unsigned int lenghtLiaison = stoi(liaisonCar[3]);

        //Création de la liaison
        Liaison liaison(vA, vB, colorLiaison, lenghtLiaison);
        csvParser.push_back(liaison); // liaison ajoute dans le vecteur
    }
    return csvParser;
}




