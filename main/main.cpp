#include "main.hpp"
int main (int argc, char *argv[]){
    for (int i=0; i<argc; i++){
        std::cout<<argv[i]<<std::endl;
    }
    std::cout<<"Введите имя игорька. Имя должно быть не длиннее "<<NAME_LENGTH<<"символов, и не должно содержать пробелов."<<std::endl;
    std::cout<<"Имя: ";
    std::string input_name;
    std::cin>>input_name;
    pname name(input_name);
    
    //Приветствие
    //Ввод имени
    //Вывод таблицы рекордов
    //Игра
}