#ifndef MAPA_H
#define MAPA_H
#include"Headers.h"
class Mapa
{
	float tam; //Tamaño del mapa
    int area_num;//cantidad de Areas normalmente cuadrado
    int area_numx;
    int area_numy;
    int area_numbloq;//cantidad de bloques por area
    int area_numbloqx;
    int area_numbloqy;
    int area_tamx;
    int area_tamy;
    Area *arr_areas;
public:
    Mapa(float,int,int);
    //tamano del mapa , numero de areas , numero de bloques por area
    Mapa(float,int,int,int,int);
    //tamano del mapa , numero de areas en X y Y , numnero de bloques por area X y Y
    Mapa(float,int,int[]);
    ~Mapa();
	void Random(sf::RenderWindow&);
    void Dibujar_mapa(sf::RenderWindow&);
    void Dibujar(sf::RenderWindow&,int);
    void Dibujar_Area(sf::RenderWindow&,int);
};
#endif 


