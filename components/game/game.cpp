#include "game.hpp"


void GuessNumberGame::set_level(unsigned int){
    
}

ReturnType GuessNumberGame::attempt(unsigned int in){
    attempts++;
    if (!check_number(in)){
        return ReturnType::bad_number;
    }
    if (in>hidden_number){
        return ReturnType::more;
    }
    if (in<hidden_number){
        return ReturnType::less;
    }
    return ReturnType::goal;
}