#include <iostream>
using namespace std;

int diagonalSec(int **matriz, int n) {
    int suma = 0;
    int pos = n - 1;

    for(int i = 0; i < n; i++) {
        for(int j = pos; j >= 0; j--) {
            if (j == pos) {
                //cout << matriz[i][pos] << endl;
                suma += matriz[i][pos];
                pos--;
                break;
            }
        }
    }
    return suma;
}

int main(){
    int n; int **matriz;
    cin >> n;

    matriz = new int*[n];
    for(int i = 0; i < n; i++) {
        matriz[i] = new int[n];
    }

    cout << "Introduce los datos para la matriz:";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    cout << endl << "El resultado es:" << diagonalSec(matriz, n) << endl;
    return 0;
}