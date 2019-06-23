#ifndef COLISIONES_H
#define COLISIONES_H
#include "Headers.h"
class Colisiones {
    Entidad *entidades = NULL;
    int entidad_size=0;
    Bloque *bloques= NULL;
    int bloque_size=0;
    Entidad *jugador= NULL;
    
public:
    Colisiones(){
    }
    Colisiones(Entidad *n_ent,int n_enti_size,Bloque *n_blo,int n_bloq_size,Entidad *n_jugador){
        entidades=n_ent;
        entidad_size=n_enti_size;
        bloques=n_blo;
        bloque_size=n_bloq_size;
        jugador=n_jugador;
    }
    std::string Entidad_Entidad(int,int);
    std::string Entidad_Bloque(int,int);
    std::string Entidad_Jugador(int);
    void ColisionesEntidades();
    void ColisionesEntid_Jug();
    void ColisionesEntid_Bloq();
    void setEntidades(Entidad *entidades,uint entsize){
        this->entidades = entidades;
        entidad_size = entsize;    
    }
    void setBloques(Bloque *bloques,uint bloqsize){
        this->bloques = bloques;
        bloque_size = bloque_size;
    }
    void setJugador(Entidad *jugador){this->jugador = jugador;}
};

#endif //COLISIONES_H



