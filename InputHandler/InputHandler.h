#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include <map>
#include <map>
using namespace std;

class InputHandler{
    public:
        int getBoardSize();
        int getNoOfPlayers();
        map<string,int> getRowAndColumn(string name);
        map<string,string> getPlayerData(int playerNo);
};

#endif