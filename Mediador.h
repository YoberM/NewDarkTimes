//Patron de diseño que controla el comportamiento de las demas clases en conjunto
#ifndef MEDIADOR_H
#define MEDIADOR_H
#include "Entidad.h"
#include "Mapa.h"
#include "Colisiones.h"
class Mediator{
    Entidad *entidades;
    unsigned int numEnt;
    Mapa *mapa;
    Entidad *jugador;
    Colisiones colisiones;
    sf::Texture *textentity;
    sf::Texture *textbloques;
    sf::Texture *textjugador;
    sf::RenderWindow *window;
public:
    Mediator(){
    }
    Mediator(Entidad *entidades,uint numEnt,Mapa mapa,Entidad *jugador){
        //colisiones.setMapa(mapa);
        this->numEnt = numEnt;
        colisiones.setEntidades(entidades,numEnt);
        colisiones.setJugador(jugador);
    }

    void setEnt(Entidad*,uint);
    void setMapa(Mapa*);
    void setWindow(sf::RenderWindow*);
    void Acciones();
    void Dibujado();

};
#endif