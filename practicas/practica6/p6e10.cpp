// Practica 6, ejercicio 10

/* Haga una función que tome como entrada una matriz cuadrada de N × M y
retorne la matriz traspuesta de M × N . Recuerde que la matriz traspuesta
es aquella en donde se intercambian filas por columnas. Por ejemplo,
si la matriz original es A = {{1, 5}, {2, 3}}, la función debe retornar
{{1, 2}{5, 3}}. */

#include <iostream>
using namespace std;

void introducirValor(int **matriz, int n) {
    int noI = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "Introduce un Valor para: " << i << ", " << j << ": ";
            cin >> noI;
            matriz[i][j] = noI;
        }
    }
}

void recorrer(int **matriz, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "[" << matriz[i][j] << "] ";
        }
        cout << endl;
    }
}

void matrizTrasp(int **matriz, int n) {
    int **b;
    b = new int*[n];
    for(int i = 0; i < n; i++) {
        b[i] = new int[n];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            b[j][i] = matriz[i][j];
        }
    }

    cout << endl << "Matriz Traspuesta:" << endl;
    recorrer(b, n);
}

int main() {
    int n = 0; int **matriz; // El numero de celdas (n=2, 2x2) || Declaracion matriz.
    cout << "Introduce el numero de FxC (ej: 3): ";
    cin >> n;
    cout << endl;
    matriz = new int*[n];
    for(int i = 0; i < n; i++) {
        matriz[i] = new int[n];
    }
    introducirValor(matriz, n);
    cout << "Matriz Original" << endl;
    recorrer(matriz, n);
    matrizTrasp(matriz, n);
    return 0;
}