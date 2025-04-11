#include <iostream>

using namespace std;

int main() {
    for(int i = 0; i < 5; i++) {
        cout << "*";
    }

    cout << endl;

    for(int i = 0; i < 5; i++) {
        if(i == 0 || i == 5 - 1){
            cout << "*";
        } else {
            cout << " ";
        }
    } 
    cout << endl;
}

