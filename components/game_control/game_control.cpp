#include "game_control.hpp"

void GameControl::clear_screen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

bool GameControl::game_req(){
    std::cout<<"Вы хотите сыграть?"<<std::endl;
    std::cout<<"Введите y\\n: ";
    std::string input;
    while (true){
        std::cin>>input;
        if ((input.find_first_of("д")==0)
            || (input.find_first_of("Д")==0)
            || (input.find_first_of("Y")==0)
            || (input.find_first_of("y")==0)){
                return true;
        }
        if ((input.find_first_of("н")==0)
            || (input.find_first_of("Н")==0)
            || (input.find_first_of("n")==0)
            || (input.find_first_of("N")==0)){
                is_exit = true;
                return false;
            }
    }
}

void GameControl::start_game_manual(){
    std::cout<<"Выберите максимальное число для отгадывания:"<<std::endl;
    std::cout<<"Число: ";
    unsigned int number;
    std::cin>>number;
    //std::cout<<"Введенное число: "<<number<<std::endl;
    game = new GuessNumberGame(number, true);
    //std::cout<<"загаданное число: "<<game->return_hidden_number()<<std::endl;
}

GameState GameControl::Acquaint(){
    //clear_screen();
    std::cout<<"Введите имя игорька. Имя должно быть не длиннее "<<NAME_LENGTH<<" символов, и не должно содержать пробелов."<<std::endl;
    std::cout<<"Имя: ";
    std::string input_name;             //переменная для имени
    std::getline(std::cin,input_name);  //считываем строку
    name = new pname (input_name);      //создаем объект с именем
    if (!name->process()){
        std::cout<<"Вы ввели неправильное имя."<<std::endl;
        return GameState::exit_en;
    }
    table = new result_table;
    table->sort_table();
    table->print_table(); // Вывод таблицы результатов
    if (table->get_best_result(name->get_name())){ // Написание рекорда текущего игрока
        std::cout<<"Ваш лучший счет: "<< table->get_best_result(name->get_name()) << std::endl;
    }
    if (!game_req()){
        return GameState::game_en;
    }
    
    if (is_prestart_level){
        game = new GuessNumberGame(level, true);//Тут логика на случай, если программа запущена с параметром уровня
        std::cout<<"Число загадано! Начинаем отгадывать"<<std::endl;
    }else {
        start_game_manual();
    }
    return GameState::game_en;
}

GameState GameControl::Game(){
    std::cout<<"Введите число: ";
    unsigned int number;
    std::cin>>number;
    switch (game->attempt(number))
    {
    case ReturnType::less:
        std::cout<<"Загаданное число больше!"<<std::endl;
        break;
    case ReturnType::more:
        std::cout<<"Загаданное число меньше!"<<std::endl;
        break;
    case ReturnType::goal:
        std::cout<<"Вы отгадали!"<<std::endl;
        std::cout<<"Количество попыток: "<<game->return_attempts()<<std::endl;
        clear_screen();
        std::cout<<"Поздравляем, вы выиграли!"<<std::endl;
        std::cout<<"Ваш счет: "<<game->return_attempts()<<std::endl;
        name->set_result(game->return_attempts());
        table->add_result(name);
        //delete game;
        //delete name;
        return GameState::lobby_en;
        break;
    case ReturnType::bad_number:
        std::cout<<"Вы ввели число вне диапазона"<<std::endl;
        break;
    }
    return GameState::game_en;
}

GameState GameControl::Lobby(){
    table->print_table();
    table->result_export();
    if (game_req()){
        start_game_manual();
        return GameState::game_en;
    }
    std::cout<<"Спасибо за игру!"<<std::endl;
    is_exit=true;
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