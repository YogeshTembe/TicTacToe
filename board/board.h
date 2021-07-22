#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "../InputHandler/InputHandler.h"
using namespace std;

class Board{
    private:
        int size;
        vector<vector<string>> board;
        InputHandler inputHandler;
    public:
        void initializeBoard();
        int getSize();
        void setSize(int sizeGiven);
        vector<vector<string>> returnBoard();
        void entryToBoard(int row,int column,string symbol);
        bool isFull();
};
#endif 