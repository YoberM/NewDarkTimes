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
    int salud=100;
    Font font;
    Text textopantalla;
    int auxbalacontador=0;
    int balanum;
    bool boolbala=1;
public:
    Mediator(){
    }
    Mediator(Entidad *entidades,uint numEnt,Mapa mapa,Zombie *jugador){
        //colisiones.setMapa(mapa);
        this->numEnt = numEnt;
        colisiones.setEntidades(entidades,numEnt);
        colisiones.setJugador(player);
        colisiones.setMapa(&mapa);
        font.loadFromFile("arial.ttf");
        textopantalla.setFont(font);
        textopantalla.setColor(sf::Color(50,100,200));
        textopantalla.setString("Salud -> ");
        textopantalla.setPosition(500,500);
        textopantalla.setCharacterSize(25);
    }
    ~Mediator(){
        delete[] entidades;
    }

    void setEnt(Entidad*,uint);
    void setMapa(Mapa*);
    void setWindow(sf::RenderWindow*);
    void setJugador(jugador*);
    void Acciones();
    void AccionBala();
    void ColisionBala();
    void ColisionesEntidadThreads();
    void Spawn();//"Object Pool"
    bool SpawnComprobador(int,int);
    void Dibujado();

};
#endif