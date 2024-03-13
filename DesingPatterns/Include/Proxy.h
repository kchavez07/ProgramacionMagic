#pragma once
#include "Preriquisites.h"

// Interfaz del sujeto
class Sujeto {
public:
    // Método virtual puro para realizar una operación.
    virtual void operacion() = 0;
};

// Implementación del sujeto real
class SujetoReal : public Sujeto {
public:
    // Implementación concreta del método de operación.
    void operacion() override {
        cout << "Operación en el sujeto real." << endl;
    }
};

// Proxy
class Proxy : public Sujeto {
public:
    // Constructor del proxy
    Proxy() : m_sujetoReal(nullptr) {}

    // Implementación del método de operación del proxy
    void operacion() override {
        // Se crea el sujeto real solo si no existe
        if (m_sujetoReal == nullptr) {
            m_sujetoReal = new SujetoReal();
        }
        cout << "Operación en el proxy. Redirigiendo a sujeto real." << endl;
        // Se llama al método de operación del sujeto real.
        m_sujetoReal->operacion();
    }

private:
    SujetoReal* m_sujetoReal; // Almacena una instancia del sujeto real.
};
