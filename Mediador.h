//Patron de diseño que controla el comportamiento de las demas clases en conjunto
#ifndef MEDIADOR_H
#define MEDIADOR_H
#include "Entidad.h"
#include "Mapa.h"
#include "Colisiones.h"
#include "Zombie.h"
#include "Jugador.h"
class Mediator{
    Entidad *entidades;
    unsigned int numEnt;
    Mapa *mapa;
    jugador *player;
    Colisiones colisiones;
    sf::Texture *textentity;
    sf::Texture *textbloques;
    sf::Texture *textjugador;
    sf::RenderWindow *window;
public:
    Mediator(){
    }
    Mediator(Entidad *entidades,uint numEnt,Mapa mapa,Zombie *jugador){
        //colisiones.setMapa(mapa);
        this->numEnt = numEnt;
        colisiones.setEntidades(entidades,numEnt);
        colisiones.setJugador(player);

    }
    ~Mediator(){
        delete[] entidades;
    }

    void setEnt(Entidad*,uint);
    void setMapa(Mapa*);
    void setWindow(sf::RenderWindow*);
    void Acciones();
    void Spawn();
    bool SpawnComprobador(int,int);
    static void Colisionesthread(int,int,int,Colisiones&,Entidad*);
    void Dibujado();

};
#endif