#include "buscaGulosa.hpp"

using namespace std;

vector<char> BuscaGulosa::encontrarCaminho(
    Grafo& grafo, 
    char inicio, 
    char fim, 
    unordered_map<char, double>& h_values
) {
    int iteracoes = 0;

    priority_queue<Node, vector<Node>, greater<Node>> openSet;
    unordered_map<char, bool> closedSet;
    unordered_map<char, char> cameFrom;
    
    MemoryUsage memStats = {0, 0, 0};
    size_t currentOpenSetSize = 0;
    
    openSet.push(Node(inicio, h_values[inicio], inicio));
    currentOpenSetSize++;
    
    while (!openSet.empty()) {
        iteracoes++;
        Node current = openSet.top();
        openSet.pop();
        currentOpenSetSize--;
        
        if (current.nome == fim) {
            memStats.closedSetSize = closedSet.size();
            memStats.mapsSize = cameFrom.size();
            
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
                memStats.mapsSize * sizeof(char);
                
            cout << "Estatísticas de Memória da Busca Gulosa:"<<endl;
            cout << "Máximo de nós na fila de prioridade: " << memStats.maxOpenSetSize << endl;
            cout << "Nós visitados: " << memStats.closedSetSize << endl;
            cout << "Tamanho dos mapas: " << memStats.mapsSize << endl;
            cout << "Memória total estimada: " << totalMemory << " bytes"<<endl;
            cout << "Número de Iterações: " << iteracoes << endl;
            
            return path;
        }
        
        if (closedSet[current.nome]) continue;
        closedSet[current.nome] = true;
        
        AdjNode* adj = grafo.getAdjList(current.nome);
        while (adj != nullptr) {
            if (!closedSet[adj->nome]) {
                cameFrom[adj->nome] = current.nome;
                openSet.push(Node(adj->nome, h_values[adj->nome], current.nome));
                currentOpenSetSize++;
                memStats.maxOpenSetSize = max(memStats.maxOpenSetSize, currentOpenSetSize);
            }
            adj = adj->proximo;
        }
    }
    
    return vector<char>();
}