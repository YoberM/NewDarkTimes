#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <SFML/Graphics.hpp>
#include <string>
class Entidad
{
	float posx,posy,objx,objy; //Tamaño de la ventana
    float rad,movrad;
    char state;
    int automatic=0;
    int aggressiveness=1; //agresividad , 0 - 3 siendo 3 el peor
    int agress_counter=0;//contador , va sumandose hasta un limite
    sf::CircleShape doll;
	sf::Texture texturedoll;
public:
    Entidad();
    Entidad(float,float,float);
    void searchObj();
	void setObj(float,float);
    void setPosx(float);
    void setPosy(float);
    void setPosx_y(float,float);
    void Function_agress();
    void MoveAutomatico();
    void MoveGuided();
    void Dibujar(sf::RenderWindow &);
};
#endif 



