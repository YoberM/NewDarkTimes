#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <SFML/Graphics.hpp>
#include <string>
class Entidad
{
	float posx,posy,objx,objy; //Tamaño de la ventana
    char state;
    int automatic=0;
    sf::CircleShape doll;
	sf::Texture texturedoll;
public:
    Entidad();
    Entidad(float,float,float);
    void searchObj();
	void setObj(float,float);
    void Move();
    void MoveAutomatico();
    void Dibujar(sf::RenderWindow &);
};
#endif 



