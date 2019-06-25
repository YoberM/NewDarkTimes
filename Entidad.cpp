#include "Headers.h"
#include "ValoresGlobales.h"
#include "State.h"
#include "Entidad.h"
using namespace std;

void Entidad::setcolor(uint r,uint g,uint b){
    doll.setFillColor(sf::Color(r,g,b));
}

Entidad::Entidad(){
    doll.setPosition(sf::Vector2f(0,0));
    //agresividad
    aggressiveness=rand()%4+1;
    //Radio
    rad=pred_enemy_tam;
    movrad=pred_enemy_mov;
    //set
    posx=rad;
    posy=rad;
    objx=0;
    objy=0;
    //
    movrad=pred_enemy_mov;
    doll.setRadius(pred_enemy_tam);
    //color
    int r=rand()%255;
    int g=rand()%255;
    int b=rand()%255;
    //Seteando el shape
    doll.setFillColor(sf::Color(r,g,b));
    doll.setOutlineColor(sf::Color(b,r,g));
    doll.setOutlineThickness(1);
}
Entidad::Entidad(float tam_1,float tam_2,float radius){
    doll.setPosition(sf::Vector2f(tam_1,tam_2));
    posx=tam_1;
    posy=tam_2;
    objx=350;
    objy=350;
    movrad=pred_enemy_mov;
    doll.setRadius(radius);
    int r=rand()%255;
    int g=rand()%255;
    int b=rand()%255;
    doll.setFillColor(sf::Color(r,g,b));
}

void Entidad::searchObj(){
    setObj(rand()%(int)(movrad*2)-movrad+posx,rand()%(int)(movrad*2)-movrad+posy);
}

void Entidad::setObj(float newx,float newy){
    objx=newx;
    objy=newy;
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
    setPosx(newx);
    setPosy(newy);
}
void Entidad::setStateres(std::string statenew){
    state.setres(statenew);
}

void Entidad::Function_agress(){
    agress_counter++;
    agress_counter=agress_counter%(aggressiveness*120);
}


void Entidad::MoveAutomatico(){
    if(posx==objx && posy==objy && agress_counter==0){
        searchObj();
    }
    else Function_agress();
    MoveGuidedCol();
}
void Entidad::MoveGuided(){
    if(posx==objx && posy==objy)return;
    float movx=0,movy=0;
    movx=(objx-posx)*1/(sqrt(pow(objx-posx,2)+pow(objy-posy,2)));
    movy=(objy-posy)*1/(sqrt(pow(objy-posy,2)+pow(objx-posx,2)));
    if(movx>abs(objx-posx))movx=objx-posx;
    if(movy>abs(objy-posy))movy=objy-posy;
    posx+=movx;
    posy+=movy;
    doll.move(sf::Vector2f(movx,movy));
    //cout<<"moveguided::"<<movx<<"|"<<movy<<"||"<<posx<<"|"<<posy<<endl;
}

void Entidad::MoveGuidedCol(){
    if(posx==objx && posy==objy)return;
    float movx=0,movy=0;
    movx=(objx-posx)*1/(sqrt(pow(objx-posx,2)+pow(objy-posy,2)));
    movy=(objy-posy)*1/(sqrt(pow(objy-posy,2)+pow(objx-posx,2)));
    if(movx>abs(objx-posx))movx=objx-posx;
    if(movy>abs(objy-posy))movy=objy-posy;
    posx+=movx;
    posy+=movy;
    if(state.getres().find("r")&&movx>=0){
        movx=0;
    }
    else if(state.getres().find("l")&&movx<=0){
        movx=0;
    }
    if(state.getres().find("t")&&movy<=0){
        movy=0;
    }
    else if(state.getres().find("b")&&movy>=0){
        movy=0;
    }
    doll.move(sf::Vector2f(movx,movy));

}

void Entidad::Dibujar(sf::RenderWindow &ven_dibujo){
    ven_dibujo.draw(doll);
}