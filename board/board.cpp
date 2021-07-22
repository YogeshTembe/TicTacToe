#include "board.h"
#include<iostream>
#include "../InputHandler/InputHandler.h"
using namespace std;

void Board::initializeBoard(){
    for(int i=0;i<size;i++){
        vector<string>v1;
        for(int j=0;j<size;j++){
            v1.push_back("_");
        }
        board.push_back(v1);
    }
}
int Board::getSize(){
    return size;
}

void Board::setSize(int sizeGiven){
    size=sizeGiven;
}

vector<vector<string>> Board::returnBoard(){
    return board;
}

void Board::entryToBoard(int row,int column,string symbol){
    map<string,int>location;
    location["row"]=row;
    location["column"]=column;
    while(board[location["row"]][location["column"]]!="_" && symbol!="_"){
        cout<<"That spot is already taken please enter some other value for row and column\n";
        location=inputHandler.getRowAndColumn(" ");
    }
    board[location["row"]][location["column"]]=symbol;
}

bool Board::isFull(){
    bool isFull=true;
    for(int row=0;row<size;row++){
        for(int col=0;col<size;col++){
            if(board[row][col]=="_"){
                isFull=false;
            }
        }
    }
    return isFull;
}



