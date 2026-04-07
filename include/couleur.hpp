#pragma once
#include <string>
/**
 * @brief Énumération des couleurs possibles pour :
 * - les cases (rails) du plateau de jeu, ici les liaisons
 * - les joueurs
 * - les Cartes wagon
 */
enum class couleur_e{
    JAUNE,
    BLANC,
    VERT, 
    NOIR, 
    BLEU, 
    ROUGE,
    MULTICOLORE,
    COULEUR_INCONNUE
};

/**
 * @brief convertie
 * 
 * @param c 
 * @return couleur_e 
 */
inline couleur_e colorConverteur(std::string c){
    if (c == "yellow") return couleur_e::JAUNE;
    if (c == "white")  return couleur_e::BLANC;
    if (c == "green")  return couleur_e::VERT;
    if (c == "black")  return couleur_e::NOIR;
    if (c == "blue")   return couleur_e::BLEU;
    if (c == "red")    return couleur_e::ROUGE;
    return COULEUR_INCONNUE;
}

namespace couleurTerminal_n{
    //reset
    const std::string RESET = "\033[0m";  // remet à zéro gras ET couleur

    //gras
    const std::string GRAS  = "\033[1m";

    //Couleur
    const std::string JAUNE   = "\033[33m";
    const std::string BLANC   = "\033[97m";
    const std::string VERT    = "\033[32m";
    const std::string NOIR    = "\033[90m";   
    const std::string BLEU    = "\033[34m";
    const std::string ROUGE   = "\033[31m";
}


inline const couleurTerminal_n convertCouleur(couleur_e c){
    if (c == couleur_e::JAUNE) return couleurTerminal_n::JAUNE;
    if (c == couleur_e::BLANC) return couleurTerminal_n::BLANC;
    if (c == couleur_e::VERT) return couleurTerminal_n::VERT;
    if (c == couleur_e::NOIR) return couleurTerminal_n::NOIR;
    if (c == couleur_e::BLEU) return couleurTerminal_n::BLEU;
    if (c == couleur_e::ROUGE) return couleurTerminal_n::ROUGE;
    return "";
}