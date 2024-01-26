#pragma once
#include <iostream>
#include <string>

class Vehiculo {
protected:
    std::string modelo;
    int a�o;

public:
    Vehiculo(const std::string& _modelo, int _a�o) : modelo(_modelo), a�o(_a�o) {}

    void mostrarInformacion() const {
        std::cout << "Modelo: " << modelo << "\nA�o: " << a�o << std::endl;
    }
};

class Coche : public Vehiculo {
private:
    int numeroPuertas;

public:
    Coche(const std::string& _modelo, int _a�o, int _numeroPuertas)
        : Vehiculo(_modelo, _a�o), numeroPuertas(_numeroPuertas) {}

    void mostrarInformacion() const {
        Vehiculo::mostrarInformacion();  // Llamada al m�todo de la clase base
        std::cout << "N�mero de Puertas: " << numeroPuertas << std::endl;
    }
};

int main() {
    // Solicitar datos al usuario para el coche
    std::string modeloCoche;
    int a�oCoche, puertasCoche;

    std::cout << "Ingrese el modelo del coche: ";
    std::cin >> modeloCoche;

    std::cout << "Ingrese el a�o del coche: ";
    std::cin >> a�oCoche;

    std::cout << "Ingrese el n�mero de puertas del coche: ";
    std::cin >> puertasCoche;

    // Crear objeto de la clase derivada (Coche)
    Coche miCoche(modeloCoche, a�oCoche, puertasCoche);

    // Mostrar informaci�n del coche
    std::cout << "Informaci�n del Coche:\n";
    miCoche.mostrarInformacion();

    return 0;
}
