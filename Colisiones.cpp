#include "Headers.h"

std::string Colisiones::Entidad_Entidad(int n,int m){
    std::string Direccion ="";
    if(sqrt(pow(entidades[n].getPosx()-entidades[m].getPosx(),2))-
            pow(entidades[n].getPosy()-entidades[m].getPosy(),2) <= 
                        entidades[n].getTam()+entidades[m].getTam()){

        if(entidades[n].getPosx()-entidades[m].getPosx()>0){
            Direccion+="r";//right
        }
        else if(entidades[n].getPosx()-entidades[m].getPosx()<0){
            Direccion+="l";//left
        }
        else if(entidades[n].getPosy()-entidades[m].getPosy()>0){
            Direccion+="b";//bottom
        }
        else if(entidades[n].getPosy()-entidades[m].getPosy()>0){
            Direccion+="t";//top
        }
    }
    return Direccion;
}

std::string Colisiones::Entidad_Bloque(int n,int m){
    //if(entidades[n]);
}

std::string Colisiones::Entidad_Jugador(int n){
    //Formula para colisiones con circulos
    std::string Direccion ="";
    if(sqrt(pow(entidades[n].getPosx()-jugador->getPosx(),2))-
            pow(entidades[n].getPosy() - jugador->getPosy(),2) <= 
                entidades[n].getTam()+jugador->getTam()){

        if(entidades[n].getPosx()-jugador->getPosx()>0){
            Direccion+="r";//right
        }
        else if(entidades[n].getPosx()-jugador->getPosx()<0){
            Direccion+="l";//left
        }
        else if(entidades[n].getPosy()-jugador->getPosy()>0){
            Direccion+="b";//bottom
        }
        else if(entidades[n].getPosy()-jugador->getPosy()>0){
            Direccion+="t";//top
        }
    }
    return Direccion;
    //if(entidades[n]);
}

void Colisiones::ColisionesEntidades(){
    for (int i = 0; i < entidad_size; i++)
    {
        for (int j = 0; i < entidad_size; j++)
        {
            
        }
        
    }
    
}

void Colisiones::ColisionesEntid_Bloq(){
    
}

void Colisiones::ColisionesEntid_Jug(){
    
}