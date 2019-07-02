#include "Headers.h"
#include "Mediador.h"

void Mediator::Acciones(){
    for(int i=0;i<numEnt;i++){
        for(int j=0;j<numEnt;j++){
            if(i==j)continue;
                entidades[i].setStateres(entidades[i].getStates() + colisiones.Entidad_Entidad(i,j));
        }
    }
    
    for(int i=0;i<numEnt;i++){
        entidades[i].setStateres("");
    }
    Spawn();
}

void Mediator::Spawn(){
    for(int k=0;k<numEnt;k++){
        if(entidades[k].getStates()=='D'){
            int i=rand()%(mapa->getarea_num());
            int j=rand()%(mapa->getarea_num_bloq());
            for(;1;){
                if(SpawnComprobador(i,j)){
                    float nx=mapa->getArea(i)->getbloq(j)->getPosx();//auxiliar
                    float ny=mapa->getArea(i)->getbloq(j)->getPosy();
                    float aux=mapa->getArea(i)->getbloqtam();
                    entidades[k].setPosx_y(nx+aux/2,ny+aux/2);
                    entidades[k].setState('A');
                    break;
                }
                i=rand()%(mapa->getarea_num());
                j=rand()%(mapa->getarea_num_bloq());
            }
        }
        else{
            continue;
        }
    }
}

bool Mediator::SpawnComprobador(int i,int j){
    if(mapa->getArea(i)->getbloq(j)->getStateb()=='s'){
        return 1;
    }
    return 0;
}

void Mediator::setEnt(Entidad *entidades,uint numEnt){
    this->entidades=entidades;
    this->numEnt=numEnt;
    for(int i=0;i<numEnt;i++){
        entidades[i].setPosx_y(100+i*10,100+i*10);
    }
    colisiones.setEntidades(entidades,numEnt);
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