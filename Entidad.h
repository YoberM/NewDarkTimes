#ifndef ENTIDAD_H
#define ENTIDAD_H
#include "Headers.h"
#include "State.h"
class Entidad
{
private:
	float posx,posy,objx,objy; //poscicion actual de la entidad y el objetivo al cual quiere ir
    float rad,movrad;//tamano de la figura y su movimiento 
    char type; //tipo de Figura
    bool automatic=0;
    

    int agress_counter=0;
    int aggressiveness=1;

    sf::CircleShape doll;
	sf::Texture texturedoll;
    StateEntidad state;
public:
    Entidad();
    void setcolor(uint,uint,uint);//borrar
	void setObj(float,float);
    void setPosx(float);
    void setPosy(float);
    void setPosx_y(float,float);
    void setRad(float);
    void setMovRad(float);
    void setState(char);
    void setStateres(std::string);
    
    char getStates(){return state.get();}
    sf::CircleShape getDoll(){return doll;}
    float getPosx(){return posx;}
    float getPosy(){return posy;}
    float getRad(){return rad;}
    float getObjx(){return objx;}
    float getObjy(){return objy;}
    float getMovRad(){return rad;}
    StateEntidad& getState(){return state;}
    
    void searchObj();
    void Function_agress();
    void MoveAutomatico();
    void MoveGuidedCol();
    void Dibujar(sf::RenderWindow &);
};
#endif 



