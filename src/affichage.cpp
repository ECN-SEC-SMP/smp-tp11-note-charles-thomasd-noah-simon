#include <iostream>
#include <iomanip>
#include "affichage.hpp"
#include "couleur.hpp"

using namespace std;

//constante :
static const int L = 18;

// --- Méthode Privée ---
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
    if (l.isOccupe()){
        const auto couleurOccupant = l.getOccupant()->getCouleur();
        cout << toCouleurTerminal_n(couleurOccupant)+"["+toString(couleurOccupant)+"]";
    } else {
        cout << couleurTerminal_n::GRIS+"[vide]" ;
    }
    cout << couleurTerminal_n::RESET;
}

void Affichage::statusLiaison(const Liaison &l1, const Liaison &l2){
    // Status Voie 1
    statusLiaison(l1);
    cout  << couleurTerminal_n::RESET << couleurTerminal_n::GRIS << " / ";
    // Status Voie 2
    statusLiaison(l2);
}

void Affichage::liaison(const Liaison &l1){
    const unsigned int nbRails = l1.getNbRails();
    string railsStr = string(nbRails, '=') + "(" + to_string(nbRails) + ")" + string(nbRails, '=');

    cout << toCouleurTerminal_n(l1.getCouleur()) 
         << left << setw(L) << railsStr
         //reset
         << couleurTerminal_n::RESET;
}

void Affichage::liaison(const Liaison &l1, const Liaison &l2){
    const array<unsigned int,2> nbRailsTab = {l1.getNbRails(), l2.getNbRails() };
    const array<string,2> railsStrTab = {string(nbRailsTab[0]/2, '=') + "(" + to_string(nbRailsTab[0]) + ")" + string(nbRailsTab[0]/2, '='),
                                         string(nbRailsTab[1]/2, '=') + "(" + to_string(nbRailsTab[1]) + ")" + string(nbRailsTab[1]/2, '=')};
     //liaisons 1 :
     cout << toCouleurTerminal_n(l1.getCouleur()) 
          << railsStrTab[0]
          // separation / :
          << couleurTerminal_n::RESET << couleurTerminal_n::GRIS << " / "
          //Liaison 2 :
          << couleurTerminal_n::RESET << toCouleurTerminal_n(l2.getCouleur()) 
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

// --- Lifecycle (Constructeurs / Destructeur) ---
Affichage::Affichage(){

}

Affichage::~Affichage(){
    
}

// --- Méthode Publique ---
void Affichage::plateau(const Plateau &p){
    cout << couleurTerminal_n::BLANC << couleurTerminal_n::GRAS
         << "╔══════════════════════════════════════════════════════════════╗\n"
         << "║          LES AVENTURIERS DU RAIL — État du plateau           ║\n"
         << "╚══════════════════════════════════════════════════════════════╝\n"
         << couleurTerminal_n::RESET;
    //copie par adresse du vecteur liaisons
    const auto liaisons = p.getLiaisons();
    region_e lastRegion = region_e::DEFAULT_REGION;
    unsigned int cptNumero = 0; 

    if (liaisons.empty()) return;
    
    for (unsigned int i = 0; i < liaisons.size() - 1; ++i) {
        const auto& n = liaisons[i];
        const auto& nextN = liaisons[i + 1]; 
        cptNumero++;

        //On sauvegarde une fois pour pas appeler plusieurs fois
        const auto villesTab = n.getVilles();
        region_e regionActuelle = villesTab[0]->getRegion();

        //Si la region change
        if (regionActuelle!=lastRegion)
        {
            region(regionActuelle);
            lastRegion = regionActuelle;
        }

        //Affiche le Numéro de sélection
        cout << "[" << setfill('0') << setw(2) << right << cptNumero << "] " << setfill(' ');

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
            if (i >= liaisons.size() - 1) break; // empèche de dépasser la taille maxium de liaisons
        }  
        cout << endl; // retour à la ligne
        
    }
}


void Affichage::nbJoueursPartie(){
    cout << "Entrez le nombre de joueurs (2-4) : ";
}   

void Affichage::partieInitialise(unsigned int nbJ){
    cout << "Partie initialisée avec " << nbJ << " joueurs." << endl;
}


void Affichage::choixJoueur(const Joueur& j, const string& txtQuestion, const vector<std::string>& txtChoix){
    const couleur_e c = j.getCouleur();

    cout << "Joueur "
         << toCouleurTerminal_n(c) << toString(c)
         << couleurTerminal_n::RESET << " "
         << txtQuestion << endl;

    for (size_t i = 0; i < txtChoix.size(); ++i) {
        cout << i + 1 << ". " << txtChoix[i] << endl;
    }
}




// void Affichage::mainJoueur(Joueur j){
//     // for(n :j.getMain()){
//     //     cout << n.  <<endl;
//     // }
// }

// void Affichage::tickets(Joueur j){
//     // for(n :j.getTickets()){
//     //     cout << n.   <<endl;
//     // }
// }

// void Affichage::score(Joueur j){
//     // for(n :j.getTickets()){
//     //     cout << n.   <<endl;
//     // }
// }

// void Affichage::wagonRestant(Joueur j){
//     // for(n :j.getTickets()){
//     //     cout << n.   <<endl;
//     // }
// }




