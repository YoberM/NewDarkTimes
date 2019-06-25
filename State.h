#ifndef STATE_H
#define STATE_H
#include <string>
class StateEntidad{
    char estado ='N';
    std::string restriccion="No";
public:
    StateEntidad(){
        
    }
    char get(){
        return estado;
    } 
    void set(char estado){
        this->estado=estado;
    }
    std::string getres(){
        return restriccion;
    }
    void setres(std::string restriccion){
        this->restriccion=restriccion;
    }
};

class StateBloq{

};
#endif