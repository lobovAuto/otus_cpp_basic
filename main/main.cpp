#include "main.hpp"


int main (int argc, char *argv[]){

    args_orchestrator input_args(argc, argv);

    if (input_args.check_arg("help")){ // Вывод справки
        help();
        return 0;
    }

    if (input_args.check_arg("table")){ // Вывод таблицы результатов
        result_table table;
        table.sort_table();
        table.print_table();            
        return 0;
    }

    if (input_args.check_arg_with_parm("max")>0){
        if (input_args.check_arg_with_parm("level")>0){
            std::cerr<<"Ошибка! Укажите либо max, либо level"<<endl;
            return -1;
            }
    }
    unsigned int level=0;
    bool set_level=false;
    if (input_args.check_arg_with_parm("max")>0){
        level=input_args.check_arg_with_parm("max");
        set_level=true;
    }
    if (input_args.check_arg_with_parm("level")>0){
        switch (input_args.check_arg_with_parm("level")) {
        case 1: level=10; break;
        case 2: level=50; break;
        case 3: level=100; break;
        default:
            std::cerr<<"Ошибка! Уровень должен быть от 1 до 3"<<std::endl;
            return -1;
            break;
        }
        set_level=true;
    }

    GameControl game_process(level, set_level);
    while (true){
        game_process.process();
        if (game_process.exit()){break;}
    }

}