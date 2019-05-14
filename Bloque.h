#ifndef Bloque_H
#define Bloque_H
#include <SFML/Graphics.hpp>
#include <string>
class Bloque
{
	float tam; //Tamaño del bloque 
    float posx,posy;
    sf::Texture* textura;
    bool booltexture=0;//dato temporal hasta mejorar codigo
    sf::RectangleShape shape;
    friend class Mapa;
    friend class Area;
public:
    Bloque();
    Bloque(const Bloque &);//constructor copia
    Bloque(float,float,int);
    void setTexture(sf::Texture);
    void setColorBloque(int,int,int); //test
    void setTam(float);
    void setPosx(float);
    void setPosy(float);
    void setPosx_y(float,float);
};
#endif 


