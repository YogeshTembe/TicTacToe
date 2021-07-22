#include "player.h"
#include<iostream>
using namespace std;



string Player::getName(){
    return name;
}
string Player::getSymbol(){
    return symbol;
}
void Player::setName(string nameGiven){
    name=nameGiven;
}
void Player::setSymbol(string symbolGiven){
    symbol=symbolGiven;
}