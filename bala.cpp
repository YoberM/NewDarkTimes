#include "bala.h"
using namespace std;

bala::bala(){
    textura_bala.loadFromFile("bala.png");
    sprite_bala.setTexture(textura_bala);
    sprite_bala.setOrigin(sprite_bala.getTexture()->getSize().x/2.f, sprite_bala.getTexture()->getSize().y/2.f);
    sprite_bala.setScale(((float)10/sprite_bala.getTexture()->getSize().x),((float)10/sprite_bala.getTexture()->getSize().y));
    sprite_bala.setPosition(posicion);}

bala::bala(Texture textura_bala2, Sprite sprite_bala2,Vector2f posicion)
{
    
    textura_bala=textura_bala2;
    sprite_bala=sprite_bala2;
    textura_bala.loadFromFile("bala.png");
    sprite_bala.setTexture(textura_bala);
    sprite_bala.setOrigin(sprite_bala.getTexture()->getSize().x/2.f, sprite_bala.getTexture()->getSize().y/2.f);
    sprite_bala.setScale(((float)10/sprite_bala.getTexture()->getSize().x),((float)10/sprite_bala.getTexture()->getSize().y));
    sprite_bala.setPosition(posicion);
   // sprite_bal.setColor(Color::Black);
}

Sprite bala::getspritebala()
{
    return sprite_bala;
}

void bala::setpos(Vector2f nuevopos)//Seteamos la bala en la posicion del jugador
{
	posicion=nuevopos;
	sprite_bala.setPosition(posicion);
}

void bala::setDirBala(Vector2f nuevodir){//Posicion del mouse, y formula matematica para ver cuanto tiene que moverse en x y en Y
	float movx,movy;//auxiliares para comprender mejor el codigo
	movx=(nuevodir.x-posicion.x) /(sqrt (pow(nuevodir.x-posicion.x,2) + pow(nuevodir.y-posicion.y,2)) )*pred_bala_velocidad;
    movy=(nuevodir.y-posicion.y) /(sqrt (pow(nuevodir.y-posicion.y,2) + pow(nuevodir.x-posicion.x,2)) )*pred_bala_velocidad;
    mov.x=movx;//mov es el vector de direccion
	mov.y=movy;

}

void bala::movebala(){
	posicion.x+=mov.x;
	posicion.y+=mov.y;
	sprite_bala.setPosition(posicion);
}