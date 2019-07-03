#ifndef STATE_H
#define STATE_H
#include <string>
#include "Headers.h"
class StateEntidad{
    char estado;//A-> alive | D -> Dead pd ironia que un zombie ya este muerto
                     //que cosas no?xd
    std::string restriccion="No";//Colisiones
                                 
public:
    StateEntidad(){
        estado='D';
    }
    char get(){
        return estado;
    } 
    void set(char nuevo){
        estado=nuevo;
    }
    std::string getres(){
        return restriccion;
    }
    void setres(std::string restriccion){
        this->restriccion=restriccion;
    }
    bool contiene(char);
    void addres(std::string);
};

class StateBloq{
    char tipo='s';//s=bloque simple sin colisiones solo textura
                  //c=Bloque con colision y textura
                  //m=Bloque con modificador (velocidad, vida) sin colision pero con textura
                  //p=Bloque con modificador ,colision y textura ,complejo aun no ideado.
public:
    StateBloq(){

    }
    StateBloq(char tipo){
        this->tipo=tipo;
    }
    void set(char nuevo){
        tipo=nuevo;
    }
    char get(){
        return tipo;
    }
};

class StateBala{
    char estado='I';//I inactivo;
                    //A Activo
public:
    StateBala(){}
    StateBala(char estado){
        this->estado=estado;
    }
    void set(char estado){
        this->estado=estado;
    }
    char get(){
        return estado;
    }
};

#endif