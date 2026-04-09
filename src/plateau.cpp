#include "plateau.hpp"
#include <queue>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

Plateau::Plateau(){
    
}

Plateau::Plateau(vector<Liaison> data) : liaisons_(data){
}

Plateau::~Plateau(){
    
}

bool Plateau::getLiaisonOccupe(Liaison l) const{
    return l.isOccupe();
}

const vector<Liaison> & Plateau::getLiaisons() const{
    return liaisons_;
}


bool Plateau::isLink(const array<const Ville*,2> &villes, const Joueur *j) const {
    if (!isLink(villes[0], villes[1], j)) return false;
    else return true;
}

bool Plateau::isLink(const Ville &vA, const Ville &vB, const Joueur *j) const {
    if (j == nullptr) return false; // Si le pointeur est null on sort

    //On crée une map qui stocke l'ensemble des villes qui sont accesibles à partir d'une ville source
    map<const Ville*, vector<const Ville*>> villeRelierParJoueur;
    for (unsigned int i = 0; i < liaisons_.size(); i++) {
        if (liaisons_[i].getOccupant() == j) {
            const auto villeRelierTab = liaisons_[i].getVilles();
            //Ville 1
            villeRelierParJoueur[villeRelierTab[0]].push_back(villeRelierTab[1]);
            //Ville 2
            villeRelierParJoueur[villeRelierTab[1]].push_back(villeRelierTab[0]);
        }
    }

    //if va || vb ne sont pas présent dans la map return false 
    if (villeRelierParJoueur.find(&vA) == villeRelierParJoueur.end() ||
        villeRelierParJoueur.find(&vB) == villeRelierParJoueur.end()) 
    {
        return false;
    }

    //On vérifie si les 2 villes ne sont pas cotes à cotes
    //const auto& vosionsVa = villeRelierParJoueur[&vA];
    //if (find(vosionsVa.begin(), vosionsVa.end(), &vB) != vosionsVa.end())
    //{
    //    //Si il est dans les voisins direct return true
    //    return true;
    //}

    queue<const Ville*> toVisite; toVisite.push(&vA);
    //vector<const Ville*> visiter; visiter.push_back(&vA); // Plus optimisée avec set (Gemini)
    set<const Ville*> visiter; visiter.insert(&vA);

    while (!toVisite.empty()){
        const Ville* visiteActuelle = toVisite.front();
        toVisite.pop();  //Suprimer la ville actuelle de la queue
        const auto& vosionsVisiteActuelle = villeRelierParJoueur[visiteActuelle];

        if (find(vosionsVisiteActuelle.begin(), vosionsVisiteActuelle.end(), &vB) != vosionsVisiteActuelle.end())
        {
            //Si il est dans les voisins direct return true
            return true;
        } else {
            // sinon ajouter dans la queue tous les voisins qui nont pas déjà été visiter 
            for(const auto &n : vosionsVisiteActuelle){
                if (visiter.find(n) == visiter.end())   //(find(visiter.begin(), visiter.end(), n) == visiter.end()) // Plus optimisée avec set (Gemini)
                {
                    toVisite.push(n);
                    //Ajouter la ville actuelle dans la list des villes déjà visiteée
                    visiter.insert(n);
                }
            }
        }
    }
    return false;
}


bool Plateau::putWagon(Liaison *l, Joueur &j){
    if (l->isOccupe() ||(l == nullptr)) {
        return false;
    } else {
        l->setOccupant(&j);
        return true;
    }
}