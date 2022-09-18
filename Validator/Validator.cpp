#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
#include "Validator.h"


bool Validator::validateSymbol(string symbol){
    if(symbol=="_"){
        return false;
    }
    return true;
}