#include "Headers.h"
#include "Mediador.h"
#include <thread>

void Mediator::Acciones(){
    ColisionesEntidadThreads();
    AccionBala();
    ColisionBala();
    
    /*
    for(int i=0;i<numEnt;i++){
        for(int j=0;j<mapa->getarea_num();j++){
            for(int k=0;k<mapa->getArea(j)->getnumbloq();k++){
                cout<<"i->"<<i<<"\nj->"<<j<<"\nk->"<<k<<endl;
                colisiones.Entidad_Bloque(i,j,k);
            }
        }
    }*/

    for(int i=0;i<numEnt;i++){
        entidades[i].setStateres("");
    }
    Spawn();
}

//https://www.bogotobogo.com/cplusplus/C11/3_C11_Threading_Lambda_Functions.php
void Mediator::ColisionesEntidadThreads(){
    thread t([](int inicio,int numEnt,Entidad* entidades,Colisiones colisiones,int salud){
    for(int i=inicio;i<numEnt;i++){
        for(int j=inicio;j<numEnt;j++){
            if(i==j)continue;
            if(entidades[i].getState().get()=='A'){
                entidades[i].getState().addres(entidades[i].getStates() + colisiones.Entidad_Entidad(i,j));
            }
        }
        if(colisiones.Entidad_Jugador(i)){
            std::cout<<-1<<"<salud>"<<salud<<"<-"<<i<<std::endl;
            salud--;
        }
        entidades[i].MoveAutomatico();
    }
    },0,numEnt/4,entidades,colisiones,salud);

    thread t2([](int inicio,int numEnt,Entidad* entidades,Colisiones colisiones,int salud){
    for(int i=inicio;i<numEnt;i++){
        for(int j=inicio;j<numEnt;j++){
            if(i==j)continue;
            if(entidades[i].getState().get()=='A'){
                entidades[i].getState().addres(entidades[i].getStates() + colisiones.Entidad_Entidad(i,j));
            }
        }
        if(colisiones.Entidad_Jugador(i)){
            std::cout<<-1<<"<salud>"<<salud<<"<-"<<i<<std::endl;
            salud--;
        }
        entidades[i].MoveAutomatico();
    }
    },numEnt/4,numEnt*2/4,entidades,colisiones,salud);

    thread t3([](int inicio,int numEnt,Entidad* entidades,Colisiones colisiones,int salud){
    for(int i=inicio;i<numEnt;i++){
        for(int j=inicio;j<numEnt;j++){
            if(i==j)continue;
            if(entidades[i].getState().get()=='A'){
                entidades[i].getState().addres(entidades[i].getStates() + colisiones.Entidad_Entidad(i,j));
            }
        }
        if(colisiones.Entidad_Jugador(i)){
            std::cout<<-1<<"<salud>"<<salud<<"<-"<<i<<std::endl;
            salud--;
        }
        entidades[i].MoveAutomatico();
    }
    },numEnt*2/4,numEnt*3/4,entidades,colisiones,salud);

    thread t4([](int inicio,int numEnt,Entidad* entidades,Colisiones colisiones,int salud){
    for(int i=inicio;i<numEnt;i++){
        for(int j=inicio;j<numEnt;j++){
            if(i==j)continue;
            if(entidades[i].getState().get()=='A'){
                entidades[i].getState().addres(entidades[i].getStates() + colisiones.Entidad_Entidad(i,j));
            }
        }
        if(colisiones.Entidad_Jugador(i)){
            std::cout<<-1<<"<salud>"<<salud<<"<-"<<i<<std::endl;
            salud--;
        }
        entidades[i].MoveAutomatico();
    }
    },numEnt*3/4,numEnt,entidades,colisiones,salud);

    t.join();
    t2.join();
    t3.join();
    t4.join();

}

void Mediator::ColisionBala(){
    for(int i=0;i<numEnt;i++){
        for(int j=0;j<player->getBalasNum();j++){
            if(player->getBala(j).getState().get()=='A'){
                if(colisiones.Entidad_Balas(i,j)){
                    entidades[i].setState('D');
                    player->getBala(j).getState().set('I');
                }
            }
        }
    }

}


void Mediator::AccionBala(){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(boolbala==1){
            player->getBala(auxbalacontador).setpos(player->getsprite().getPosition());
            player->getBala(auxbalacontador).setDirBala((Vector2f)player->getmouse());
            player->getBala(auxbalacontador).getState().set('A');
            auxbalacontador++;
            auxbalacontador=auxbalacontador%20;
            boolbala=0;
        }
    }
    else {
        boolbala=1;
    }
    for(int i=0;i<balanum;i++){
        player->getBala(i).movebala();
    }
}

void Mediator::Spawn(){
    for(int k=0;k<numEnt;k++){
        if(entidades[k].getStates()=='D'){
            int i=rand()%(mapa->getarea_num());
            int j=rand()%(mapa->getarea_num_bloq());
            for(;1;){
                if(SpawnComprobador(i,j)){
                    float nx=mapa->getArea(i)->getbloq(j)->getPosx();//auxiliar
                    float ny=mapa->getArea(i)->getbloq(j)->getPosy();
                    float aux=mapa->getArea(i)->getbloqtam();
                    entidades[k].setPosx_y(nx+aux/2,ny+aux/2);
                    entidades[k].setState('A');
                    break;
                }
                i=rand()%(mapa->getarea_num());
                j=rand()%(mapa->getarea_num_bloq());
            }
        }
        else{
            continue;
        }
    }
}

bool Mediator::SpawnComprobador(int i,int j){
    if(mapa->getArea(i)->getbloq(j)->getStateb()=='s'){
        return 1;
    }
    return 0;
}

void Mediator::setEnt(Entidad *entidades,uint numEnt){
    this->entidades=entidades;
    this->numEnt=numEnt;
    for(int i=0;i<numEnt;i++){
        entidades[i].setPosx_y(100+i*10,100+i*10);
    }
    colisiones.setEntidades(entidades,numEnt);
}

void Mediator::setMapa(Mapa *mapa){
    this->mapa=mapa;
}

void Mediator::setWindow(sf::RenderWindow *window){
    this->window=window;
}

void Mediator::setJugador(jugador* player){
    this->player=player;
    colisiones.setJugador(player);
    balanum=player->getBalasNum();
}

void Mediator::Dibujado(){
    //entidades
    //Bloques
    mapa->Dibujar_mapa(*window);
    for(int i=0;i<numEnt;i++){
        if(entidades[i].getState().get()=='A'){
            entidades[i].Dibujar(*window);

        }
    }
    for(int i=0;i<balanum;i++){
        if(player->getBala(i).getState().get()=='A'){
            window->draw(player->getBala(i).getspritebala());
        }
    }
    window->draw(textopantalla);
}