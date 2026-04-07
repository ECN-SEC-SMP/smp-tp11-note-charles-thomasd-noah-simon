#include "plateau.hpp"


Plateau::Plateau(vector<Liaison> data) : liaisons(data){
}

Plateau::~Plateau(){
    
}

bool Plateau::getLiaisonOccupe(Liaison l) const{
    return l.isOccupe();
    
}

liaisons * Plateau::getLiaisons() const{
    return &liaisons;
}


//code à vérifier mais c'est chatgpt donc pas de raison
bool Plateau::isLink(array<Ville*,2> villeIsLink, Joueur * j)const{
    if (j == nullptr || villeIsLink[0] == nullptr || villeIsLink[1] == nullptr)
        return false;

    // Si les deux villes sont les mêmes
    if (villeIsLink[0] == villeIsLink[1])
        return true;

    queue<Ville*> aVisiter;
    vector<Ville*> visitees;

    aVisiter.push(villeIsLink[0]);
    visitees.push_back(villeIsLink[0]);

    while (!aVisiter.empty())
    {
        Ville* villeCourante = aVisiter.front();
        aVisiter.pop();

        // Parcours de toutes les liaisons du plateau
        for(const Liaison& liaison : liaisons)
        {
          
            // On ne garde que les liaisons occupées par le joueur
            if (liaison.getOccupant() != j)
                continue;

            std::array<Ville*,2> villes = liaison.getVilles();

            Ville* voisine = nullptr;

            if (villes[0] == villeCourante)
                voisine = villes[1];
            else if (villes[1] == villeCourante)
                voisine = villes[0];

            // Si la liaison ne touche pas la ville courante
            if (voisine == nullptr)
                continue;

            // Si on atteint la ville cible
            if (voisine == villeIsLink[1])
                return true;

            // Si pas encore visitée, on l'ajoute
            if (std::find(visitees.begin(), visitees.end(), voisine) == visitees.end())
            {
                visitees.push_back(voisine);
                aVisiter.push(voisine);
            }
        }
    }

    return false;
}




bool Plateau::putWagon(Liaison l,Joueur j){
    if (l.isOccupe()) return false;
    else {
        l.setOccupant(&j);
        return true;
    }
}