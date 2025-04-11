#include <iostream>

using namespace std;

int printM(int **matriz, int n, int m) {
    int i = 0, j = 1, signo = 1, moverJ = true;
    cout << matriz[0][0] << " ";

    while(i != j) {
        cout << matriz[i][j] << " ";

        if(moverJ) {
            j += signo;
        }

        if(j == m) {
            j--;
            moverJ = false;
        }

        if(!moverJ) {
            i += signo;
        }

        if(i == n) {
            moverJ = true;
            signo = -1;
        }
    }
}

int main() {
    
    return 0;
}

