//Patron de diseño que controla el comportamiento de las demas clases en conjunto
#ifndef MEDIATOR_H
#define MEDIATOR_H
#include "Headers.h"
class Mediator{
    Entidad *entidades;
    unsigned int numEnt;
    Bloque *bloques;
    unsigned int numBloq;
    Entidad *jugador;
    Colisiones colisiones;
    sf::Texture *textentity;
    sf::Texture *textbloques;
    sf::Texture *textjugador;
public:
    Mediator(){

    }
    Mediator(Entidad *entidades,uint numEnt,Bloque *bloques
            ,uint numBloq,Entidad *jugador){
        colisiones.setBloques(bloques,numBloq);
        colisiones.setEntidades(entidades,numEnt);
        colisiones.setJugador(jugador);
    }
};
#endif