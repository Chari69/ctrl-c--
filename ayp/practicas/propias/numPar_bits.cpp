#include <iostream>
using namespace std;

int main() {
    while(true) {
        int number = 0; 
        cin >> number;
        cout << ((number & 1) == 0 ? "Par" : "Impar") << endl;
    }
}