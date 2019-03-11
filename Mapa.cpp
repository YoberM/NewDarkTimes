#include "Mapa.h"
#define r rand()%255
#define rango 80
Mapa::Mapa(float tam_new){
    tam=tam_new;
    shape.setSize(sf::Vector2f(rango,rango));
}

void Mapa::Random(sf::RenderWindow &window){
    sf::Vector2u asd= window.getSize();
    for(int i=0;i<rango;i++){
        for(int j=0;j<rango; j++)
        {
            shape.setPosition(sf::Vector2f(i*rango,j*rango));
            shape.setFillColor(sf::Color(r,r,r));
            Dibujar(window);
        }
        
    }
}

void Mapa::Dibujar(sf::RenderWindow &window){
    window.draw(shape);
}
