#pragma once
#include "Preriquisites.h"

// Clase que representa una interfaz vieja
class InterfazVieja {
public:
    // Método de la interfaz vieja
    virtual void MetodoViejo() {
        cout << "Metodo Viejo llamado." << endl;
    }
};

// Clase que representa una interfaz nueva (objetivo)
class InterfazNueva {
public:
    // Método de la interfaz nueva
    virtual void MetodoNuevo() {
        cout << "Metodo Nuevo llamado." << endl;
    }
};

// Adaptador que conecta la interfaz vieja con la nueva
class Adapter : public InterfazNueva {
public:
    // Constructor que toma una interfaz vieja como parámetro
    Adapter(InterfazVieja* vieja) : m_interfazVieja(vieja) {}

    // Implementación del método de la interfaz nueva
    void MetodoNuevo() override {
        cout << "Adaptador llamado al metodo nuevo" << endl;
        m_interfazVieja->MetodoViejo();
    }

private:
    InterfazVieja* m_interfazVieja;
};

