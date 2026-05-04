#ifndef INPUT_HPP
#define INPUT_HPP

class Input{
private:
     
public:
    // --- Lifecycle (Constructeurs / Destructeur) ---
    Input();
    ~Input();

    // --- API Public ---
    unsigned int entier(unsigned int min,unsigned int max);

    // void wagonRestant(const Joueur &j);
};

#endif // --- INPUT.HPP ---