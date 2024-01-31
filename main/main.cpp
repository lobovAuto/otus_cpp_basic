#include "main.hpp"


int main (int argc, char *argv[]){

    for (int i=0; i<argc; i++){
        std::cout<<argv[i]<<std::endl;
    }

    /*
    result_table table;
    table.print_table();
    std::cout<<std::endl;
    table.sort_table();
    //table.print_table();
    std::cout<< table.get_best_result("ыва")<<std::endl;
    */
    
    GameControl game_process(1);
    while (true){
        game_process.process();
        if (game_process.exit()){break;}
    }
    

    //Приветствие
    //Ввод имени
    //Вывод таблицы рекордов
    //Игра
}