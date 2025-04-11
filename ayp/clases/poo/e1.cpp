#include <iostream>
using namespace std;

class Motor {
    public:
        int cilindros;
        int año;
        int aceite = 3;
    
    Motor(int a, int b) {
        cilindros = a;
        año = b;
    }
};

class Vehiculo {
    public:
        Motor motor;
        string placa;

        Vehiculo() : motor(0, 0) {}; // Constructor por defecto
};

class Carro : private Vehiculo {
    public:

    Carro(string placa, int cilindros, int año) {
        this->placa = placa;
        this->motor.cilindros = cilindros;
        motor.año = año;
    }

    Carro(string placa, Motor motor) {
        this->placa = placa;
        this->motor.cilindros = motor.cilindros;
        this->motor.año = motor.año;
    }

    // Esto lo agregue yo
    void setCilindros(int cilindros) {
        motor.cilindros = cilindros;
    }

    int getCilindros() {
        return motor.cilindros;
    }
};

int main() {
    Carro a("ADN02F", 225, 2020);
    Carro b("CHARI69", Motor(16, 2025));

    /*
        Por ejemplo, si se quisiera acceder a los atributos de motor y placa de los objetos a y b, no se podría hacer de la siguiente manera:
            a.motor;
            b.placa;
    */
    
    // OJO con VEHICULO: Todas las clases cuando tienen otro objeto como atributo, se les debe de hacer un constructor por defecto para poder acceder a los atributos de ese objeto.
    Vehiculo c;
    c.motor.cilindros = 10;
    cin >> c.motor.cilindros;
    
    cout << "Cilindros de a: " << a.getCilindros() << endl;
    cout << "Ingrese los cilindros de a: ";
    int a1;
    cin >> a1;
    a.setCilindros(a1);

    cout << "Cilindros de a: " << a.getCilindros() << endl;

    return 0;
}
