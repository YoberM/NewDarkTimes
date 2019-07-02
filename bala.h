#ifndef BALA_H
#define BALA_H
#include "Headers.h"
#include <iterator>
#include "ValoresGlobales.h"
#include "State.h"
using namespace std;
using namespace sf;

class bala
{
private:
    Vector2f mov;
    StateBala state;
public:
    Texture textura_bala;
    Sprite sprite_bala;
    Vector2f posicion;
    Vector2f direccion_bala;
    bool disponible;
    bala();
    bala(Texture textura_bala2, Sprite sprite_bala2,Vector2f pos);
    Sprite getspritebala();
    void setpos(Vector2f);
    void movebala();
    void setvector(Vector2f direccion_bala2);
    void setDirBala(Vector2f);
    StateBala getState(){return state;}
};

#endif 