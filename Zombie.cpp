#include "Zombie.h"
/* 
Zombie::Zombie(){
    getDoll().setPosition(sf::Vector2f(0,0));
    //agresividad
    //Radio
    setRad(pred_enemy_tam);
    setMovRad(pred_enemy_mov);
    //set
    setPosx_y(getRad(),getRad());
    setObj(0,0);
    //
    getDoll().setRadius(getRad());
    //color
    int r=rand()%255;
    int g=rand()%255;
    int b=rand()%255;
    //Seteando el shape
    getDoll().setFillColor(sf::Color(r,g,b));
    getDoll().setOutlineColor(sf::Color(b,r,g));
    getDoll().setOutlineThickness(1);
}

Zombie::~Zombie(){

}

void Zombie::Function_agress(){
    agress_counter++;
    agress_counter=agress_counter%(aggressiveness*120);
}

void Zombie::searchObj(){
    int nuevoObjx=rand()%(int)(getMovRad()*2)-getMovRad()+getPosx();
    int nuevoObjy=rand()%(int)(getMovRad()*2)-getMovRad()+getPosy();
    setObj(nuevoObjx,nuevoObjy);
    std::cout<<"searchobj"<<nuevoObjx<<"|"<<nuevoObjy<<std::endl;
}

void Zombie::MoveAutomatico(){
    if(getPosx()==getObjx() && getPosx()==getObjx() && agress_counter==0){
        searchObj();
    }
    else Function_agress();
    MoveGuidedCol();
}

void Zombie::MoveGuidedCol(){
    if(getPosx()==getObjx() && getPosy()==getObjy())return;
    float movx=0,movy=0;
    
    movx=(getObjx()-getPosx()) * 1/(sqrt (pow(getObjx()-getPosx(),2) + pow(getObjy()-getPosy(),2)) );
    movy=(getObjy()-getPosy())*1/(sqrt(pow(getObjy()-getPosy(),2)+pow(getObjx()-getPosx(),2)));
    std::cout<<movx<<"|"<<movy<<std::endl;
    if(movx>abs(getObjx()-getPosx())){
        movx=getObjx()-getPosx();
    }
    if(movy>abs(getObjy()-getPosy())){
        movy=getObjy()-getPosy();
    }

    if(getState().contiene('r')&&getState().contiene('t')&&getState().contiene('b')&&getState().contiene('l')){
        movx=1*rand()%2;
        movy=1*rand()%2;
    }
    else{
        if(getState().contiene('r')&&movx>=0){
            //cout<<"col R ";
            movx=0;
        }
         if(getState().contiene('l')&&movx<=0){
            //cout<<"col L ";
            movx=0;
        }
        if(getState().contiene('t')&&movy<=0){
            //cout<<"col T ";
            movy=0;
        }
         if(getState().contiene('b')&&movy>=0){
            //cout<<"col B ";
            movy=0;
        }
    }
    setPosx_y(getPosx()+movx,getPosy()+movy);
}
*/