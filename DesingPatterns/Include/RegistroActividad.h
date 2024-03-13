#pragma once
#include "Preriquisites.h"

class RegistroActividad {
private:
    static RegistroActividad* instancia;
    vector<string> log;

    RegistroActividad() : log() {}

public:
    // Método estático para obtener la instancia (Singleton)
    static RegistroActividad* getInstancia2() {
        if (instancia != nullptr) {
            return instancia;
        }
        else {
            instancia = new RegistroActividad();
            return instancia;
        }
    }

    // Agregar un log al registro
    void setLog(string nuevoLog) {
        log.push_back(nuevoLog);
    }

    // Obtener los logs registrados
    vector<string> getLog() {
        return log;
    }
};

// Inicializar el atributo estático
RegistroActividad* RegistroActividad::instancia = nullptr;