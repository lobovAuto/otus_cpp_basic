#include "main.hpp"

void clear_screen (){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
int main (int argc, char *argv[]){
    
    clear_screen();

    for (int i=0; i<argc; i++){
        std::cout<<argv[i]<<std::endl;
    }



    std::cout<<"Введите имя игорька. Имя должно быть не длиннее "<<NAME_LENGTH<<"символов, и не должно содержать пробелов."<<std::endl;
    std::cout<<"Имя: ";
    std::string input_name;
    std::getline(std::cin,input_name);
    
    pname name(input_name);
    std::cout<<name.process()<<std::endl;

    GameControl game_process(1);
    game_process.process();
    game_process.process();
    

    //Приветствие
    //Ввод имени
    //Вывод таблицы рекордов
    //Игра
}