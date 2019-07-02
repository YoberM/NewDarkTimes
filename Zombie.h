#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "Headers.h"
#include "Entidad.h"
#include "ValoresGlobales.h"

class Zombie : public Entidad{
    
    int agress_counter=0;
    int aggressiveness=1;
public:
    Zombie();
    ~Zombie();
    void searchObj();
    void Function_agress();
    void MoveAutomatico();
    void MoveGuidedCol();
};
#endif //ZOMBIE_H
