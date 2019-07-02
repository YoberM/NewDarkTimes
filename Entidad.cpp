#include "Headers.h"
#include "ValoresGlobales.h"
#include "State.h"
#include "Entidad.h"
using namespace std;

Entidad::Entidad(){
    doll.setPosition(sf::Vector2f(0,0));
    //agresividad
    //Radio
    rad=pred_enemy_tam;
    movrad=pred_enemy_mov;
    //set
    setPosx_y(rad,rad);
    setObj(0,0);
    //
    doll.setRadius(rad);
    //color
    int r=rand()%255;
    int g=rand()%255;
    int b=rand()%255;
    //Seteando el shape
    doll.setFillColor(sf::Color(r,g,b));
    doll.setOutlineColor(sf::Color(b,r,g));
    doll.setOutlineThickness(1);

}
Entidad::~Entidad(){
    
}

void Entidad::setcolor(uint r,uint g,uint b){
    doll.setFillColor(sf::Color(r,g,b));
}


void Entidad::setObj(float newx,float newy){
    objx=newx;
    objy=newy;
}

void Entidad::setRad(float rad){
    this->rad=rad;
}

void Entidad::setState(char nuevo){
    state.set(nuevo);
}

void Entidad::setMovRad(float rad){
    this->movrad=movrad;
}

void Entidad::setPosx(float newx){
    posx=newx+rad;
    objx=newx+rad;
    doll.setPosition(sf::Vector2f(newx,posy)); 
}
void Entidad::setPosy(float newy){
    posy=newy+rad;
    objy=newy+rad;
    doll.setPosition(sf::Vector2f(posx,newy));
}
void Entidad::setPosx_y(float newx,float newy){
    posx=newx + rad;
    objx=posx;
    posy=newy +rad;
    objy=posy;
    doll.setPosition(sf::Vector2f(posx-rad,posy-rad));
}
void Entidad::setStateres(std::string statenew){
    state.setres(statenew);
}

void Entidad::Dibujar(sf::RenderWindow &ven_dibujo){
    ven_dibujo.draw(doll);
}
void Entidad::Function_agress(){
    agress_counter++;
    agress_counter=agress_counter%(aggressiveness*120);
}

void Entidad::searchObj(){
    int nuevoObjx=rand()%(int)(movrad*2)-movrad+posx;
    int nuevoObjy=rand()%(int)(movrad*2)-movrad+posy;
    setObj(nuevoObjx,nuevoObjy);
    }

void Entidad::MoveAutomatico(){
    if(posx==objx && posx==objx && agress_counter==0){
        searchObj();
    }
    else Function_agress();
    MoveGuidedCol();
}

void Entidad::MoveGuidedCol(){
    if(posx==objx && posy==objy)return;
    float movx=0,movy=0;
    
    movx=(objx-posx) /(sqrt (pow(objx-posx,2) + pow(objy-posy,2)) )*pred_enemy_movrango;
    movy=(objy-posy) /(sqrt (pow(objy-posy,2) + pow(objx-posx,2)) )*pred_enemy_movrango;
    if(abs(movx)>abs(objx-posx)){
        movx=objx-posx;
    }
    if(abs(movy)>abs(objy-posy)){
        movy=objy-posy;
    }

    if(state.contiene('r')&&state.contiene('t')&&state.contiene('b')&&state.contiene('l')){
        movx=1-2*(rand()%2);
        movy=1-2*(rand()%2);
    }
    else{
        if(state.contiene('r')&&movx>=0){
            movx=0;
        }
        if(state.contiene('l')&&movx<=0){
            movx=0;
        }
        if(state.contiene('t')&&movy<=0){
            movy=0;
        }
        if(state.contiene('b')&&movy>=0){
            movy=0;
        }
    }
    posx+=movx;
    posy+=movy;
    doll.setPosition(posx-rad,posy-rad);
}