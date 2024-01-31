#include "players_name.hpp"

bool pname::process(){
    if (name.length()>=NAME_LENGTH){
        err_type = ErrorType::length;
        return false;
    }
    if (name.find_first_of(' ')<=NAME_LENGTH){
        err_type = ErrorType::space;
        return false;
    }
    return true;
}

bool pname::name_compare(std::string in){
    if (name==in){
        return true;
    } else {
        return false;
    }
}