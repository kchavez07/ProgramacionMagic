#pragma once
#include "Preriquisites.h"

// Interfaz del sujeto
class Sujeto {
public:
    // M�todo virtual puro para realizar una operaci�n.
    virtual void operacion() = 0;
};

// Implementaci�n del sujeto real
class SujetoReal : public Sujeto {
public:
    // Implementaci�n concreta del m�todo de operaci�n.
    void operacion() override {
        cout << "Operaci�n en el sujeto real." << endl;
    }
};

// Proxy
class Proxy : public Sujeto {
public:
    // Constructor del proxy
    Proxy() : m_sujetoReal(nullptr) {}

    // Implementaci�n del m�todo de operaci�n del proxy
    void operacion() override {
        // Se crea el sujeto real solo si no existe
        if (m_sujetoReal == nullptr) {
            m_sujetoReal = new SujetoReal();
        }
        cout << "Operaci�n en el proxy. Redirigiendo a sujeto real." << endl;
        // Se llama al m�todo de operaci�n del sujeto real.
        m_sujetoReal->operacion();
    }

private:
    SujetoReal* m_sujetoReal; // Almacena una instancia del sujeto real.
};
