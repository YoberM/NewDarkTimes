#include "Colisiones.h"
#include "Entidad.h"
#include "Headers.h"

std::string Colisiones::Entidad_Entidad(int n,int m){
    std::string Direccion ="";
    if(sqrt(pow(abs(entidades[n].getPosx()-entidades[m].getPosx()),2) +
            pow(abs(entidades[n].getPosy()-entidades[m].getPosy()),2) )
    <= entidades[n].getRad()+entidades[m].getRad()){

        if(entidades[n].getPosx()-entidades[m].getPosx()>=0){
            Direccion+="l";//left
        }
        if(entidades[n].getPosx()-entidades[m].getPosx()<=0){
            Direccion+="r";//right
        }
        if(entidades[n].getPosy()-entidades[m].getPosy()>=0){
            Direccion+="t";//top
        }
        if(entidades[n].getPosy()-entidades[m].getPosy()<=0){
            Direccion+="b";//bottom
        }
    }
    return Direccion;
}

std::string Colisiones::Entidad_Bloque(int n,int m,int o){
    std::string Direccion = "";
    
}

bool Colisiones::Entidad_Jugador(int n){
    //Formula para colisiones con circulos
    std::string Direccion ="";
    if(sqrt(pow(abs(entidades[n].getPosx() - player->getsprite().getPosition().x),2) +
            pow(abs(entidades[n].getPosy() - player->getsprite().getPosition().y),2)) <= 
                entidades[n].getRad()+15){
                    entidades[n].setcolor(255,255,255);
        return 1;
    }
                    entidades[n].setcolor(0,0,0);
    return 0;
    //if(entidades[n]);
}

bool Colisiones::Entidad_Balas(int i,int j){//id Entidad, j->balaid

    if(sqrt(pow(abs(entidades[i].getPosx()-player->getBala(j).getspritebala().getPosition().x),2) +
            pow(abs(entidades[i].getPosy()-player->getBala(j).getspritebala().getPosition().y),2) )
    <= entidades[i].getRad()+player->getBala(j).getspritebala().getScale().x){
        return 1;
    }
    return 0;
}
