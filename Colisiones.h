#ifndef COLISIONES_H
#define COLISIONES_H
#include "Mapa.h"
#include "Entidad.h"
class Colisiones {
    Entidad *entidades = NULL;
    unsigned int entidad_size=0;
    Entidad *jugador= NULL;
    Mapa *mapa;
public:
    Colisiones(){
        
    }
    Colisiones(Entidad *n_ent,int n_enti_size,Entidad *n_jugador){
        entidades=n_ent;
        entidad_size=n_enti_size;
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
        std::cout<<entidad_size;
    }
    void setJugador(Entidad *jugador){
        this->jugador = jugador;
    }
};

#endif //COLISIONES_H



