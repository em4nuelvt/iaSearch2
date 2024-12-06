#ifndef FUNCAOH_H
#define FUNCAOH_H

#include <unordered_map>
#include <cmath>
#include <iostream>

using namespace std;

class funcaoH{
    private:
        
        unordered_map<char, double> H;
        double calcularDistancia(char pos1, char pos2);
        unordered_map<char,double> setH(char meta);
        

    public:
        unordered_map<char,double> getH();
        funcaoH();
        funcaoH(char meta);
        ~funcaoH();
};

#endif