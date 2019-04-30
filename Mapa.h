#ifndef MAPA_H
#define MAPA_H
#include <SFML/Graphics.hpp>
#include <string>
class Mapa
{
	float tam; //Tamaño de la ventana
    int cantidad;
    int *arr;
    sf::RenderTexture textura;
    sf::RectangleShape shape;
public:
    Mapa(float,int);
    Mapa(float,int,int[]);
	void Random(sf::RenderWindow&);
    void Dibujar(sf::RenderWindow&);
};
#endif 


