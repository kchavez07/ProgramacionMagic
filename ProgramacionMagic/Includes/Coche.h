#pragma once
#include "Prerequisites.h"
using namespace std;

class Coche {
private:
    string m_marca;
    string m_modelo;
    int m_year;

public:
    Coche(string _marca, string _modelo, int _year) : m_marca(_marca), m_modelo(_modelo), m_year(_year) {}

    void obtenerInformacion() {
        cout << "Marca: " << m_marca << " | Modelo: "
            << m_modelo << " | Año: " << m_year << endl;
    }

    void setMarca(string marca) {
        m_marca = marca;
    }

    void setModelo(string modelo) {
        m_modelo = modelo;
    }

    void setYear(int year) {
        m_year = year;
    }

    string getMarca() {
        return m_marca;
    }

    string getModelo() {
        return m_modelo;
    }

    int getYear() {
        return m_year;
    }
};
