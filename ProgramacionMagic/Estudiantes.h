#pragma once
#include <iostream>
#include <string>

class Estudiante {
private:
    std::string nombre;
    int edad;
    float calificacion;

public:
    Estudiante(const std::string& n, int e, float c) : nombre(n), edad(e), calificacion(c) {}

    void mostrarInformacion() const {
        std::cout << "Nombre: " << nombre << ", Edad: " << edad << ", Calificación: " << calificacion << std::endl;
    }
};

int main() {
    int numEstudiantes;

    std::cout << "Ingrese el número de estudiantes: ";
    std::cin >> numEstudiantes;

    Estudiante** estudiantes = new Estudiante * [numEstudiantes];

    for (int i = 0; i < numEstudiantes; ++i) {
        std::string nombre;
        int edad;
        float calificacion;

        std::cout << "Ingrese el nombre del estudiante: ";
        std::cin >> nombre;

        std::cout << "Ingrese la edad del estudiante: ";
        std::cin >> edad;

        std::cout << "Ingrese la calificación del estudiante: ";
        std::cin >> calificacion;

        estudiantes[i] = new Estudiante(nombre, edad, calificacion);
    }

    // Mostrar información 
    for (int i = 0; i < numEstudiantes; ++i) {
        estudiantes[i]->mostrarInformacion();
    }

    // Liberar memoria 

    for (int i = 0; i < numEstudiantes; ++i) {
        delete estudiantes[i];
    }
    delete[] estudiantes;

    return 0;
}