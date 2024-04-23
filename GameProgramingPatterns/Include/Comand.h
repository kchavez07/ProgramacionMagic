#pragma once
#include "Prereriquisites.h"

// Interfaz Comando 
class Comando {
public:
    virtual void ejecutar() = 0;   // M�todo virtual puro para ejecutar el comando
    virtual void deshacer() = 0;   // M�todo virtual puro para deshacer el comando
};

// Clase Receptora: Luz
class Luz {
public:
    void encender() {
        cout << "Luz encendida." << endl;
    }

    void apagar() {
        cout << "Luz apagada." << endl;
    }
};

// Comando Concreto para encender la luz
class ComandoEncender : public Comando {
public:
    ComandoEncender(Luz& luz) : m_luz(luz) {}

    void ejecutar() override {
        m_luz.encender();   // Ejecutar el comando de encendido de la luz
    }

    void deshacer() override {
        m_luz.apagar();   // Deshacer el comando de encendido (apagar la luz)
    }

private:
    Luz& m_luz;   // Referencia a la luz sobre la cual se ejecuta el comando
};

// Comando Concreto para apagar la luz
class ComandoApagarLuz : public Comando {
public:
    ComandoApagarLuz(Luz& luz) : m_luz(luz) {}

    void ejecutar() override {
        m_luz.apagar();   // Ejecutar el comando de apagado de la luz
    }

    void deshacer() override {
        m_luz.encender();   // Deshacer el comando de apagado (encender la luz)
    }

private:
    Luz& m_luz;   // Referencia a la luz sobre la cual se ejecuta el comando
};

// Invocador: Control remoto que ejecuta comandos
class ControlRemoto {
public:
    // M�todo para presionar un bot�n y ejecutar un comando
    void presionarBoton(Comando* comando) {
        comando->ejecutar();   // Ejecutar el comando presionado
        m_historial.push_back(comando);   // Agregar el comando al historial de ejecuci�n
    }

    // M�todo para deshacer el �ltimo comando ejecutado
    void deshacer() {
        if (!m_historial.empty()) {
            m_historial.back()->deshacer();   // Deshacer el �ltimo comando en el historial
            m_historial.pop_back();   // Eliminar el comando del historial
        }
    }

private:
    vector<Comando*> m_historial;   // Historial de comandos ejecutados
};