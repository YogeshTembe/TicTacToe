#include "boardHandler.h"
#include<iostream>
#include "../board/board.h"
using namespace std;

void BoardHandler::showBoard(Board b){
    vector<vector<string>> board=b.returnBoard();
    int size=b.getSize();
    for(int row=0;row<size;row++){
        for(int col=0;col<size;col++){
            cout<<board[row][col]<<" ";
        }
        cout<<"\n";
    }
}

string BoardHandler::checkBoard(Board b){
    vector<vector<string>> board=b.returnBoard();
    int size=b.getSize();
    //for rows
    string rowValue;
    int rowCount=0;
    for(int row=0;row<size;row++){
        rowValue=board[row][0];
        rowCount=0;
        for(int col=0;col<size;col++){
            if(board[row][col]==rowValue){
                rowCount++;
            }
        }
        if(rowValue!="_" && rowCount==size){return "winner";}
    }
    //cout<<"row checked\n";
    
    //for columns
    int colCount=0;
    string colValue;
    for(int col=0;col<size;col++){
        colValue=board[0][col];
        colCount=0;
        for(int row=0;row<size;row++){
            if(colValue!="_" && board[row][col]==colValue){
                colCount++;
            }
        }
        if(colValue!="_" && colCount==size){return "winner";}
    }
    
    //cout<<"column checked"<<colCount<<"\n";
    //for cross
    //from left-up to right-down
    string diagonal1Value=board[0][0];
    if(board[0][0]!="_"){
        int diagonal1Count=0;
        for(int i=0;i<size;i++){
            if(board[i][i]==diagonal1Value){diagonal1Count++;}
        }
        if(diagonal1Count==size){return "winner";}
    }
    //cout<<"dia1 checked\n";
    //from right-up to left-down
    string diagonal2Value=board[0][size-1];
    if(board[0][size-1]!="_"){
        int diagonal2Count=0;
        for(int i=0;i<size;i++){
            if(board[i][size-i-1]==diagonal2Value){diagonal2Count++;}
        }
        if(diagonal2Count==size){return "winner";}
    }
    //cout<<"dia2 checked\n";
    //tie or not
    int count=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(board[i][j]=="_"){
                count++;
                break;
            }
        }
    }
    if(count==0){
        return "tie";
    }
    else{
        return "continue";
    }
}
