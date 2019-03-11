#include <iostream>
#include <stdlib.h>
#define rango 30
using namespace std;

int main(){
    srand(time(NULL));
    for(int i=0;i<100;i++){
        cout<<(rand()%(int(0)+2*rango+1)-rango)<<"|";
    }
    cout<<endl;
}

