#include "buscaGulosa.hpp"

std::vector<char> BuscaGulosa::encontrarCaminho(
    Grafo& grafo, 
    char inicio, 
    char fim, 
    std::unordered_map<char, double>& h_values
) {
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> openSet;
    std::unordered_map<char, bool> closedSet;
    std::unordered_map<char, char> cameFrom;
    
    MemoryUsage memStats = {0, 0, 0};
    size_t currentOpenSetSize = 0;
    
    openSet.push(Node(inicio, h_values[inicio], inicio));
    currentOpenSetSize++;
    
    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();
        currentOpenSetSize--;
        
        if (current.nome == fim) {
            memStats.closedSetSize = closedSet.size();
            memStats.mapsSize = cameFrom.size();
            
            std::vector<char> path;
            char curr = fim;
            while (curr != inicio) {
                path.push_back(curr);
                curr = cameFrom[curr];
            }
            path.push_back(inicio);
            std::reverse(path.begin(), path.end());
            
            size_t totalMemory = 
                memStats.maxOpenSetSize * sizeof(Node) +
                memStats.closedSetSize * sizeof(char) +
                memStats.mapsSize * sizeof(char);
                
            std::cout << "Estatísticas de Memória da Busca Gulosa:\n";
            std::cout << "Máximo de nós na fila de prioridade: " << memStats.maxOpenSetSize << "\n";
            std::cout << "Nós visitados: " << memStats.closedSetSize << "\n";
            std::cout << "Tamanho dos mapas: " << memStats.mapsSize << "\n";
            std::cout << "Memória total estimada: " << totalMemory << " bytes\n";
            
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
                memStats.maxOpenSetSize = std::max(memStats.maxOpenSetSize, currentOpenSetSize);
            }
            adj = adj->proximo;
        }
    }
    
    return std::vector<char>();
}