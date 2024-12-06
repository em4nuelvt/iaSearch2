#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>

struct AdjNode {
    int vertice;
    char nome;
    int peso;
    AdjNode* proximo;
    AdjNode(int v, char nome, int peso);
};

struct VerticeNode {
    int id;
    AdjNode* listaAdj;
    VerticeNode* proximo;
    char nome;
    VerticeNode(int identificador, char nome);
};

class Grafo {
private:
    VerticeNode* vertices;
    int numVertices;
    int proximoId;
    VerticeNode* encontrarVertice(int id);
    VerticeNode* encontrarVerticePorNome(char nome);

public:
    Grafo();
    ~Grafo();
    int adicionarVertice(char nome);
    bool removerVertice(int id);
    bool adicionarAresta(int origem, int destino);
    bool removerAresta(int origem, int destino);
    void imprimirGrafo();
    int getNumVertices();
    AdjNode* getAdjList(char nome);
};

#endif