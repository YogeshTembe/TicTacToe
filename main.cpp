#include<iostream>
using namespace std;
#include "game/game.h"

int main(){
    string typeOfGame;
    cout<<"Enter the type of game you want to play Multiplayer or AIGame-";
    cin>>typeOfGame;
    if(typeOfGame=="Multiplayer"){
        MultiplayerGame game;
        game.startGame(); 
    }
    else if(typeOfGame=="AIGame"){
        AIGame game;
        game.startGame(); 
    }
    return 0;
}