#include <iostream>
#include <math.h>

// Imprime un mensaje en la consola
void print(std::string mensaje) {
    std::cout << mensaje << std::endl;
}

void print(float mensaje) {
    std::cout << mensaje << std::endl;
}

float m_resolvente_de(float b, float a, float c) {
    float potencia = pow(b,2);
    float opRaiz = potencia-(4*(a*c));
    if (opRaiz < 0) {
        opRaiz = opRaiz * -1;
    }
    float raiz = sqrt(opRaiz);
    float x1 = -b + raiz;
    float x2 = 2 * a;
    float x = x1 / x2;
    std::cout << x << std::endl;
    return x;
}

int main () {
    print("Hello World");
    std::cout << m_resolvente_de(3245, 223, 1123) << std::endl;

    std::cin.get();
    return 0;
}