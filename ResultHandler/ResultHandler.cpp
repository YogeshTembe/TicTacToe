#include<iostream>
#include "ResultHandler.h"
using namespace std;

void ResultHandler::displayResult(string result, string playerName){
    if(result=="winner"){
        cout<<playerName<<" is winner";
    }
    else if(result=="tie"){
        cout<<"game over! tie";
    }
}