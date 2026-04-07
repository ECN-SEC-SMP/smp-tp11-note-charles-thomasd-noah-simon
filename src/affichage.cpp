#include <iostream>
#include "affichage.hpp"
#include "couleur.hpp"

using namespace std;

Affichage::Affichage(){

}

Affichage::~Affichage(){
    
}

void Affichage::showRegion(region_e cote){
    switch (cote){
        case region_e::OUEST:
            cout << couleurTerminal_n::GRIS << "-- CÔTE OUEST --";
        break;

        case region_e::CENTRE_OUEST:
            cout << couleurTerminal_n::GRIS << "-- CENTRE-OUEST ";
        break;

        case region_e::CENTRE_EST:
            cout << couleurTerminal_n::GRIS << "-- CENTRE-EST --";
        break;

        case region_e::EST:
            cout << couleurTerminal_n::GRIS << "-- CÔTE EST ----";
        break;

        default:
        break;
    }
    cout << string(48, '-') << couleurTerminal_n::RESET << "\n";
}

void Affichage::showPlateau(Plateau &p){
    cout << couleurTerminal_n::BLANC << couleurTerminal_n::GRAS
         << "╔══════════════════════════════════════════════════════════════╗\n"
         << "║          LES AVENTURIERS DU RAIL — État du plateau           ║\n"
         << "╚══════════════════════════════════════════════════════════════╝\n"
         << couleurTerminal_n::RESET;
    //copie par adresse du vecteur liaisons
    auto liaisons = p.getLiaisons();

    showRegion(region_e::OUEST);
    for (unsigned int i = 0; i < liaisons.size() - 1; ++i) {
        const auto& n = liaisons[i];
        const auto& nextN = liaisons[i + 1]; 

        //On sauvegarde une fois pour pas appeler plusierus fois
        const unsigned int nbRails = n.getNbRails();
        const array<Ville*,2> villesTab = n.getVilles();
        const array<Ville*,2> nextVillesTab = (nextN).getVilles();;

        if (!isEquivalentLiaison(villesTab,nextVillesTab))
        {
            cout << couleurTerminal_n::BLANC << couleurTerminal_n::GRAS
            //Ville 1 :
             << n.getVilles()[0] << "     "  
             //liaisons :
             << couleurTerminal_n::RESET << convertCouleur(n.getCouleur()) 
             << string(nbRails/2, '=') << nbRails << string(nbRails/2, '=')
             //Ville 2 :
             << couleurTerminal_n::RESET << couleurTerminal_n::BLANC << couleurTerminal_n::GRAS
             << n.getVilles()[1] 
             //status :
             << n.isOccupe() << endl;
        }else {
            const unsigned int nextNnbRails = nextN.getNbRails();

            cout << couleurTerminal_n::BLANC << couleurTerminal_n::GRAS
            //Ville 1 :
             << n.getVilles()[0] << "     "  
             //liaisons 1 :
             << couleurTerminal_n::RESET << convertCouleur(n.getCouleur()) 
             << string(nbRails/2, '=') << nbRails << string(nbRails/2, '=')
             
             << couleurTerminal_n::RESET << couleurTerminal_n::GRIS << " / "
             //Liaison 2 :
             << couleurTerminal_n::RESET << convertCouleur(nextN.getCouleur()) 
             << string(nextNnbRails/2, '=') << nextNnbRails << string(nextNnbRails/2, '=')
             //Ville 2 :
             << couleurTerminal_n::RESET << couleurTerminal_n::BLANC << couleurTerminal_n::GRAS
             << n.getVilles()[1] 
             //status :
             << n.isOccupe() << endl;
             i++;
        }
    }
}

void Affichage::showMain(Joueur j){
    // for(n :j.getMain()){
    //     cout << n.  <<endl;
    // }
}

void Affichage::showTickets(Joueur j){
    // for(n :j.getTickets()){
    //     cout << n.   <<endl;
    // }
}

void Affichage::showTicketGagnant(Joueur j){
    // for(n :j.getTickets()){
    //     cout << n.   <<endl;
    // }
}

void Affichage::showWagonRestant(Joueur j){
    // for(n :j.getTickets()){
    //     cout << n.   <<endl;
    // }
}




