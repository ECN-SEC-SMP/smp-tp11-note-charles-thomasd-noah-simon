#include "affichage.hpp"
#include couleur.hpp""

using namespace std;

Affichage::Affichage(){

}

Affichage::~Affichage(){
    
}

void Affichage::showPlateau(Plateau &p){
   cout << couleurTerminal_n::BLANC << couleurTerminal_n::GRAS
        << "╔══════════════════════════════════════════════════════════════╗\n"
        << "║          LES AVENTURIERS DU RAIL — État du plateau           ║\n"
        << "╚══════════════════════════════════════════════════════════════╝\n"
        << couleurTerminal_n::RESET;
    //copie par adresse du vecteur liaisons
    auto liaisons = p->getLiaisons();
    for(n:liaisons){

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




