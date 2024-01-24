#ifndef PLAYERS_NAME
#define PLAYERS_NAME

#include <string>
#include <iostream>

#define NAME_LENGTH 20

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
    public:
    pname(const std::string name_in){
        std::string temp(name_in);
        name = name_in;
    }
    bool process();
};

#endif