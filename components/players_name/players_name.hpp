#ifndef PLAYERS_NAME
#define PLAYERS_NAME

#include <string>
#include <iostream>

#define NAME_LENGTH 20

enum class ErrorType{
    no_err = 0,
    length = 1,
    space = 2,
}typedef ErrType;

/**
 * @brief Класс имени игрока
 * @param В контструктор принимает массив символов проверяемого имени
 * 
 * Метод process проверяет класс на:
 * 1. Наличие в имени пробелов
 * 2. На ограничение длины имени
*/
class pname {
    private:
    std::string name;
    ErrType err_type=ErrorType::no_err;
    public:
    pname(const std::string name_in){
        std::string temp(name_in);
        name = name_in;
    }
    bool process();
};

#endif