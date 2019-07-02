#include "State.h"
bool StateEntidad::contiene(char a){
    for(int i=0;i<restriccion.length();i++){
        if(restriccion[i]==a){
            return 1;
        }
    }
    return 0;
}

void StateEntidad::addres(std::string nuevo){
    restriccion+=nuevo;
}