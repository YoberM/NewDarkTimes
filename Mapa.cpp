#include "Mapa.h"
#define r rand()%255
#define rango 17
Mapa::Mapa(float tam_new,int n_cantidad,int n_cantidadbloq){ //tam_new tamaño del mapa ,n_cantidad= numero de areas
    area_numx=n_cantidad;
    area_numy=n_cantidad;
    area_num=n_cantidad*n_cantidad;
    area_numbloq=n_cantidadbloq*n_cantidadbloq;
    area_numbloqx=n_cantidadbloq;
    area_numbloqy=n_cantidadbloq;
    tam=tam_new;
    Area *new_area = new Area[area_numx*area_numy];
    for(int i=0;i<area_num;i++){
        for(int j=0;j<area_numbloq;j++){
            new_area[i].addbloq(pred_bloq_tam);
            new_area[i].setColorbloq(j,255,255,255);
            new_area[i].setTamBloq(j,pred_bloq_tam);
        }
    }
    arr_areas=new_area;
}
 
Mapa::Mapa(float tam_new,int n_cantidadx,int n_cantidady,int n_cantidadbloqx,int n_cantidadbloqy){
    if(n_cantidady==-1){
        area_numx=n_cantidadx;
        area_numy=n_cantidadx;
    }
    area_num=n_cantidadx*n_cantidady;
    tam=tam_new;
    arr_areas->arr[0].shape.setSize(sf::Vector2f(tam,tam));
    bool aux=0;
    for(int i=0;i<area_numx;i++){
        for(int j=0;j<area_numy;j++){
            if(aux==0)arr_areas[i].setColorbloq(j,100,255,255);
            else arr_areas[i].setColorbloq(j,0,0,0);
            aux=!aux;
        }
        
    }
}

Mapa::Mapa(float tam_new,int cantidad,int *new_array){
    ;
}

Mapa::~Mapa(){
    delete[] arr_areas;
}

void Mapa::Random(sf::RenderWindow &window){
    sf::Vector2u asd= window.getSize();
    bool aux=0;
    for(int i=0;i<area_numx;i++){
        for(int j=0;j<area_numy; j++)
        {
            if(aux=0){
                arr_areas->arr[i*area_numx+area_numy].shape.setFillColor(sf::Color(255,255,255));
            }
            else
            {
                arr_areas->arr[i*area_numx+area_numy].shape.setFillColor(sf::Color(0,0,0));
            }
            arr_areas->arr[i*area_numx+area_numy].shape.setPosition(sf::Vector2f(j*tam,i*tam));
            Dibujar(window,i*area_numx+area_numy);
        }
        
    }
}

void Mapa::Dibujar_mapa(sf::RenderWindow &window){
    for(int i = 0; i < area_numx; i++){
        for(int j = 0; i < area_numy; i++){
            Dibujar(window,i*area_numx);
        }
        
    }
    
}

void Mapa::Dibujar(sf::RenderWindow &window,int n){
    window.draw(arr_areas->arr[n].shape);
}
