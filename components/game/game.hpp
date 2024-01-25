#ifndef GAME_HPP
#define GAME_HPP

#include <ctime>
#include <cstdlib>
#include <iostream>

enum class ReturnType{
    less = 0,
    more = 1,
    goal = 2,
    bad_number = 3,
};
class GuessNumberGame {
private:
    bool check_number(unsigned int);
    unsigned int hidden_number;
    unsigned int attempts;
    unsigned int level;
public:
    GuessNumberGame(unsigned int game_level=100, bool manual=0):level(game_level),attempts(0){
        std::srand(std::time(nullptr));
        if (manual){
            hidden_number = std::rand() % game_level;
            return;
        }
    };
    void set_level(unsigned int);
    ReturnType attempt (unsigned int);
};


#endif