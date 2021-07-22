#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "InputHandler.h"
using namespace std;

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
    cout<<"Enter player"<<playerNo<<" name-";
    cin>>playerData["name"];
    cout<<"Enter player"<<playerNo<<" symbol-";
    cin>>playerData["symbol"];
    return playerData;
}

map<string,int> InputHandler::getRowAndColumn(string name){
    if(name!=" "){
        cout<<name<<"'s turn"<<endl;
    }
    map<string,int>location;
    cout<<"Enter row-";
    cin>>location["row"];
    cout<<"Enter column-";
    cin>>location["column"];
    location["row"]=location["row"]-1;
    location["column"]=location["column"]-1;
    return location;
}