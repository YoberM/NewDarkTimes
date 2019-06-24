#include "Headers.h"
#include "Mediador.h"

void Mediator::Acciones(){
    for(int i=0;i<numEnt;i++){
        for(int j=0;j<numEnt;i++){
            if(i==j)continue;
            std::string temp=colisiones.Entidad_Entidad(i,j);
            entidades[i].getState().setres(temp);
        
            
        }
    }
}

void Mediator::Dibujado(sf::RenderWindow &window){
    //entidades
    for(int i=0;i<numEnt;i++){
        entidades[i].Dibujar(window);
    }
    //Bloques
    mapa.Dibujar_mapa(window);
}