#ifndef Bloque_H
#define Bloque_H
#include <SFML/Graphics.hpp>
#include <string>
class Bloque
{
	float tam; //Tamaño del bloque 
    float posx,posy;
    sf::Texture* textura;
    sf::RectangleShape shape;
public:
    Bloque();
    Bloque(float,float,int);
    void setTexture(sf::Texture);
    void setColor(int,int,int); //test
    void setPosx(float);
    void setPosy(float);
    void setPosx_y(float,float);
};
#endif 


