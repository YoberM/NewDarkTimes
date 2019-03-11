#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>
#include <string>
class Window
{
	float tamx,tamy; //Tamaño de la ventana
    sf::RenderWindow window;
public:
    Window(float,float,std::string);
	void Abierto(bool);
    void Dibujar();
};
#endif 



