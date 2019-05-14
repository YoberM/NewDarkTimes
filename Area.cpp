#include "Headers.h"

void Area::addbloq(int newtam){
    Bloque *n_arr=new Bloque[++size];
    for(int i = 0; i < size-1; i++){
        n_arr[i]=arr[i];
    }
    n_arr[size-1].setPosx_y((int)numx/size,(int)numy%size);
    n_arr[size-1].setTam(newtam);
    delete[] arr;
    arr=n_arr;
}

void Area::setTamBloq(int n,int newtam){
    arr[n].setTam(newtam);
}

void Area::setColorbloq(int n,int r,int g,int b){
    arr[n].setColorBloque(r,g,b);
}