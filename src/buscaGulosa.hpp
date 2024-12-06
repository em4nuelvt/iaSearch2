#ifndef BUSCA_GULOSA_H
#define BUSCA_GULOSA_H

#include "grafo.hpp"
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>

class BuscaGulosa {
private:
    struct Node {
        char nome;
        double h;
        char parent;
        
        Node(char n, double h_val, char p) 
            : nome(n), h(h_val), parent(p) {}
        
        bool operator>(const Node& other) const {
            return h > other.h;
        }
    };

    struct MemoryUsage {
        size_t maxOpenSetSize;
        size_t closedSetSize;
        size_t mapsSize;
    };

public:
    static std::vector<char> encontrarCaminho(
        Grafo& grafo, 
        char inicio, 
        char fim, 
        std::unordered_map<char, double>& h_values
    );
};

#endif