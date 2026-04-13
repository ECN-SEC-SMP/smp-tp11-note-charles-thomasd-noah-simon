#include <gtest/gtest.h>
#include "csvReader.hpp"
#include "liaison.hpp"
#include "piocheTicket.hpp"

// =====================
// readMaps
// =====================

TEST(ReaderMapTest, NombreLiaisons) {
    Reader r;
    auto liaisons = r.readMaps("data/map.csv");
    EXPECT_EQ(liaisons.size(), 39);
}

TEST(ReaderMapTest, FichierInexistant) {
    Reader r;
    auto liaisons = r.readMaps("inexistant.csv");
    EXPECT_TRUE(liaisons.empty());
}

TEST(ReaderMapTest, PremiereLiaisonVilles) {
    Reader r;
    auto liaisons = r.readMaps("data/map.csv");
    const auto villes = liaisons[0].getVilles();
    EXPECT_EQ(villes[0]->getNom(), "Seattle");
    EXPECT_EQ(villes[1]->getNom(), "Calgary");
}

TEST(ReaderMapTest, PremiereLiaisonCouleur) {
    Reader r;
    auto liaisons = r.readMaps("data/map.csv");
    EXPECT_EQ(liaisons[0].getCouleur(), couleur_e::NOIR);
}

TEST(ReaderMapTest, PremiereLiaisonLongueur) {
    Reader r;
    auto liaisons = r.readMaps("data/map.csv");
    EXPECT_EQ(liaisons[0].getNbRails(), 4);
}

TEST(ReaderMapTest, PremiereLiaisonRegion) {
    Reader r;
    auto liaisons = r.readMaps("data/map.csv");
    const auto villes = liaisons[0].getVilles();
    EXPECT_EQ(villes[0]->getRegion(), region_e::OUEST);
    EXPECT_EQ(villes[1]->getRegion(), region_e::CENTRE_OUEST);
}

TEST(ReaderMapTest, MemePointeurPourMemeville) {
    // Seattle apparait dans plusieurs liaisons, doit pointer au même objet
    Reader r;
    auto liaisons = r.readMaps("data/map.csv");
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
    EXPECT_TRUE(p.estVide());
}

TEST(ReaderTicketTest, NombreTickets) {
    Reader r;
    PiocheTicket p = r.readTickets("data/ticket.csv");

    int nbTickets = 0;
    while (!p.estVide()) {
        Carte* c = p.piocher();
        delete c;
        ++nbTickets;
    }

    EXPECT_EQ(nbTickets, 32);
}

TEST(ReaderTicketTest, PremierTicketVilles) {
    Reader r;
    PiocheTicket p = r.readTickets("data/ticket.csv");
    Carte* c = p.piocher();
    ASSERT_NE(c, nullptr);

    auto* ticket = dynamic_cast<CarteTicket*>(c);
    ASSERT_NE(ticket, nullptr);

    const auto villes = ticket->getVilles();
    EXPECT_EQ(villes[0]->getNom(), "Seattle");
    EXPECT_EQ(villes[1]->getNom(), "New York");

    delete c;
}

TEST(ReaderTicketTest, MemePointeurVillePartageeAvecMap) {
    // Si readMaps est appelé avant readTickets sur le même Reader,
    // les pointeurs de villes communes doivent être identiques
    Reader r;
    auto liaisons = r.readMaps("data/map.csv");
    PiocheTicket p = r.readTickets("data/ticket.csv");

    const Ville* seattleMap = liaisons[0].getVilles()[0];
    bool sharedPointerFound = false;

    while (!p.estVide()) {
        Carte* c = p.piocher();
        auto* ticket = dynamic_cast<CarteTicket*>(c);
        if (ticket != nullptr) {
            const auto villes = ticket->getVilles();
            if (villes[0]->getNom() == "Seattle") {
                EXPECT_EQ(seattleMap, villes[0]);
                sharedPointerFound = true;
            }
            if (villes[1]->getNom() == "Seattle") {
                EXPECT_EQ(seattleMap, villes[1]);
                sharedPointerFound = true;
            }
        }
        delete c;
    }

    EXPECT_TRUE(sharedPointerFound);
}