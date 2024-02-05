#include "args.hpp"

void args_orchestrator::print_args_with_parm(){
    std::vector<arg_with_parm>::iterator it=arg_with_parm_vector.begin();
    for (unsigned int i=0; i<arg_with_parm_vector.size();i++){
        std::cout<<"param: "<<it->get_name()<<" value: "<<it->get_value()<<std::endl;
        it++;
    }
}

void args_orchestrator::print_args(){
    std::vector<arg>::iterator it=arg_vector.begin();
    for (unsigned int i=0; i<arg_vector.size();i++){
        std::cout<<"param: "<<it->get_name()<<std::endl;
        it++;
    }
}

bool args_orchestrator::check_arg(std::string input){
    std::vector<arg>::iterator it=arg_vector.begin();
    for (unsigned int i=0; i<arg_vector.size();i++){
        if (it->is_match(input)){return true;}
        it++;
    }
    return false;
}

int args_orchestrator::check_arg_with_parm(std::string input){
    std::vector<arg_with_parm>::iterator it=arg_with_parm_vector.begin();
    for (unsigned int i=0; i<arg_with_parm_vector.size();i++){
        if (it->is_match(input)){return it->get_value();}
        it++;
    }
    return -1;
}
