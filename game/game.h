#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "../board/board.h"
#include "../player/player.h"
#include "../boardHandler/boardHandler.h"
#include "../InputHandler/InputHandler.h"
#include "../ResultHandler/ResultHandler.h"
using namespace std;

class GameInterface{
    public:
        Board b;
        BoardHandler bh;
        Player currentPlayer;
        InputHandler inputHandler;
        ResultHandler resultHandler;
        virtual void startGame()=0;
};
class MultiplayerGame: public GameInterface{
    private:
        vector<Player>players;
    public:
        MultiplayerGame();
        void startGame();

};

class AIGame: public GameInterface{
    private:
        int evaluate(bool isComputer);
        int minimax(int depth, bool isComputer);
        map<string,int> findBestMove();
        Player human;
        Player computer;
    public:
        AIGame();
        void startGame();
};

#endif
