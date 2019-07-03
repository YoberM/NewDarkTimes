#include "Area.h"

void Area::addbloq(int newtam){
    Bloque *n_arr=new Bloque[++size];
    for(int i = 0; i < size-1; i++){
        n_arr[i]=arr[i];
    }
    //seteamos X y Y , que son nuestros "indices" ya que 
    //Nuestro array de bloques es una matriz
    n_arr[size-1].x=(size-1)/numx;//fila
    n_arr[size-1].y=(size-1)%numy;//columna

    n_arr[size-1].setTam(newtam);
    n_arr[size-1].setPosx_y(n_arr[size-1].x*bloqtam+posx,n_arr[size-1].y*bloqtam+posy);
    
    delete[] arr;
    arr=n_arr;
}


void Area::setColorbloq(int n,int r,int g,int b){
    arr[n].setColorBloque(r,g,b);
}

void Area::setTamBloq(int newtam){
    bloqtam=newtam;
}

void Area::set_texture_bloq(const unsigned int n,sf::Texture &textura,char nuevo){
    arr[n].shape.setTexture(&textura);
    arr[n].setState(nuevo);
}
void Area::setnumx(const int newx){numx=newx;}
void Area::setnumy(const int newy){numy=newy;}
void Area::setnumx_y(const int newx,const int newy){
    numx=newx;
    numy=newy;
}

void Area::setposx(const float newposx){posx=newposx;}
void Area::setposy(const float newposy){posy=newposy;}
void Area::setposx_y(const float newposx,const float newposy){
    posx=newposx;
    posy=newposy;
}

void Area::setposx_ybloq(unsigned int n,const float newposx,const float newposy){
    arr[n].setPosx_y(newposx,newposy);
}

