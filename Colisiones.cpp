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
    };
    return Direccion;
}

std::string Colisiones::Entidad_Bloque(int n,int m,int o){//N entidad, M area , O Bloque;
    float ex=entidades[n].getPosx();
    float ey=entidades[n].getPosy();
    float er=entidades[n].getRad();
    float bloqtam=mapa->getArea(m)->getbloq(o)->getTam();
    float bloqx=mapa->getArea(m)->getbloq(o)->getPosx();
    float bloqy=mapa->getArea(m)->getbloq(o)->getPosy();
    if(ex<bloqx&&ex>bloqx+bloqtam){
        float px=ex;
        float py;
        if(ey<bloqy+bloqtam/2){
            py=ey+er;
            if(bloqy-ey<=0){
                return "b";
            }
        }
        else if(ey>bloqy+bloqtam/2){
            py=ey-er;
            if (ey-bloqy<=0){
                return "t";
            }
        }
    }
    else if(ey<bloqy&&ey>bloqy+bloqtam){
        float py=ey;
        float px;
        if(ex<bloqx+bloqtam/2){
            px=ex+er;
            if(bloqx-ex<=0){
                return "b";
            }
        }
        else if(ex>bloqx+bloqtam/2){
            px=ex-er;
            if (ex-bloqx<=0){
                return "t";
            }
        }
    }
    return "";
    
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
