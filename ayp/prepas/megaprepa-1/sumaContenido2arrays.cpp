#include<iostream>

using namespace std;

int main(){
    int arreglo1[5]={1,2,3,4,5};
    int arreglo2[5]={6,7,8,9,10};
    int arreglo3[10];

    for(int i=0; i<5;i++){
        arreglo3[i]=arreglo1[i];
        arreglo3[i+5]=arreglo2[i];
    }
    for(int i=0;i<10;i++){
        cout<<arreglo3[i];
    }
}

