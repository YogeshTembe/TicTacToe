#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include <map>
#include <map>
#include "../Validator/Validator.h"
using namespace std;

class InputHandler{
    private:
        Validator validator;
    public:
        int getBoardSize();
        int getNoOfPlayers();
        map<string,int> getRowAndColumn(string name);
        map<string,string> getPlayerData(int playerNo);
};

#endif