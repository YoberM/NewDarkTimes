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
    texturas=new sf::Texture[2];
    texturas[0].loadFromFile("Texturas/terreno3.png");
    texturas[1].loadFromFile("Texturas/terreno7.png");
    //Jugador
    jugador player;
    
    

    //Mapa para el render
    Mapa render(800,pred_areas_numx,pred_bloq_numx,texturas,mapa_arr);
    //Mediator
        
        Mediator mediator;
        mediator.setEnt(mobs,Nentity);
        mediator.setMapa(&render);
        mediator.setWindow(&window);
        mediator.setJugador(&player);

    //!Mediator

    //Textura menu
    sf::Texture texturamenu;

    //Menu
    Menu menu(pred_window_tamx,pred_window_tamy,window);
    bool menuopen=1;
    int contadorbalas=0;

    //Bala;
    bool boolbala=1;
    bala *balaarr=new bala[20];

    while (window.isOpen()){ //Este es el while del juego

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        if(menuopen){
            menuopen=menu.Interaccion(window);
            menu.drawfondo(window);
		    menu.draw(window);

        }else{
            mediator.Dibujado();
            mediator.Acciones();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
                for (int i = 0; i < Nentity; i++)
                {
                    mobs[i].setObj(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);
                }
                
            }
            
            player.obtener_mouse(window);
            player.setmovmou();
            player.girarmouse();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                player.seguimiento.x=player.seguimiento.x+1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                player.seguimiento.y=player.seguimiento.y-1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                player.seguimiento.x=player.seguimiento.x-1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                player.seguimiento.y=player.seguimiento.y+1;
            }
            for(int i=0;i<20;i++){
                balaarr[i].movebala();
                window.draw(balaarr[i].getspritebala());
            }
            window.draw(player.getsprite());

            



        }
        window.display();
    }

    return 0;
}