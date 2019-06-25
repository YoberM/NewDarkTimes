#include "Colisiones.h"
#include "Entidad.h"
#include "Headers.h"

std::string Colisiones::Entidad_Entidad(int n,int m){
    std::string Direccion ="N";
    if(sqrt(pow(abs(entidades[n].getPosx()-entidades[m].getPosx()),2)+pow(abs(entidades[n].getPosy()-entidades[m].getPosy()),2))
    <= entidades[n].getRad()+entidades[m].getRad()
    ){
        //std::cout <<"Colision"<<sqrt(pow(entidades[n].getPosx()-entidades[m].getPosx(),2))<<" || Rad-> "<<entidades[n].getRad()+entidades[m].getRad();
        entidades[n].setcolor(255,255,255);
        entidades[m].setcolor(255,255,255);
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
        //std::cout<<Direccion;
    }
    else{
        entidades[n].setcolor(0,0,0);
        entidades[m].setcolor(0,0,0);
    }
    ////std::cout <<"No "<<sqrt(pow(entidades[n].getPosx()-entidades[m].getPosx(),2));
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
                entidades[n].getRad()+jugador->getRad()){

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
            //entidades[i].;
        }
        
    }
    
}

void Colisiones::ColisionesEntid_Bloq(){
    
}

void Colisiones::ColisionesEntid_Jug(){
    
}