#include "players_name.hpp"

bool pname::process(){
    if (name.length()>=NAME_LENGTH){
        return false;
    }
    return true;
}