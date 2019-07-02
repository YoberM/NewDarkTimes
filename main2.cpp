#include "Headers.h"
#include "Entidad.h"
#include "Mapa.h"
#include "State.h"
#include "ValoresGlobales.h"
#include "Zombie.h"
#include "Colisiones.h"
#include "Mediador.h"
#include "MapModel.h"
#include "Jugador.h"
#include "bala.h"
#include "menu.h"


using namespace std;

#define Nentity (uint)200

int main(){
    // create the window
    sf::RenderWindow window(sf::VideoMode(pred_window_tamx,pred_window_tamy), "NewDarkTimes");
    window.setMouseCursorGrabbed(0);
    srand(time(NULL));
    //Declarando las entidades
    Entidad *mobs=new Entidad[Nentity];
    window.setFramerateLimit(60);

    //Texturas
    sf::Texture *texturas;
    texturas=new sf::Texture[1];
    texturas[0].loadFromFile("Texturas/terreno1.jpg");
    
    

    //Mapa para el render
    Mapa render(800,pred_areas_numx,pred_bloq_numx,*texturas,mapa_arr);
    //Mediator
        
        Mediator mediator;
        mediator.setEnt(mobs,Nentity);
        mediator.setMapa(&render);
        mediator.setWindow(&window);

    //!Mediator
    float xw=pred_mapx_tam/2,yw=pred_mapy_tam/2;
    while (window.isOpen()){ //Este es el while del juego

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        mediator.Dibujado();
        mediator.Acciones();
        window.display();
    }

    return 0;
}