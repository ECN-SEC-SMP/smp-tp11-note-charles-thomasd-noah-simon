#pragma once
#include <string>
/**
 * @brief Énumération des couleurs possibles pour :
 * - les cases (rails) du plateau de jeu, ici les liaisons
 * - les joueurs
 * - les Cartes wagon
 */
enum class couleur_e{
    JAUNE = 0,
    BLANC = 1,
    VERT  = 2, 
    NOIR  = 3, 
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
inline couleur_e toCouleur_e(std::string c){
    if (c == "yellow") return couleur_e::JAUNE;
    if (c == "white")  return couleur_e::BLANC;
    if (c == "green")  return couleur_e::VERT;
    if (c == "black")  return couleur_e::NOIR;
    if (c == "blue")   return couleur_e::BLEU;
    if (c == "red")    return couleur_e::ROUGE;
    return couleur_e::COULEUR_INCONNUE;
}




/**
 * @brief Convertit l'énumération couleur_e en chaîne de caractères (string).
 */
inline const std::string toString(const couleur_e c) {
    switch (c){
        case couleur_e::JAUNE:       return "Jaune";
        case couleur_e::BLANC:       return "Blanc";
        case couleur_e::VERT:        return "Vert";
        case couleur_e::NOIR:        return "Noir";
        case couleur_e::BLEU:        return "Bleu";
        case couleur_e::ROUGE:       return "Rouge";
        case couleur_e::MULTICOLORE: return "RGB";
        default: return "unknown";
    }
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

    //couleur suplémentaire pour l'affichage
    const std::string GRIS   = "\033[90m";
}


inline const std::string  toCouleurTerminal_n(couleur_e c){
    if (c == couleur_e::JAUNE) return couleurTerminal_n::JAUNE;
    if (c == couleur_e::BLANC) return couleurTerminal_n::BLANC;
    if (c == couleur_e::VERT) return couleurTerminal_n::VERT;
    if (c == couleur_e::NOIR) return couleurTerminal_n::NOIR;
    if (c == couleur_e::BLEU) return couleurTerminal_n::BLEU;
    if (c == couleur_e::ROUGE) return couleurTerminal_n::ROUGE;
    return "";
}

