#ifndef JUGADOR_H
#define JUGADOR_H
#include"Headers.h"
#include "bala.h"
#include "ValoresGlobales.h"
using namespace std;
using namespace sf;

class jugador
{
private:
    bala *arrbalas;
    int numbalas;
public:
        Texture textura1;
        Sprite sprite1;
        Vector2i posicionmouse;
        Vector2i seguimiento;
        Vector2f p;
        Vector2f giro;
        int tam;
        float angl;
        double a, b;
        jugador();
        jugador(Texture textuta2, Sprite sprite2);
        Sprite getsprite();
        void setmouse(Vector2i mouse1);
        void setseguimeiento(Vector2i seguimiento1);
        void setmvep(Vector2f p1);
        void setgiro(Vector2f giro1);
        void setangulo(int &tam1, float &angulo, double &a1, double &b1);
        Vector2i getmouse();
        void obtener_mouse(RenderWindow &Window);
        void girarmouse();
        void setmovmou();
        int getBalasNum(){return numbalas;}
        bala& getBala(int i){return arrbalas[i];}



};

#endif 