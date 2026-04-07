#include "affichage.hpp"
#include couleur.hpp""

using namespace std;

Affichage::Affichage(){

}

Affichage::~Affichage(){
    
}

Affichage::showCote(region_e cote){
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
    }
    cout << string(48, '-') << RESET << "\n";
}

void Affichage::showPlateau(Plateau &p){
    cout << couleurTerminal_n::BLANC << couleurTerminal_n::GRAS
         << "╔══════════════════════════════════════════════════════════════╗\n"
         << "║          LES AVENTURIERS DU RAIL — État du plateau           ║\n"
         << "╚══════════════════════════════════════════════════════════════╝\n"
         << couleurTerminal_n::RESET;
    //copie par adresse du vecteur liaisons
    auto liaisons = p->getLiaisons();

    showCote(region_e::OUEST);

    for(n:liaisons){
        //Ville 1 :
        cout << couleurTerminal_n::BLANC << couleurTerminal_n::GRAS
             << n.getVilles()[0] << "     "  
             //liaisons :
             << couleurTerminal_n::RESET << couleurTerminal_n::convertCouleur(n.getCouleur()) 
             << string(n.getNbRails()/2, '=') << getNbRails() << string(n.getNbRails()/2, '=')
             //Ville 2 :
             << couleurTerminal_n::RESET << couleurTerminal_n::BLANC << couleurTerminal_n::GRAS
             << n.getVilles()[1] 
             //status :
             << n.isOccupe(); << endl;
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




