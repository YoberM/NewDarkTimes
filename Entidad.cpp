#include"Entidad.h"
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;
#define rango 250
Entidad::Entidad(){
    doll.setPosition(sf::Vector2f(0,0));
    //agresividad
    aggressiveness=rand()%4+1;
    //set
    posx=0;posy=0;objx=0;objy=0;
    movrad=7.5;
    doll.setRadius(7.5);
    //color
    int r=rand()%255;
    int g=rand()%255;
    int b=rand()%255;
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
    movrad=radius;
    doll.setRadius(radius);
    int r=rand()%255;
    int g=rand()%255;
    int b=rand()%255;
    doll.setFillColor(sf::Color(r,g,b));
}

void Entidad::searchObj(){
    setObj((rand()%(int(posx)+(2*rango)))-rango,(rand()%(int(posy)+(2*rango)))-rango);
    if(objx<=0)objx=0;
    if(objy<=0)objy=0;
}

void Entidad::setObj(float newx,float newy){
    objx=newx;
    objy=newy;
}

void Entidad::setPosx(float newx){
    posx=newx;
    objx=newx;
    doll.setPosition(sf::Vector2f(newx,posy)); 
}
void Entidad::setPosy(float newy){
    posy=newy;
    objy=newy;
    doll.setPosition(sf::Vector2f(posx,newy));
}
void Entidad::setPosx_y(float newx,float newy){
    setPosx(newx); setPosy(newy);
}

void Entidad::Function_agress(){
    agress_counter++;
    agress_counter=agress_counter%(aggressiveness*120);
}


void Entidad::MoveAutomatico(){
    Function_agress();
    if(posx==objx && posy==objy && agress_counter==0){
        searchObj();
    }
    MoveGuided();
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

void Entidad::Dibujar(sf::RenderWindow &ven_dibujo){
    ven_dibujo.draw(doll);
}