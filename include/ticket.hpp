#pragma once
#include "carte.hpp"
#include <string>

using namespace std;

class ticketVille : public carte
{
private:
    Ville ville1;
    Ville ville2;
    bool estTermine;
public:
    ticketVille(Ville ville1, Ville ville2);
    void getVille1();
    void getVille2();
    void setEstTermine();
    ~ticketVille();
};