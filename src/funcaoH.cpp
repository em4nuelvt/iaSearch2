#include "funcaoH.hpp"

funcaoH::funcaoH(){
}   

funcaoH::funcaoH(char meta){
    this->H = setH(meta);
}

funcaoH::~funcaoH(){
    this->H.clear();
}

unordered_map<char,double> funcaoH::setH(char meta){
    string letras = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
    unordered_map<char, double> H;
    for (int i = 0; i < letras.size(); i++){
        H[letras[i]] = calcularDistancia(letras[i], meta);
    }
    return H;
}

double funcaoH::calcularDistancia(char pos1, char pos2){
    unordered_map<char, pair<int, int>> tabuleiro = {
        {'A', {0, 0}}, {'B', {0, 1}}, {'C', {0, 2}}, {'D', {0, 3}}, {'E', {0, 4}},
        {'F', {1, 0}}, {'G', {1, 1}}, {'H', {1, 2}}, {'I', {1, 3}}, {'J', {1, 4}},
        {'K', {2, 0}}, {'L', {2, 1}}, {'M', {2, 2}}, {'N', {2, 3}}, {'O', {2, 4}},
        {'P', {3, 0}}, {'Q', {3, 1}}, {'R', {3, 2}}, {'S', {3, 3}}, {'T', {3, 4}},
        {'U', {4, 0}}, {'V', {4, 1}}, {'X', {4, 2}}, {'Y', {4, 3}}, {'Z', {4, 4}}
    };
    
    std::pair<int, int> coord1 = tabuleiro[pos1];
    std::pair<int, int> coord2 = tabuleiro[pos2];
    
    //valores para calcular a distância
    int x1 = coord1.first, y1 = coord1.second;
    int x2 = coord2.first, y2 = coord2.second;
    
    //  distância euclidiana
    double distancia = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));

    return distancia;
}

unordered_map<char,double> funcaoH::getH(){
    return this->H;
}