#include <iostream>
using namespace std;

const int tam_alternativa = 8;

int alternativas_x[tam_alternativa] = {2, 2, -2, -2, 1, 1, -1, -1};
int alternativas_y[tam_alternativa] = {1, -1, 1, -1, 2, -2, 2, -2};

bool encontrado = false;

int tablero[tam_alternativa][tam_alternativa];

struct Caballo {
    int x = 2;
    int y = 3;
    char nombre = 'C';

    int x_old = 0;
    int y_old = 0;
};

Caballo caballo;

void imprimirTablero() {
    for (int i = 0; i < tam_alternativa; i++) {
        for (int j = 0; j < tam_alternativa; j++) {
            if (caballo.x == i && caballo.y == j) {
                cout << caballo.nombre << " ";
            } else {
                cout << tablero[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// OPTIMIZAR ESTO, ES UNA PUTA MIERDA
void inicializarTablero() {
    for (int i = 0; i < tam_alternativa; i++) {
        for (int j = 0; j < tam_alternativa; j++) {
            tablero[i][j] = 0;
        }
    }
    imprimirTablero();
}

void deshacerAlternativa(Caballo &caballo) {
    tablero[caballo.x][caballo.y] = 0;
    caballo.x = caballo.x_old;
    caballo.y = caballo.y_old;
}

bool alternativaValida(int x, int y) {
    if(x >= tam_alternativa || y >= tam_alternativa || (x < 0 || y < 0)) {
        return false;
    } else {
        return true;
    }
}

void aplicarAlternativa(int x, int y) {
    caballo.x = x;
    caballo.y = y;
    tablero[x][y] = 1;
    cout << "Alternativa aplicada: " << caballo.x << ", " << caballo.y << endl;
}

bool esSolucion(int x, int y) {
    int contador = 0;
    for (int i = 0; i < tam_alternativa; i++) {
        for (int j = 0; j < tam_alternativa; j++) {
            if (tablero[i][j] == 1) {
                contador++;
            }
        }
    }
    if (contador == tam_alternativa * tam_alternativa) {
        return true;
    } else {
        return false;
    }
}


void backtracking(int paso = 0, int i = 0, int j = 0) {
    while (i < 8 /* && !encontrado*/) {
        caballo.x_old = caballo.x;
        caballo.y_old = caballo.y;
        int nueva_x = caballo.x + alternativas_x[i];
        int nueva_y = caballo.y + alternativas_y[i];

        cout << "Paso numero:" << endl;

        imprimirTablero();


        if(alternativaValida(nueva_x, nueva_y)) {
            aplicarAlternativa(nueva_x, nueva_y);

            if(esSolucion(nueva_x, nueva_y)) {
                encontrado = true;
            } else {
                backtracking(paso + 1);
            }


            if(!encontrado) {
                deshacerAlternativa(caballo);
            }
        }
        i++;
    }
}

int main() {

    inicializarTablero();
    backtracking(0);
}