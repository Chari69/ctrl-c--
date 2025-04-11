#include <iostream>

using namespace std;

int main() {
    int A, B, n;
    cin >> A >> B;
    int **arr;
    arr = new int*[A];
    for(int i = 0; i < A; i++) {
        arr[i] = new int[B];
    }

    for(int i = 0; i < A; i++) {
        for(int j = 0; j < B; j++) {
            cout << "Introduce un Valor para: " << i << ", " << j << ": ";
            cin >> n;
            arr[i][j] = n;
        }
    }

    cout << endl;

    for(int i = 0; i < A; i++) {
        for(int j = 0; j < B; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}