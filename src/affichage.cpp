#include <iostream>
#include <iomanip>
#include "affichage.hpp"
#include "couleur.hpp"

using namespace std;

static const int L = 16;


Affichage::Affichage(){

}

Affichage::~Affichage(){
    
}

void Affichage::region(const Ville *v){
    if (v == nullptr) {
        cout << couleurTerminal_n::ROUGE <<left << setw(L) << "error";
        return;
    }
    region(v->getRegion());
}

void Affichage::region(region_e cote){
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

void Affichage::statusLiaison(const Liaison &l){
    cout << (l.isOccupe() ? couleurTerminal_n::VERT+"["+convertCouleur(l.getOccupant()->getCouleur())+"]" : 
                            couleurTerminal_n::GRIS+"[vide]")
         << couleurTerminal_n::RESET;
}

void Affichage::statusLiaison(const Liaison &l1, const Liaison &l2){
    // Status Voie 1
    cout << (l1.isOccupe() ? couleurTerminal_n::VERT+"["+convertCouleur(l1.getOccupant()->getCouleur())+"]" : 
                            couleurTerminal_n::GRIS+"[vide]")
         << couleurTerminal_n::RESET << couleurTerminal_n::GRIS << " / ";
    // Status Voie 2
    cout << (l1.isOccupe() ? couleurTerminal_n::VERT+"["+convertCouleur(l1.getOccupant()->getCouleur())+"]" : 
                            couleurTerminal_n::GRIS+"[vide]")
         << couleurTerminal_n::RESET;
}

void Affichage::liaison(const Liaison &l1){
    const unsigned int nbRails = l1.getNbRails();
    string railsStr = string(nbRails, '=') + "(" + to_string(nbRails) + ")" + string(nbRails, '=');

    cout << convertCouleur(l1.getCouleur()) 
         << left << setw(L) << railsStr
         //reset
         << couleurTerminal_n::RESET;
}

void Affichage::liaison(const Liaison &l1, const Liaison &l2){
    const array<unsigned int,2> nbRailsTab = {l1.getNbRails(), l2.getNbRails() };
    const array<string,2> railsStrTab = {string(nbRailsTab[0]/2, '=') + "(" + to_string(nbRailsTab[0]) + ")" + string(nbRailsTab[0]/2, '='),
                                         string(nbRailsTab[1]/2, '=') + "(" + to_string(nbRailsTab[1]) + ")" + string(nbRailsTab[1]/2, '=')};
     //liaisons 1 :
     cout << convertCouleur(l1.getCouleur()) 
          << railsStrTab[0]
          // separation / :
          << couleurTerminal_n::RESET << couleurTerminal_n::GRIS << " / "
          //Liaison 2 :
          << couleurTerminal_n::RESET << convertCouleur(l2.getCouleur()) 
          << railsStrTab[1]
          //reset de la couleur
         << couleurTerminal_n::RESET;

    //padding a droite d'espace
    int reste = L - (railsStrTab[0].length() + railsStrTab[1].length() + 3);
    if (reste > 0) cout << string(reste, ' ');
    }

void Affichage::ville(const Ville *v){
    if (v == nullptr) {
        cout << couleurTerminal_n::ROUGE <<left << setw(L) << "error";
        return;
    }
    
    cout << couleurTerminal_n::BLANC << couleurTerminal_n::GRAS
             << left << setw(L) << v->getNom()
             << couleurTerminal_n::RESET;
}

void Affichage::plateau(Plateau &p){
    cout << couleurTerminal_n::BLANC << couleurTerminal_n::GRAS
         << "╔══════════════════════════════════════════════════════════════╗\n"
         << "║          LES AVENTURIERS DU RAIL — État du plateau           ║\n"
         << "╚══════════════════════════════════════════════════════════════╝\n"
         << couleurTerminal_n::RESET;
    //copie par adresse du vecteur liaisons
    auto liaisons = p.getLiaisons();

    region(region_e::OUEST);
    for (unsigned int i = 0; i < liaisons.size() - 1; ++i) {
        const auto& n = liaisons[i];
        const auto& nextN = liaisons[i + 1]; 

        //On sauvegarde une fois pour pas appeler plusieurs fois
        const auto villesTab = n.getVilles();

        //Afficher Ville 1 :
        ville(villesTab[0]);

        if (!(n == nextN)) {
            //Affiche liaisons :
            liaison(n);
            //Afficher Ville 1 :
            ville(villesTab[1]);
            //status simple :
            statusLiaison(n);
        }else {     
            //affiche liaisons double :       
            liaison(n, nextN);
            //Afficher Ville 1 :
            ville(villesTab[1]);
            //status double :
            statusLiaison(n,nextN);
            i++; //skip la prochaine liaison du vecteur
        }  
        cout << endl; // retour à la ligne
    }
}

void Affichage::mainJoueur(Joueur j){
    // for(n :j.getMain()){
    //     cout << n.  <<endl;
    // }
}

void Affichage::tickets(Joueur j){
    // for(n :j.getTickets()){
    //     cout << n.   <<endl;
    // }
}

void Affichage::score(Joueur j){
    // for(n :j.getTickets()){
    //     cout << n.   <<endl;
    // }
}

void Affichage::wagonRestant(Joueur j){
    // for(n :j.getTickets()){
    //     cout << n.   <<endl;
    // }
}




