#ifndef COLISIONES_H
#define COLISIONES_H
#include "Mapa.h"
#include "Entidad.h"
#include "Jugador.h"
class Colisiones {
    Entidad *entidades = NULL;
    unsigned int entidad_size=0;
    jugador *player;
    int numbalas;
    Mapa *mapa;
public:
    Colisiones(){
        
    }
    Colisiones(Entidad *n_ent,int n_enti_size,jugador *n_jugador){
        entidades=n_ent;
        entidad_size=n_enti_size;
        player=n_jugador;
        numbalas=player->getBalasNum();
    }
    std::string Entidad_Entidad(int,int);
    std::string Entidad_Bloque(int,int,int);
    bool Entidad_Jugador(int);
    bool Entidad_Balas(int,int);
    void setEntidades(Entidad *entidades,uint entsize){
        this->entidades = entidades;
        entidad_size = entsize;    
        std::cout<<entidad_size;
    }
    void setJugador(jugador *jugador){
        this->player= jugador;
        numbalas=player->getBalasNum();
    }
    void setMapa(Mapa* mapa){
        this->mapa=mapa;
    }
};

#endif //COLISIONES_H



