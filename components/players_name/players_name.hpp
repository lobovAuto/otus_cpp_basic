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
    unsigned int result;
    ErrType err_type=ErrorType::no_err;
    public:
    pname(const std::string name_in){
        std::string temp(name_in);
        name = name_in;
    };
    pname(const std::string name_in, unsigned int attempts):result(attempts){
        std::string temp(name_in);
        name = name_in;
    }
    bool process();
    std::string get_name (){return name;};
    unsigned int get_result (){return result;};
    bool name_compare(std::string);
};

#endif