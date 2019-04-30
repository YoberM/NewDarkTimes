#include <iostream>
#include <stdlib.h>
#define rango 10
using namespace std;

int main(){
    srand(time(NULL));
    int *arr = new int[0];
    for(int i=0;i<(rango*rango);i++,cout<<"i"){
        cout<<i<<"|";
        if(i%2==0){
            arr[i]=0;
        }
        else arr[i]=1;
    }
    cout<<endl;
    for(int i=0;i<rango;i++){
        for(int j=0;j<rango; j++)
        {
            cout<<arr[i*rango+j]<<endl;
        }
        
    }
    cout<<endl;
}

