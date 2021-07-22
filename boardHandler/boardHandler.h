#ifndef BOARDHANDLER_H
#define BOARDHANDLER_H

#include <iostream>
#include <vector>
#include "../board/board.h"
using namespace std;

class BoardHandler{
    public:
        void showBoard(Board b);
        string checkBoard(Board b);
};

#endif