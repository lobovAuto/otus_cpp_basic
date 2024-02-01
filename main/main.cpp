#include "main.hpp"


int main (int argc, char *argv[]){

    for (int i=0; i<argc; i++){
        std::cout<<argv[i]<<std::endl;
    }
    
    GameControl game_process(1);
    while (true){
        game_process.process();
        if (game_process.exit()){break;}
    }
    
}