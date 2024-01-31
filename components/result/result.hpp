#pragma once

#include "players_name.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
class result_table {
private:
    std::vector <pname> table;
    //static bool comp (pname one , pname two){return one.get_result()>two.get_result();};
public:
result_table (){
    std::ifstream result("result");
    if (!result.is_open()){return;}
    if (result.eof()){return;}
    while (!result.eof()){
        std::string line;
        unsigned int int_attempt;
        std::getline(result, line);
        std::string name(line, 0, line.find_first_of(" "));
        std::string attempt(line, line.find_first_of(" "));
        int_attempt = stoi(attempt);
        pname * temp = new pname(name, int_attempt);
        table.push_back(*temp);
        //std::cout<<"name is "<<name<<std::endl;
        //std::cout<<"attempts is "<<int_attempt<<std::endl;
    }
};
void print_table();
void sort_table();
unsigned int get_best_result(std::string);
};