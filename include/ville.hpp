#pragma once
#include <string>
#include <array>

enum class region_e{
    OUEST,
    CENTRE_OUEST,
    CENTRE_EST,
    EST,
    DEFAULT_REGION
};


class Ville
{
private:
    std::string nom_;
    region_e region_;
public:
    // --- Constructeur par défault ---
    Ville();

    // --- Constructeur ---
    Ville(std::string nvNom);
    Ville(std::string nvNom,region_e c);

    // --- Destructeur ---
    ~Ville();

    // --- Acesseur : ---
    std::string getNom() const;
    region_e getRegion() const;

    bool operator==(const Ville& v) const { return this->nom_ == v.nom_; }

};

region_e convertRegion(std::string c);
bool isEquivalentLiaison(const std::array<Ville*,2> & vTab1, const std::array<Ville*,2> & vTab2);
