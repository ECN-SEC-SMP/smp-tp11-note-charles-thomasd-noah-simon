#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// ca marche mais c est l'ia ... :/

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

/*test pour le lecteur de csv*/
// int main() {
//     auto data = Reader()("map.csv");

//     // Affichage direct
//     for (auto row : data) {
//         for (auto word : row) cout << word << " ";
//         cout << endl;
//     }
// }