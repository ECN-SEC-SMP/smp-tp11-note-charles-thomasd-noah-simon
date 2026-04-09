#ifndef READER_HPP
#define READER_HPP

#include <vector>
#include <string>
#include <map>
#include "liaison.hpp"
#include "piocheTicket.hpp"

class Reader {
    private : 
    // --- Attributs privés ---
    std::map<string, Ville*> villeMap;  // Initialisation de la map statique
    
    // --- Méthode privés ---
    Ville* getVillePtr(std::string nom, region_e r); 

    public: 
    // --- Lifecycle (Constructeurs / Destructeur) ---
    Reader();
    ~Reader();

    // --- API Public ---
    std::vector<Liaison> readMaps(std::string path);
    PiocheTicket readTickets(std::string path);
};

#endif // --- READER_H ---
