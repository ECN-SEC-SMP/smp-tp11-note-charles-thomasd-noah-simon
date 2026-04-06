#ifndef READER_HPP
#define READER_HPP

#include <vector>
#include <string>
#include "liaison.hpp"
#include "piocheTicket.hpp"

struct Reader {
    // On ne garde que la signature
    std::vector<Liaison> readLiaisons(std::string path);
    PiocheTicket readTickets(std::string path);
};

#endif
