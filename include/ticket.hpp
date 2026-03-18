#pragma once
#include "carte.hpp"
#include "ville.hpp"
#include <string>

using namespace std;

class ticketVille : public carte
{
private:
    ville ville1;
    ville ville2;
    bool estTermine;
public:
    ticketVille(ville ville1, ville ville2);
    void getVille1();
    void getVille2();
    void setEstTermine();
    ~ticketVille();
};