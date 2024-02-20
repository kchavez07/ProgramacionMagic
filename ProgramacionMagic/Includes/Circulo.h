#pragma once
#include <iostream>
#include <cmath>

class Circulo
{
private:
    double radio;

public:

    Circulo(double r) : radio(r) {}


    double obtenerRadio() const
    {
        return radio;
    }


    double calcularArea() const
    {
        return M_PI * radio * radio;
    }


    double calcularPerimetro() const
    {
        return 2 * M_PI * radio;
    }
};

int main()
{

    Circulo miCirculo(5.0);


    std::cout << "Radio del c�rculo: " << miCirculo.obtenerRadio() << std::endl;


    std::cout << "�rea del c�rculo: " << miCirculo.calcularArea() << std::endl;


    std::cout << "Per�metro del c�rculo: " << miCirculo.calcularPerimetro() << std::endl;

    return 0;
}
