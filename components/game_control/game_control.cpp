#include "game_control.hpp"

GameState GameControl::Acquaint(){
    std::cout<<"test accquiant"<<std::endl;
    return GameState::acquaint_en;
}

GameState GameControl::Game(){
    //GuessNumberGame new_game(return_level(), false);
    std::cout<<"test game"<<std::endl;
    return GameState::game_en;
}

GameState GameControl::Lobby(){
    //GuessNumberGame new_game(return_level(), false);
    std::cout<<"test game"<<std::endl;
    return GameState::lobby_en;
}

int GameControl::process(){
    switch (state)
    {
    case GameState::acquaint_en:
        state = Acquaint();
        break;
    case GameState::game_en:
        state = Game();
        break;
    case GameState::lobby_en:
        state = Lobby();
        break;
    }
    return 1;
}