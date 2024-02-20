#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Rectangulo {
private:
    double ancho;
    double altura;

public:
    Rectangulo(double ancho, double altura) : ancho(ancho), altura(altura) {}

    double calcularArea() const {
        return ancho * altura;
    }
};

class Calculadora {
public:
    static double calcularRaizCuadrada(double numero) {
        return sqrt(numero);
    }
};

int main() {
    double ancho, altura;

    cout << "Ingrese el ancho del rectángulo: ";
    cin >> ancho;
    cout << "Ingrese la altura del rectángulo: ";
    cin >> altura;

    Rectangulo miRectangulo(ancho, altura);

    double area = miRectangulo.calcularArea();
    cout << "Área del rectángulo: " << area << endl;

    double numero;
    cout << "Ingrese un número para calcular la raíz cuadrada: ";
    cin >> numero;

    double raizCuadrada = Calculadora::calcularRaizCuadrada(numero);
    cout << "Raíz cuadrada de " << numero << ": " << raizCuadrada << endl;

    return 0;
}
