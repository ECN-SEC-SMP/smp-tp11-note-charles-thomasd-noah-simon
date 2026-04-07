#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include "liaison.hpp"
#include "ville.hpp"
#include "csvReader.hpp"
#include "piocheTicket.hpp"

using namespace std;


vector<Liaison> Reader::readMaps(string path) {
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
        //tableau contenant city_a[0],city_b[1],region_a[2],region_b[3],color[4],lenght[5]
        array<string,6> liaisonCar;

        unsigned short cpt = 0;
        while (getline(iss, csvWordData, ',') && cpt < 6){  // séparateur virgule 
            liaisonCar[cpt] = csvWordData;
            cpt++;
        }

        //Conversion
        Ville * vA = new Ville(liaisonCar[0],convertRegion(liaisonCar[2]));
        Ville * vB = new Ville(liaisonCar[1],convertRegion(liaisonCar[3]));
        couleur_e colorLiaison = colorConverteur(liaisonCar[4]);
        unsigned int lenghtLiaison = stoi(liaisonCar[5]);

        //Création de la liaison
        Liaison liaison(vA, vB, colorLiaison, lenghtLiaison);
        csvParser.push_back(liaison); // liaison ajoute dans le vecteur
    }
    return csvParser;
}



PiocheTicket Reader::readTickets(string path) {
    vector<CarteTicket> csvParser;
    string line, csvWordData;

    ifstream file(path); //Ouvre le fichier

    //Vérification si le fichier est ouvert
    if (!file) { 
        cerr << "Erreur: Impossible d'ouvrir le fichier " << path << endl;
        return PiocheTicket();
    }

    getline(file, line); // passe la première ligne
    while (getline(file, line)) {
        istringstream iss(line); // Séparation en ligne
        //tableau contenant ticket_id[0],city_a[1],city_b[2]
        array<string,3> piocheCar;

        unsigned short cpt = 0;
        while (getline(iss, csvWordData, ',') && cpt < 3){  // séparateur virgule 
            piocheCar[cpt] = csvWordData;
            cpt++;
        }

        //Conversion
        //tickedID non utilisé
        Ville * vA = new Ville(piocheCar[1]);
        Ville * vB = new Ville(piocheCar[2]);

        //Création de la liaison
        CarteTicket ticket(vA, vB);
        csvParser.push_back(ticket); // liaison ajoute dans le vecteur
    }
    return PiocheTicket(csvParser);
}



