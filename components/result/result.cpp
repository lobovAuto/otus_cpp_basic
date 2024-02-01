#include "result.hpp"

void result_table::print_table(){
    std::cout<<"Таблица рекордов:"<<std::endl;
    std::vector<pname>::iterator it = table.begin();
    int max_length=0;
    for (int i=0; i<table.size(); i++){
        std::string name = it->get_name();
        //std::cout<<"name is "<<name<<", length is "<<name.size()<<std::endl;
        if (name.size()>max_length){max_length=name.size();}
        it++;
    }
    it = table.begin();
    for (int i=0; i<table.size(); i++){
        if (i<9){std::cout<<"0";}
        std::cout<<i+1<<" | ";
        std::cout<<it->get_name();
        int delta = (max_length-(it->get_name()).size())/2;
        /**
         * Нужна помощь!
         * Узнал, что size возвращает не длину посимволно, а размер в байтах
         * Не понял, как узнать длину одного символа в строке в текущей системе
        */
        for (int j=0; j<delta; j++){std::cout<<" ";}
        std::cout<<" | Результат: "<<it->get_result()<<std::endl;
        it++;
    }
}


void result_table::sort_table(){
    std::sort(table.begin(), table.end(), [](pname &a, pname &b){return a.get_result()<b.get_result();});
}

unsigned int result_table::get_best_result(std::string name){
    unsigned int best_res=__INT_MAX__;
    std::vector<pname>::iterator it = table.begin();
    for (int i=0; i<table.size(); i++){
        if (it->name_compare(name)){
            if (best_res>(it->get_result())){best_res=(it->get_result());}    
        }
        it++;
    }
    if (best_res==__INT_MAX__){best_res=0;}
    return best_res;
}

void result_table::add_result(pname * input){
    table.push_back(*input);
    sort_table();
}

void result_table::result_export(){
    /*
    std::vector<pname>::iterator it = table.begin();
    for (int i=0; i<table.size(); i++){
        if (i<9){std::cout<<"0";}
        std::cout<<i+1<<" | ";
        std::cout<<it->get_name();
        std::cout<<" | Результат: "<<it->get_result()<<std::endl;
        it++;
    }
    */
    it = table.begin();
    std::ofstream result("result");
    std::cout<<"size "<<table.size()<<std::endl;
    for (int i=0; i<table.size();i++){
        std::string test=it->get_name();
        std::cout<<it->get_name()<<" "<<it->get_result()<<std::endl;
        result<<test<<" "<<it->get_result()<<std::endl;
        i++;
    }
    result.close();
}