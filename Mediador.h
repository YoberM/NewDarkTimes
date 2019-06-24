//Patron de diseño que controla el comportamiento de las demas clases en conjunto
#ifndef MEDIADOR_H
#define MEDIADOR_H
#include "Headers.h"
class Mediator{
    Entidad *entidades;
    unsigned int numEnt;
    Mapa mapa;
    Entidad *jugador;
    Colisiones colisiones;
    sf::Texture *textentity;
    sf::Texture *textbloques;
    sf::Texture *textjugador;
public:
    Mediator(){

    }
    Mediator(Entidad *entidades,uint numEnt,Mapa mapa,Entidad *jugador){
        //colisiones.setMapa(mapa);
        colisiones.setEntidades(entidades,numEnt);
        colisiones.setJugador(jugador);
    }
    
    void Acciones();
    void Dibujado(sf::RenderWindow&);

};
#endif