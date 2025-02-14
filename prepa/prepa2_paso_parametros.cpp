#include <iostream>
using namespace std;

int x, y, z;


void println(int a, int b, int c) {
    cout << "x: " << a << ", y: " << b << ", z: " << c << endl;
}

void f2(int y, int &z) {
    x = 3;       // Modifica la variable global x
    y = 2;       // Modifica la copia local de y
    z = 1;       // Modifica y en f1 (por referencia)
    
    cout << "\nF2->";
    println(x, y, z); 
}

void f1(int &x, int y) {
    x = 5;       // Modifica z en main (por referencia)
    y = 4;       // Modifica la copia local de y
    cout << "\nF1->";
    println(x, y, z); 
    
    cout << "\nLlamada a f2 en f1(z="<<z<<", y="<<y<<"):" << endl;
    f2(z, y);    // Llama a f2 
    
    cout << "\nF1->";
    println(x, y, z); 
}

int main() {
    x = 8;
    y = 7;
    z = 6;

    cout << "Valores iniciales en main:" << endl;
    println(x, y, z);

    cout << "\nLlamada a f1(z="<<z<<", x="<<x<<"):" << endl;
    f1(z, x); 

    cout << "\nLlamada a f2(y="<<y<<", x="<<x<<"):" << endl;
    f2(y, x); 

    cout << "\nValores finales en main:" << endl;
    println(x, y, z); 

    return 0;
}