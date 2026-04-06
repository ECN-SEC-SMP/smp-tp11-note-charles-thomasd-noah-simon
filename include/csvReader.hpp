#ifndef READER_HPP
#define READER_HPP

#include <vector>
#include <string>
#include "liaison.hpp"

struct Reader {
    // On ne garde que la signature
    std::vector<Liaison> operator()(std::string path);
};

#endif