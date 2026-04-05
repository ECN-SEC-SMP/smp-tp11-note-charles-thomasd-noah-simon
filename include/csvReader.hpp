#ifndef CSVREADER_HPP
#define CSVREADER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Reader {
    vector<vector<string>> operator()(string path) {
        vector<vector<string>> res;
        ifstream f(path);
        string line, w;
        while (getline(f, line)) {
            istringstream iss(line);
            vector<string> row;
            while (iss >> w) row.push_back(w);
            res.push_back(row);
        }
        return res;
    }
};

#endif // CSVREADER_HPP
