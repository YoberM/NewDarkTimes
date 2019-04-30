#include "Bloque.h"

Bloque::Bloque(){
    ;
}

Bloque::Bloque(float n_posx,float n_posy,int n_tam){
    ;
}

void Bloque::setTexture(sf::Texture n_texture){
    shape.setTexture(&n_texture);
}

void Bloque::setColor(int r,int g,int b){
    shape.setFillColor(sf::Color(r,g,b));
}

void Bloque::setPosx(float newx){
    posx=newx;
    shape.setPosition(sf::Vector2f(newx,posy)); 
}
void Bloque::setPosy(float newy){
    posy=newy;
    shape.setPosition(sf::Vector2f(posx,newy));
}
void Bloque::setPosx_y(float newx,float newy){
    setPosx(newx); setPosy(newy);
}