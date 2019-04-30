#include "Mapa.h"
#define r rand()%255
#define rango 17
Mapa::Mapa(float tam_new,int n_cantidad){
    cantidad=n_cantidad;
    tam=tam_new;
    arr=new int[cantidad*cantidad];
    shape.setSize(sf::Vector2f(tam,tam));
    int aux=0;
    for(int i=0;i<(cantidad*cantidad);i++){
            arr[i]=aux;
            aux=(aux+1)%2;
    }
}
 
Mapa::Mapa(float tam_new,int cantidad,int *new_array){
    ;
}

void Mapa::Random(sf::RenderWindow &window){
    sf::Vector2u asd= window.getSize();
    for(int i=0;i<cantidad;i++){
        for(int j=0;j<cantidad; j++)
        {
            if(arr[i*cantidad+j]==0){
                shape.setFillColor(sf::Color(255,255,255));
            }
            else
            {
                shape.setFillColor(sf::Color(0,0,0));
            }
            shape.setPosition(sf::Vector2f(j*tam,i*tam));
            Dibujar(window);
        }
        
    }
}

void Mapa::Dibujar(sf::RenderWindow &window){
    window.draw(shape);
}
