#include "grafo.hpp"
#include "astar.hpp"
#include "buscaGulosa.hpp"
#include "funcaoH.hpp"
#include <chrono>
#include <sys/time.h>
#include <unistd.h>
#include <fstream>


using namespace std;

int main() {


    Grafo grafo;

    // Criando vértices do grafo para representar o labirinto
    int a = grafo.adicionarVertice('A');
    int b = grafo.adicionarVertice('B');
    int c = grafo.adicionarVertice('C');
    int d = grafo.adicionarVertice('D');
    int e = grafo.adicionarVertice('E');
    int f = grafo.adicionarVertice('F');
    int g = grafo.adicionarVertice('G');
    int h = grafo.adicionarVertice('H');
    int i = grafo.adicionarVertice('I');
    int j = grafo.adicionarVertice('J');
    int k = grafo.adicionarVertice('K');
    int l = grafo.adicionarVertice('L');
    int m = grafo.adicionarVertice('M');
    int n = grafo.adicionarVertice('N');
    int o = grafo.adicionarVertice('O');
    int p = grafo.adicionarVertice('P');
    int q = grafo.adicionarVertice('Q');
    int r = grafo.adicionarVertice('R');
    int s = grafo.adicionarVertice('S');
    int t = grafo.adicionarVertice('T');
    int u = grafo.adicionarVertice('U');
    int v = grafo.adicionarVertice('V');
    int x = grafo.adicionarVertice('X');
    int y = grafo.adicionarVertice('Y');
    int z = grafo.adicionarVertice('Z');    
    
    // adicionando as arestas (associação de caminhos do labirinto)
    grafo.adicionarAresta(a, b);
    grafo.adicionarAresta(a, f);
    grafo.adicionarAresta(b, a);
    grafo.adicionarAresta(c, h);
    grafo.adicionarAresta(c, d);
    grafo.adicionarAresta(d, e);
    grafo.adicionarAresta(e, j);
    grafo.adicionarAresta(f, g);
    grafo.adicionarAresta(g, h);
    grafo.adicionarAresta(h, i);
    grafo.adicionarAresta(i, n);
    grafo.adicionarAresta(n, o);
    grafo.adicionarAresta(n, m);
    grafo.adicionarAresta(m, l);
    grafo.adicionarAresta(m, r);
    grafo.adicionarAresta(l, q);
    grafo.adicionarAresta(k, p);
    grafo.adicionarAresta(p, u);
    grafo.adicionarAresta(q, v);
    grafo.adicionarAresta(r, s);
    grafo.adicionarAresta(s, t);
    grafo.adicionarAresta(t, z);
    grafo.adicionarAresta(z, y);
    grafo.adicionarAresta(y, x);
    grafo.adicionarAresta(x, v);
    grafo.adicionarAresta(v, u);

    char inicio = 'U';
    char fim = 'E';
    cout<<"Grafo 1"<<endl;
    grafo.imprimirGrafo();
    cout<<endl;

    funcaoH distancias(fim);
    unordered_map<char, double> H = distancias.getH();

   // algoritmo A*
    
    auto startTime = chrono::high_resolution_clock::now();

    vector<char> caminho = AStar::encontrarCaminho(grafo, inicio, fim, H);

    cout << "Caminho encontrado pelo A*: ";
    for (char c : caminho) {
        cout << c;
        if (c != fim) cout << " -> ";
    }
    cout <<endl;

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);

    cout << "Tempo de execução A*: " << duration.count() << " microsegundos" << endl;
    cout<<endl;

    // algoritmo de busca gulosa

    startTime = chrono::high_resolution_clock::now();
    
    vector<char> caminhoGuloso = BuscaGulosa::encontrarCaminho(grafo, inicio, fim, H);

    cout << "Caminho encontrado pela Busca Gulosa: ";
    for (char c : caminhoGuloso) {
        cout << c;
        if (c != fim) cout << " -> ";
    }
    cout<<endl;

    endTime = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);

    cout << "Tempo de execução Busca Gulosa: " << duration.count() << " microsegundos" << endl;
    cout<<endl;

    return 0;

}