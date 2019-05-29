#ifndef COLISIONES_H
#define COLISIONES_H
#include "Headers.h"
class Colisiones {
    Entidad *entidades;
    int entidad_size;
    Bloque *bloques;
    int bloque_size;
public:
    Colisiones(){
        entidad_size = 0;
        entidades = new Entidad[entidad_size];
        bloque_size = 0;
        bloques = new Bloque[bloque_size];
    }
    Colisiones(Entidad *n_ent,int n_enti_size,Bloque *n_blo,int n_bloq_size){
        
    }
    bool Entidad_Entidad(int,int);
};

#endif //COLISIONES_H



