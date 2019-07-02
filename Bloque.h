#ifndef Bloque_H
#define Bloque_H
#include "Headers.h"
#include "ValoresGlobales.h"
#include "State.h"
class Bloque
{
	float tam; //Tamaño del bloque 
    float posx,posy;
    bool booltexture=0;//dato temporal hasta mejorar codigo
    sf::Texture* textura;
    sf::RectangleShape shape;
    unsigned int x,y;
    friend class Mapa;
    friend class Area;
    StateBloq state;
public:
    Bloque();
    Bloque(const Bloque &);//constructor copia
    Bloque(float,float,int,sf::Texture);
    void setTexture(sf::Texture);
    void setColorBloque(int,int,int); //test
    void setTam(float);
    void setPosx(float);
    void setPosy(float);
    void setPosx_y(float,float);
    int getTam();
    float getPosx();
    float getPosy();
    void setState(char nuevo){state.set(nuevo);}
    char getStateb(){return state.get();}
    StateBloq getState(){return state;}

};
#endif 


