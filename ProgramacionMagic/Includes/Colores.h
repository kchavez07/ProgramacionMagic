#pragma once
#include <iostream>
#include <string>

// Clase base 'Figura'
class Figura {
protected:
    double m_area;

public:
    Figura(double area) : m_area(area) {}

    void mostrarInformacion() {
        std::cout << "Área de la figura: " << m_area << std::endl;
    }
};

// Clase base 'Color'
class Color {
protected:
    std::string m_color;

public:
    Color(const std::string& color) : m_color(color) {}

    void mostrarColor() {
        std::cout << "Color de la figura: " << m_color << std::endl;
    }
};

// Clase derivada 'FiguraColoreada' hereda de 'Figura' y 'Color'
class FiguraColoreada : public Figura, public Color {
public:
    FiguraColoreada(double area, const std::string& color)
        : Figura(area), Color(color) {}

    void realizarAccion() {
        std::cout << "Realizando una acción con la figura coloreada." << std::endl;
    }
};

int main() {
    // Crear un objeto de 'FiguraColoreada'
    FiguraColoreada figuraColoreada(25.0, "Rojo");

    // Utilizar métodos heredados
    figuraColoreada.mostrarInformacion();
    figuraColoreada.mostrarColor();
    figuraColoreada.realizarAccion();

    return 0;
}
