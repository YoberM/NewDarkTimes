#include "Headers.h"
#include "Mediador.h"

void Mediator::Acciones(){
    for(int i=0;i<numEnt;i++){
        for(int j=0;j<numEnt;j++){
            if(i==j)continue;
            std::cout<<entidades[i].getState().getres()<<"<>"<<i<<"<-"<<j<<std::endl;
            std::string temp=colisiones.Entidad_Entidad(i,j);
            entidades[i].setStateres("ga");
            std::cout<<entidades[i].getState().getres()<<std::endl;

            
        }
        entidades[i].MoveAutomatico();
    }
}

void Mediator::setEnt(Entidad *entidades,uint numEnt){
    this->entidades=entidades;
    this->numEnt=numEnt;
    for(int i=0;i<numEnt;i++){
        entidades[i].setPosx_y(500,500);
    }
}

void Mediator::setMapa(Mapa *mapa){
    this->mapa=mapa;
}

void Mediator::setWindow(sf::RenderWindow *window){
    this->window=window;
}

void Mediator::Dibujado(){
    //entidades
    //Bloques
    mapa->Dibujar_mapa(*window);
    for(int i=0;i<numEnt;i++){
        entidades[i].Dibujar(*window);
    }
}