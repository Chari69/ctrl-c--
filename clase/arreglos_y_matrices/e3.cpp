#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            bool printX = false;
            for(int k = n; k >=1; k -= 4) {
                int margen = (n-k) / 2;
                int fin = margen + k - 1;

                if(i == margen || i == fin) {
                    printX = true;
                } else if (j == margen || j == fin) {
                    if(i >= margen && i <= fin) {
                        printX = true;
                    }
                }
                if (printX == true) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}