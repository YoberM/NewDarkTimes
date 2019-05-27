#include"Headers.h"
Bloque::Bloque(){
    tam=pred_bloq_tam;
    posx=0;
    posy=0;
}

Bloque::Bloque(const Bloque &n_bloque){
    tam=n_bloque.tam;
    setPosx_y(n_bloque.posx,n_bloque.posy);
    if(booltexture!=0)
    textura = n_bloque.textura;
    shape=n_bloque.shape;    
}

Bloque::Bloque(float n_posx,float n_posy,int n_tam,sf::Texture textura){
    posx=n_posx;
    posy=n_posy;
    tam=n_tam;
}

void Bloque::setTexture(sf::Texture n_texture){
    shape.setTexture(&n_texture);
}

void Bloque::setColorBloque(int r,int g,int b){
    shape.setFillColor(sf::Color(r,g,b));
}

void Bloque::setTam(float newtam){
    tam=newtam;
    shape.setSize(sf::Vector2f(tam,tam));
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
    posx=newx;
    posy=newy;
    shape.setPosition(sf::Vector2f(newx,newy));
}

int Bloque::getTam(){return tam;}
float Bloque::getPosx(){return posx;}
float Bloque::getPosy(){return posy;}