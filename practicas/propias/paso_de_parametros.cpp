#include <iostream>
using namespace std;

int x = 5, y = 3, z = 8;

void imprimir(int a, int b, int c) {
    cout << a << " " << b << " " << c << endl;
}

int modificar(int &a, int b) {
    a += b;
    imprimir(a, b, x);
    return a * b;
}

int main() {
    int w = modificar(y, x);
    x = 3;
    imprimir(x, y, w);
    x = modificar(y, w);
    imprimir(x, y, w);
    return 0;
}
