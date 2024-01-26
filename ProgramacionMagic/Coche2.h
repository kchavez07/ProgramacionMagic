#pragma once
#include <iostream>
#include <string>

class Vehiculo {
protected:
    std::string modelo;
    int año;

public:
    Vehiculo(const std::string& _modelo, int _año) : modelo(_modelo), año(_año) {}

    void mostrarInformacion() const {
        std::cout << "Modelo: " << modelo << "\nAño: " << año << std::endl;
    }
};

class Coche : public Vehiculo {
private:
    int numeroPuertas;

public:
    Coche(const std::string& _modelo, int _año, int _numeroPuertas)
        : Vehiculo(_modelo, _año), numeroPuertas(_numeroPuertas) {}

    void mostrarInformacion() const {
        Vehiculo::mostrarInformacion();  // Llamada al método de la clase base
        std::cout << "Número de Puertas: " << numeroPuertas << std::endl;
    }
};

int main() {
    // Solicitar datos al usuario para el coche
    std::string modeloCoche;
    int añoCoche, puertasCoche;

    std::cout << "Ingrese el modelo del coche: ";
    std::cin >> modeloCoche;

    std::cout << "Ingrese el año del coche: ";
    std::cin >> añoCoche;

    std::cout << "Ingrese el número de puertas del coche: ";
    std::cin >> puertasCoche;

    // Crear objeto de la clase derivada (Coche)
    Coche miCoche(modeloCoche, añoCoche, puertasCoche);

    // Mostrar información del coche
    std::cout << "Información del Coche:\n";
    miCoche.mostrarInformacion();

    return 0;
}
