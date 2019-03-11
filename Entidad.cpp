#include"Entidad.h"
#include<stdlib.h>
#include<iostream>
using namespace std;
#define rango 250
Entidad::Entidad(){
    doll.setPosition(sf::Vector2f(0,0));
    posx=0;posy=0;objx=0;objy=0;
    doll.setRadius(7.5);
    int r=rand()%255;
    int g=rand()%255;
    int b=rand()%255;
    doll.setFillColor(sf::Color(r,g,b));
    doll.setOutlineColor(sf::Color(b,r,g));
    doll.setOutlineThickness(1);
}
Entidad::Entidad(float tam_1,float tam_2,float tam_entity){
    doll.setPosition(sf::Vector2f(tam_1,tam_2));
    posx=tam_1;
    posy=tam_2;
    objx=350;
    objy=350;
    doll.setRadius(tam_entity);
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

void Entidad::Move(){
    int movx,movy;
    if(posx<objx){
        movx=1;
    }
    else if(posx==objx)movx=0;
    else movx=-1;
    if(posy<objy){
        movy=1;
    }
    else if(posy==objy)movy=0;
    else movy=-1;
    doll.move(sf::Vector2f(movx,movy));
    posx+=movx;
    posy+=movy;
    //cout<<posx<<","<<posy<<"|"<<objx<<objy<<endl;
}

void Entidad::MoveAutomatico(){
    /*if (automatic++>300) {
        automatic=automatic%300;
        searchObj();
    }*/

    
    int movx,movy;
    if(posx<objx){
        movx=1;
    }
    else if(posx==objx){
        movx=0;
        searchObj();
    }
    else movx=-1;
    if(posy<objy){
        movy=1;
    }
    else if(posy==objy){
        movy=0;
        searchObj();
    }
    else movy=-1;
    doll.move(sf::Vector2f(movx,movy));
    posx+=movx;
    posy+=movy;
    //cout<<posx<<","<<posy<<"|"<<objx<<objy;
}

void Entidad::Dibujar(sf::RenderWindow &ven_dibujo){
    ven_dibujo.draw(doll);
}