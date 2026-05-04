#include "input.hpp"
#include "iostream"

using namespace std;

// --- Lifecycle (Constructeurs / Destructeur) ---
Input::Input(){

}
    
Input::~Input(){
    
}

// --- API Public ---
unsigned int Input::entier(unsigned int min, unsigned int max){
    unsigned int choixEntier;
    while (!(cin >> choixEntier && choixEntier >= min && choixEntier <= max)) {   
        cout << "[ERREUR], tapez un nombre entre " << min << " et " << max << " : ";
        cin.clear(); 
        cin.ignore(1000, '\n'); 
    }
    return choixEntier;
}