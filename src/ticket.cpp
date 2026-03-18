#include "ticket.hpp"

/**
 * @brief Construit un nouveau ticket Ville
 * 
 * @param ville1 
 * @param ville2 
 */
ticket::ticket(ville ville1, ville ville2) : carte(), ville1(ville1), ville2(ville2), isTermine(false){
    this->ville1 = ville1;
    this->ville2 = ville2;
}

/**
 * @brief Définit si le ticket est terminé ou non
 * Equivalent de le poser face visible sur la table
 */
void ticket::setisTermine(){
    isTermine = true;
}

ticket::~ticket(){}