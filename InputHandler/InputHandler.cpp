#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "InputHandler.h"
using namespace std;
#include "../Validator/Validator.h"

int InputHandler::getBoardSize(){
    int boardSize;
    cout<<"Enter board size-";
    cin>>boardSize;
    return boardSize;
}

int InputHandler::getNoOfPlayers(){
    int noOfPlayers;
    cout<<"Enter no of players-";
    cin>>noOfPlayers;
    return noOfPlayers;
}

map<string,string> InputHandler::getPlayerData(int playerNo){
    map<string,string>playerData;
    bool isValidSymbol=false;
    cout<<"Enter player"<<playerNo<<" name-";
    cin>>playerData["name"];
    while(!isValidSymbol){
        cout<<"Enter player"<<playerNo<<" symbol-";
        cin>>playerData["symbol"];
        isValidSymbol=validator.validateSymbol(playerData["symbol"]);
    }
    return playerData;
}

map<string,int> InputHandler::getRowAndColumn(string name){
    bool isRowValid=false;
    bool isColumnValid=false;
    if(name!=" "){
        cout<<name<<"'s turn"<<endl;
    }
    map<string,int>location;
    while(!isRowValid){
        cout<<"Enter row-";
        cin>>location["row"];
        if(location["row"]<0){isRowValid=false;}
        else{isRowValid=true;}
    }
    while(!isColumnValid){
        cout<<"Enter column-";
        cin>>location["column"];
        if(location["column"]<0){isColumnValid=false;}
        else{isColumnValid=true;}
    }
        location["row"]=location["row"]-1;
        location["column"]=location["column"]-1;
    
    return location;
}