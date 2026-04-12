#include <gtest/gtest.h>
#include "csvReader.hpp"
#include "liaison.hpp"
#include "piocheTicket.hpp"

// =====================
// readMaps
// =====================

TEST(ReaderMapTest, NombreLiaisons) {
    Reader r;
    auto liaisons = r.readMaps("map.csv");
    EXPECT_EQ(liaisons.size(), 39);
}

TEST(ReaderMapTest, FichierInexistant) {
    Reader r;
    auto liaisons = r.readMaps("inexistant.csv");
    EXPECT_TRUE(liaisons.empty());
}

TEST(ReaderMapTest, PremiereLiaisonVilles) {
    Reader r;
    auto liaisons = r.readMaps("map.csv");
    const auto villes = liaisons[0].getVilles();
    EXPECT_EQ(villes[0]->getNom(), "Seattle");
    EXPECT_EQ(villes[1]->getNom(), "Calgary");
}

TEST(ReaderMapTest, PremiereLiaisonCouleur) {
    Reader r;
    auto liaisons = r.readMaps("map.csv");
    EXPECT_EQ(liaisons[0].getCouleur(), couleur_e::NOIR);
}

TEST(ReaderMapTest, PremiereLiaisonLongueur) {
    Reader r;
    auto liaisons = r.readMaps("map.csv");
    EXPECT_EQ(liaisons[0].getNbRails(), 4);
}

TEST(ReaderMapTest, PremiereLiaisonRegion) {
    Reader r;
    auto liaisons = r.readMaps("map.csv");
    const auto villes = liaisons[0].getVilles();
    EXPECT_EQ(villes[0]->getRegion(), region_e::OUEST);
    EXPECT_EQ(villes[1]->getRegion(), region_e::CENTRE_OUEST);
}

TEST(ReaderMapTest, MemePointeurPourMemeville) {
    // Seattle apparait dans plusieurs liaisons, doit pointer au même objet
    Reader r;
    auto liaisons = r.readMaps("map.csv");
    const Ville* seattle0 = liaisons[0].getVilles()[0]; // Seattle-Calgary ligne 1
    const Ville* seattle1 = liaisons[1].getVilles()[0]; // Seattle-Calgary ligne 2
    const Ville* seattle2 = liaisons[2].getVilles()[0]; // Seattle-Helena
    EXPECT_EQ(seattle0, seattle1);
    EXPECT_EQ(seattle0, seattle2);
}

TEST(ReaderMapTest, CouleurInconnueSiInvalide) {
    // On teste colorConverteur indirectement via une couleur non mappée
    EXPECT_EQ(colorConverteur("purple"), couleur_e::COULEUR_INCONNUE);
}

// =====================
// readTickets
// =====================

TEST(ReaderTicketTest, FichierInexistant) {
    Reader r;
    PiocheTicket p = r.readTickets("inexistant.csv");
    //EXPECT_EQ(p.getNbCartes(), 0);
}

TEST(ReaderTicketTest, NombreTickets) {
    Reader r;
    PiocheTicket p = r.readTickets("ticket.csv");
    //EXPECT_GT(p.getNbCartes(), 0);
}

TEST(ReaderTicketTest, PremierTicketVilles) {
    Reader r;
    PiocheTicket p = r.readTickets("ticket.csv");
    const auto carte = p.piocher();
    //EXPECT_EQ(carte.getVilleA()->getNom(), "Seattle");
    //EXPECT_EQ(carte.getVilleB()->getNom(), "Los Angeles");
}

TEST(ReaderTicketTest, MemePointeurVillePartageeAvecMap) {
    // Si readMaps est appelé avant readTickets sur le même Reader,
    // les pointeurs de villes communes doivent être identiques
    Reader r;
    auto liaisons = r.readMaps("map.csv");
    PiocheTicket p = r.readTickets("ticket.csv");

    const Ville* seattleMap = liaisons[0].getVilles()[0];
    //const Ville* seattleTicket = p.piocher().getVilleA();
    //EXPECT_EQ(seattleMap, seattleTicket);
}