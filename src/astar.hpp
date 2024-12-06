#ifndef ASTAR_H
#define ASTAR_H

#include "grafo.hpp"
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class AStar {
private:
    struct Node {
        char nome;
        double f;
        double g;
        char parent;
        
        Node(char n, double f_val, double g_val, char p) 
            : nome(n), f(f_val), g(g_val), parent(p) {}
        
        bool operator>(const Node& other) const {
            return f > other.f;
        }
    };

    struct MemoryUsage {
        size_t maxOpenSetSize;
        size_t closedSetSize;
        size_t mapsSize;
    };

public:
    static vector<char> encontrarCaminho(
        Grafo& grafo, 
        char inicio, 
        char fim, 
        unordered_map<char, double>& h_values
    );
};

#endif