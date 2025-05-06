#include <iostream>
using namespace std;

// VARIABLES
bool debug = false; 
int pos_caballo_x = 0;
int pos_caballo_y = 0;
const int tam_tablero = 8;
const int tam_alternativas = 8;

int alternativas_x[tam_alternativas] = {2, 1, -1, -2, -2, -1, 1, 2};
int alternativas_y[tam_alternativas] = {1, 2, 2, 1, -1, -2, -2, -1};
int tablero[tam_tablero][tam_tablero];
bool encontrado = false;

void imprimirTablero(int filas, int columnas) {
    cout << "Tablero:" << endl;
    for (int k = 0; k < filas * columnas; k++) {
        int i = k / filas; 
        int j = k % columnas; 
        cout << tablero[i][j] << "  ";
        tablero[i][j] >= 10 ? cout << " " : cout << "  "; 
        if (j == columnas - 1) cout << endl;
    }
}

void inicializarTablero() {
    for (int k = 0; k < tam_tablero * tam_tablero; k++) {
        int i = k / tam_tablero; 
        int j = k % tam_tablero;
        tablero[i][j] = 0; 
    }
}

void deshacerAlternativa(int x, int y) {
    tablero[x][y] = 0;
}

bool alternativaValida(int x, int y) {
    if(x >= tam_tablero || y >= tam_tablero || x < 0 || y < 0) {
        return false;
    } 

    if (tablero[x][y] != 0) {
        return false;
    } 

    return true;
}

void aplicarAlternativa(int x, int y, int paso) {
    tablero[x][y] = paso;
}

bool esSolucion(int paso) {
    if(paso == (tam_tablero * tam_tablero) - 1) {
        return true;
    } else {
        return false;
    }
}

void backtracking(int c_x, int c_y, int paso) {
    int i = 0;

    // Movimientos posibles del caballo = 8
    while (i < 8 /* && !encontrado*/) {
        int nueva_x = c_x + alternativas_x[i];
        int nueva_y = c_y + alternativas_y[i]; 

        if(debug) imprimirTablero(tam_tablero, tam_tablero);

        if(alternativaValida(nueva_x, nueva_y)) {
            aplicarAlternativa(nueva_x, nueva_y, paso + 1);

            if(esSolucion(paso)) {
                imprimirTablero(tam_tablero, tam_tablero);
                cout << "Solucion encontrada" << endl << "Paso: " << paso << endl;
                encontrado = true;
            } else {
                if(debug) imprimirTablero(tam_tablero, tam_tablero);
                backtracking(nueva_x, nueva_y, paso + 1);
            }

            if(!encontrado) {
                deshacerAlternativa(nueva_x, nueva_y);
            }
        }
        i++;
    }
}

int main() {
    inicializarTablero();
    tablero[pos_caballo_y][pos_caballo_x] = 1;
    imprimirTablero(tam_tablero, tam_tablero);
    backtracking(pos_caballo_y, pos_caballo_x, 1); // Lo inicio en en paso = 1, ya que la posicion inicial ya es el primer paso.
    return 0;
}