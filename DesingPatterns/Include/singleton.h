#pragma once
#include "Preriquisites.h"

// Clase Singleton
class Singleton {
private:
    int value; // Valor almacenado en la instancia

    // Constructor privado para evitar instanciación directa
    Singleton() : value(0) {}

public:
    // Destructor
    ~Singleton();

    // Método estático para obtener la instancia
    static Singleton* getInstance() {
        if (instance != nullptr) {
            return instance;
        }
        else {
            instance = new Singleton;
            return instance;
        }
    }

    // Establece el valor
    void setValue(int _value) {
        value = _value;
    }

    // Obtiene el valor
    int getValue() {
        return value;
    }

private:
    static Singleton* instance; // Puntero a la única instancia
};
