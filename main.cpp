#include <SFML/Graphics.hpp>
#include <iostream>
#include "window.h"
#include "Entidad.h"
#include "Mapa.h"
#include <stdlib.h>
#define Nentity 1

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    window.setMouseCursorGrabbed(1);
    srand(time(NULL));
    Entidad *mobs=new Entidad[Nentity];
    Entidad mob1(500,500,2.5);
    Entidad mob2(500,500,2.5);
    Entidad mob3(500,500,2.5);
    Entidad mob4(500,500,2.5);
    int x=0;
    window.setFramerateLimit(60);
    // run the program as long as the window is open
    Mapa render(10);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        //
        //
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            sf::CircleShape ward(50);
            ward.setFillColor(sf::Color(100,100,100));
            sf::Vector2i mposition= sf::Mouse::getPosition();
            ward.setPosition(sf::Vector2f(mposition.x,mposition.y));
            window.draw(ward);
            std::cout<<"pressed"<<mposition.x<<mposition.y<<"|";
        }
        //
        x=(x+1)%300;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))x=0;
        std::cout<<x<<"||";
        if(x<1)mob1.searchObj();
        mob1.Move();
        mob1.Dibujar(window);
        mob2.MoveAutomatico();
        mob3.MoveAutomatico();
        mob4.MoveAutomatico();
        mob2.Dibujar(window);
        mob3.Dibujar(window);
        mob4.Dibujar(window);
        render.Random(window);
        for(int i = 0; i < Nentity; i++)
        {
            mobs[i].MoveAutomatico();
            mobs[i].Dibujar(window);
        }
        
        // draw everything here...
        // window.draw(...);
        std::cout<<std::endl;
        // end the current frame
        window.display();
    }

    return 0;
}