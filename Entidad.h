#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <SFML/Graphics.hpp>
#include <string>
#include "State.h"
class Entidad
{
	float posx,posy,objx,objy; //Tamaño de la ventana
    float rad,movrad;
    char type; //tipo de Figura
    bool automatic=0;
    int aggressiveness=1; //agresividad , 0 - 3 siendo 3 el peor
    int agress_counter=0;//contador , va sumandose hasta un limite
    sf::CircleShape doll;
	sf::Texture texturedoll;
    StateEntidad state;
public:
    Entidad();
    Entidad(float,float,float);
    void setcolor(uint,uint,uint);//borrar
    void searchObj();
	void setObj(float,float);
    void setPosx(float);
    void setPosy(float);
    void setPosx_y(float,float);
    void setRad(float);
    void setMovRad(float);
    void setState(char);
    void setStateres(std::string);
    float getPosx(){return posx;}
    float getPosy(){return posy;}
    float getRad(){return rad;}
    float getObjx(){return objx;}
    float getObjy(){return objy;}
    StateEntidad getState(){return state;}
    


    void Function_agress();
    void MoveAutomatico();
    void MoveGuided();
    void MoveGuidedCol();
    void Dibujar(sf::RenderWindow &);
};
#endif 



