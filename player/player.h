#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include<string>
using namespace std;

class Player{
    private:
        string name, symbol;
    public:
        void setName(string name);
        void setSymbol(string symbol);
        string getName();
        string getSymbol();
};

#endif