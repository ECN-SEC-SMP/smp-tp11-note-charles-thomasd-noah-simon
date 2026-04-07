#pragma once
#include "carte.hpp"
#include <memory>
#include <vector>

using namespace std;

class Pioche {
private:


public:
    Pioche();
    ~Pioche();
    virtual bool estVide() const = 0;
    virtual unique_ptr<Carte> piocher() = 0;
};

