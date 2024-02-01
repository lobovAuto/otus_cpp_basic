#ifndef GAME_CONTROL_HPP
#define GAME_CONTROL_HPP

#include <iostream>
#include "game.hpp"
#include "players_name.hpp"
#include "result.hpp"

/**
Игра-
    |-Знакомство --
    |              |-Ввод имени
    |              |-Вывод результата, если имеется
    |              |-Вывод таблицы результатов
    |              |-Предложение сыграть в игру --- Выбор уровня, если не был указан при запуске приложения
    |-Игра --------
    |              |-Начало игры в зависимости от выбора уровня
    |              |-Игра до конца, либо до выхода из игры.
    |                   Если до конца, то вывод результата и таблицы результатов
    |-Игровое меню-
    |              |-Ввод данных -
    |                               |-Смена имени
    |                               |-Выход из игры
    |                               |-Смена уровня
    |                               |-Начало новой игры
*/
enum class GameState{
    acquaint_en = 0,
    game_en = 1,
    lobby_en = 2,
    exit_en = 3,
};

//typedef void * (*FuncPtr)();

class GameControl {
private:
    GameState state;
    unsigned int level;
    bool is_prestart_level;
    bool is_exit;

    GuessNumberGame * game;
    result_table * table;
    pname * name;

    GameState Acquaint();
    GameState Game ();
    GameState Lobby ();
    bool game_req();
    unsigned int return_level(){return level;};
    void clear_screen ();
    void start_game_manual();
public:
    GameControl(unsigned int in_level=0,bool presel_level=false, GameState input_state = GameState::acquaint_en ) : 
                is_prestart_level(presel_level), state(input_state), 
                level(in_level), is_exit(0){
    }
    int process();
    bool exit(){return is_exit;};
};
#endif