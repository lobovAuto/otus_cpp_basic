#include "game.hpp"

bool GuessNumberGame::check_number(unsigned int in){
    if (in>base_number){
        return false;
    }
    return true;
}

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