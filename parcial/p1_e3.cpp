#include <iostream>
using namespace std;

int main() {
    // Declaracion de variables
    int numeroEntrada, numeroSalida, numPar, numImpar;
    int ni1, ni2, ni3, np1, np2, np3;

    // Entrada
    cout << "Introduce un numero: ";
    cin >> numeroEntrada;
    cout << endl;

    // Numeros Impares
    ni1 = numeroEntrada / 100000;
    ni2 = (numeroEntrada / 1000) % 10;
    ni3 = (numeroEntrada / 10) % 10;

    numImpar = (ni1 * 100) + (ni2 * 10) + ni3;

    // Numeros Pares
    np1 = (numeroEntrada / 10000) % 10;
    np2 = (numeroEntrada / 100) % 10;
    np3 = numeroEntrada % 10;
    
    numPar = (np1 * 100) + (np2 * 10) + np3;

    // Salida
    if (numImpar > numPar) {
        numeroSalida = numPar - numImpar;
    } else {
        numeroSalida = numPar * numImpar;
    }

    cout << "El numero resultante es: " << numeroSalida << endl;
    return 0;
}