#include "astar.hpp"

using namespace std;

vector<char> AStar::encontrarCaminho(
    Grafo& grafo, 
    char inicio, 
    char fim, 
    unordered_map<char, double>& h_values
) {
    priority_queue<Node, vector<Node>, greater<Node>> openSet;
    unordered_map<char, bool> closedSet;
    unordered_map<char, double> gScore;
    unordered_map<char, char> cameFrom;
    
    MemoryUsage memStats = {0, 0, 0};
    size_t currentOpenSetSize = 0;
    
    openSet.push(Node(inicio, h_values[inicio], 0, inicio));
    currentOpenSetSize++;
    gScore[inicio] = 0;
    
    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();
        currentOpenSetSize--;
        
        if (current.nome == fim) {
            memStats.closedSetSize = closedSet.size();
            memStats.mapsSize = gScore.size() + cameFrom.size();
            
            vector<char> path;
            char curr = fim;
            while (curr != inicio) {
                path.push_back(curr);
                curr = cameFrom[curr];
            }
            path.push_back(inicio);
            reverse(path.begin(), path.end());
            
            size_t totalMemory = 
                memStats.maxOpenSetSize * sizeof(Node) +
                memStats.closedSetSize * sizeof(char) +
                memStats.mapsSize * (sizeof(char) + sizeof(double));
                
            cout << "Estatísticas de Memória do A*:\n";
            cout << "Máximo de nós na fila de prioridade: " << memStats.maxOpenSetSize << "\n";
            cout << "Nós visitados: " << memStats.closedSetSize << "\n";
            cout << "Tamanho dos mapas: " << memStats.mapsSize << "\n";
            cout << "Memória total estimada: " << totalMemory << " bytes\n";
            
            return path;
        }
        
        if (closedSet[current.nome]) continue;
        closedSet[current.nome] = true;
        
        AdjNode* adj = grafo.getAdjList(current.nome);
        while (adj != nullptr) {
            if (!closedSet[adj->nome]) {
                double tentative_g = gScore[current.nome] + adj->peso;
                
                if (gScore.find(adj->nome) == gScore.end() || 
                    tentative_g < gScore[adj->nome]) {
                    cameFrom[adj->nome] = current.nome;
                    gScore[adj->nome] = tentative_g;
                    double f = tentative_g + h_values[adj->nome];
                    
                    openSet.push(Node(adj->nome, f, tentative_g, current.nome));
                    currentOpenSetSize++;
                    memStats.maxOpenSetSize = max(memStats.maxOpenSetSize, currentOpenSetSize);
                }
            }
            adj = adj->proximo;
        }
    }
    
    return vector<char>();
}