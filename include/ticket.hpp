#pragma once
#include "carte.hpp"
#include "ville.hpp"
#include <string>

using namespace std;

class ticket : public carte
{
private:
    ville ville1;
    ville ville2;
    bool isTermine;
public:
    ticket(ville ville1, ville ville2);
    void getVille1();
    void getVille2();
    void setisTermine();
    ~ticket();
};