#ifndef AREA_H
#define AREA_H
class Area{
    Bloque *arr;
    unsigned int numx;//numero de bloques en x
    unsigned int numy;//numero de bloques en y
    unsigned int size;//numero total de bloques
    float posx;       //pos en x
    float posy;       //pos en y
    float bloqtam;
    friend class Mapa;//para poder acceder a los datos desde mapa y bloque
public:
    Area(){//por defecto
        posx=0;
        posy=0;
        numx=0;
        numy=0;
        size=0;
        bloqtam=0;
        arr=new Bloque[size];}
    Area(int n){//con un rango cuadrado de bloques
        numx=n;
        numy=n;
        size=n*n;
        arr=new Bloque[size];
    }
    Area(int n_numx,int n_numy){//con un rango de X y Y
        numx=n_numx;
        numy=n_numy;
        size=numx*numy;
        arr=new Bloque[size];
    }
    Area(const Bloque *bloqarr,int n_size){
        size=n_size;
        for(int i=0;i<n_size;i++){
            arr[i]=bloqarr[i];
        }
    }
    Area(Area &otherarea){
        size = otherarea.size;
        for(int i=0;i<size;i++){
            arr[i]=otherarea.arr[i];
        }
    }
    void addbloq(int);
    void setColorbloq(int ,int,int,int);
    void setTamBloq(int);
    void set_texture_bloq(const unsigned int,sf::Texture &){
        ;
    }
    void setnumx(const int);
    void setnumy(const int);
    void setnumx_y(const int,const int);
    void setposx(const float);
    void setposy(const float);
    void setposx_y(const float,const float);
    void setposx_ybloq(unsigned int,const float,const float);
};

#endif //AREA_H