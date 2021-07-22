#include "../board/board.h"
#include "../player/player.h"
#include "../boardHandler/boardHandler.h"
#include "game.h"
#include<iostream>
#include "../InputHandler/InputHandler.h"
#include "../ResultHandler/ResultHandler.h"
#include <map>
using namespace std;



MultiplayerGame::MultiplayerGame(){
    int boardSize;
    int noOfPlayers;
    boardSize=inputHandler.getBoardSize();
    noOfPlayers=inputHandler.getNoOfPlayers();
    map<string,string> playerData;
    for(int playerNo=1;playerNo<=noOfPlayers;playerNo++){
        playerData=inputHandler.getPlayerData(playerNo);
        Player player;
        player.setName(playerData["name"]);
        player.setSymbol(playerData["symbol"]);
        players.push_back(player);
    }
    b.setSize(boardSize);
    b.initializeBoard();
}

void MultiplayerGame::startGame(){
    int playerNo=0;
    string result;
    map<string,int>location;
    while(true){
        currentPlayer.setName(players[playerNo].getName());
        currentPlayer.setSymbol(players[playerNo].getSymbol());
        location=inputHandler.getRowAndColumn(currentPlayer.getName());
        b.entryToBoard(location["row"],location["column"],currentPlayer.getSymbol());
        bh.showBoard(b);
        result=bh.checkBoard(b);
        if(result=="continue"){
            playerNo= playerNo+1;
            if(playerNo==players.size()){
                playerNo=0;
            }
        }
        else{
            resultHandler.displayResult(result,currentPlayer.getName());
            break;
        } 
    }
}

AIGame::AIGame(){
    b.setSize(3);
    b.initializeBoard();
    string name,symbol;
    map<string,string> playerData;
    playerData=inputHandler.getPlayerData(0);
    human.setName(playerData["name"]);
    human.setSymbol(playerData["symbol"]);
    computer.setName("computer");
    computer.setSymbol("X");
}
void AIGame::startGame(){
    int row,column;
    string result;
    map<string,int>location;
    currentPlayer.setName(human.getName());
    currentPlayer.setSymbol(human.getSymbol());
    while(true){
        if(currentPlayer.getName()==human.getName()){
            location=inputHandler.getRowAndColumn(currentPlayer.getName());
        }
        else if(currentPlayer.getName()==computer.getName()){
            cout<<"computer's move is-"<<endl;
            map<string,int> bestMove=findBestMove();
            location["row"]=bestMove["row"];
            location["column"]=bestMove["column"];
        }
        b.entryToBoard(location["row"],location["column"],currentPlayer.getSymbol());
        bh.showBoard(b);
        result=bh.checkBoard(b);
        if(result=="continue"){
            if(currentPlayer.getName()==human.getName()){
                currentPlayer.setName("computer");
                currentPlayer.setSymbol("X");
            }
            else{
                currentPlayer.setName(human.getName());
                currentPlayer.setSymbol(human.getSymbol());
            }
        }
        else{
            resultHandler.displayResult(result,currentPlayer.getName());
            break;
        } 

    }
}

int AIGame::evaluate(bool isHuman){
    string result=bh.checkBoard(b);
    if(result=="winner" && isHuman==true){return -10;}
    if(result=="winner" && isHuman==false){return 10;}
    if(result=="tie"){return 20;}
    if(result=="continue"){return 0;}
    return 0;
}

int AIGame::minimax(int depth, bool isComputer){
    int score = evaluate(isComputer);
    vector<vector<string>> board=b.returnBoard();
    if (score == 10){
        return score-depth;
    }
    if (score == -10){
        return score+depth;
    }
    if (score==20){
        return 0;
    }
    //If computer's move
    if (isComputer)
    {
        int best = -1000;
        for (int i = 0; i<b.getSize(); i++)
        {
            for (int j = 0; j<b.getSize(); j++)
            {
                if (board[i][j]=="_")
                {
                    b.entryToBoard(i,j,"X");
                    best = max(best,minimax(depth+1, !isComputer) );
                    b.entryToBoard(i,j,"_");
                }
            }
        }
        return best;
    }
    //If humans's move
    else
    {
        int best = 1000;
        for (int i = 0; i<b.getSize(); i++)
        {
            for (int j = 0; j<b.getSize(); j++)
            {
                if (board[i][j]=="_")
                {
                    b.entryToBoard(i,j,human.getSymbol());
                    best = min(best,minimax(depth+1, !isComputer));
                    b.entryToBoard(i,j,"_");
                }
            }
        }
        return best;
    }
}

map<string,int> AIGame::findBestMove()
{
    int bestVal = -1000;
    map<string,int> bestMove;
    bestMove["row"]=-1;
    bestMove["column"]=-1;
    vector<vector<string>> board= b.returnBoard();
    for (int i = 0; i<b.getSize(); i++)
    {
        for (int j = 0; j<b.getSize(); j++)
        {
            if (board[i][j]=="_")
            {
                b.entryToBoard(i,j,"X");
                int moveVal = minimax(0, false);
                b.entryToBoard(i,j,"_");
                if (moveVal > bestVal)
                {
                    bestMove["row"]=i;
                    bestMove["column"] = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}