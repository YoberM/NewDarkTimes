#ifndef MAPA_H
#define MAPA_H
#include <SFML/Graphics.hpp>
#include <string>
class Mapa
{
	float tam; //Tamaño de la ventana
    sf::RenderTexture textura;
    sf::RectangleShape shape;
public:
    Mapa(float);
	void Random(sf::RenderWindow&);
    void Dibujar(sf::RenderWindow&);
};
#endif 


