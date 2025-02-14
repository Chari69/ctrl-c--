#include <iostream>
using namespace std;

int mitad, n;

void entradaDatos(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int polynomialFolding(int *arr, int &n) {
    int num1, num2, auxPos, *arr2;
    auxPos = n - 1;
    for(int i = 0; i < mitad; i++) {
        num1 = arr[i]; num2 = arr[auxPos];
        auxPos--;
        n = n / 2;
        arr2 = new int[n];
        arr2[i] = 2 * num2 - num1;
        arr[i] = arr2[i];
    }
    mitad = mitad / 2;
    if(mitad % 2 != 0) { return arr[0]; }
    if(mitad == 1) { return arr[0]; }
    return -1;
}

int main() {
    int *arr; int aux; 
    cin >> n;

    if(n == 0 || n % 2 != 0) {
        cout << "El tamaño del arreglo debe ser un numero par y distinto a 0";
        return 0;
    }
    arr = new int[n];
    mitad = n / 2;

    entradaDatos(arr, n);
    for(int i = 0; i < mitad; i++) {
        aux = polynomialFolding(arr, n);
    }

    cout << aux << endl;
    return 0;
}