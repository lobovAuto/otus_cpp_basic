#pragma once
#include <iostream>
#include <vector>
#include <string>

class arg{
private:
    std::string name;
public:
    arg(std::string in_name):name(in_name){
        std::string temp(name, name.find_first_not_of("-"));
        name = temp;
    };
    std::string get_name(){return name;};
    bool is_match(std::string in){return (in==name);};
};

class arg_with_parm{
private:
    std::string name;
    unsigned int value;
public:
    arg_with_parm(std::string in_name, unsigned int value):name(in_name), value(value){
        std::string temp(name, name.find_first_not_of("-"));
        name = temp;
    };
    std::string get_name(){return name;};
    unsigned int get_value(){return value;};
    bool is_match(std::string in){return (in==name);};
};

class args_orchestrator{
private:
    std::vector<arg> arg_vector;
    std::vector<arg_with_parm> arg_with_parm_vector;
public:
    args_orchestrator(int argc, char *argv[]){
        if (argc>0){
            for (int i=1; i<argc; i++){
                std::string argument=argv[i];
                if (argument.find_first_not_of("-")>1000){continue;} //Пропускаем пустые аргументы
                if (argument.find_first_of("-")!=0){     //Если первый аргумент не начинается с -, то выходим
                    //Тут можно добавить обработчик ошибок
                    return;
                    }
                if ((i+1)<argc){                    //Если есть следующий аргумент после текущего
                    std::string arg_next=argv[i+1];
                    if (arg_next.find_first_of("-")!=0){ //Если следующий аргумент не начинается с -
                        arg_with_parm * temp = new arg_with_parm(argument,stoi(arg_next));
                        arg_with_parm_vector.push_back(*temp);
                        i++;                        //Перескакиваем через следуюший аргумент
                        continue;                   // Завершаем цикл
                    }
                }
                arg * temp = new arg(argument);
                arg_vector.push_back(*temp);

            }
        }
    }
    void print_args_with_parm();
    void print_args();
    bool check_arg(std::string);
    /**
     * Вернет значние, либо -1, если нет такого аргумента
    */
    int check_arg_with_parm(std::string);
};