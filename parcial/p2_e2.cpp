#include <iostream>
using namespace std;

int r = 3, s = 2, h = 1;

void print(int a, int b, int c) {
    cout << a << " " << b << " " << c << endl;
}

int f1(int &s, int h) {
    h++;
    print(r, s, h);
    return r + s;
}

int f2(int &h, int &s, int r) {
    r = 5;
    s += 5 % 10 + 1;
    print(r, s, h);
    return f1(h, s);
}

int main() {
    print(r, s, h);
    r = f2(r, s, h);
    print(r, s, h);
    s = f1(r, h);
    print(r, s, h);
    return 0;
}