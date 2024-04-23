#pragma once
#include "Prereriquisites.h"

// Clase base Operación
class Operacion {
public:
    virtual void ejecutar(int& resultado) = 0;
    virtual void deshacer(int& resultado) = 0;
};

// Clases derivadas: Suma, Resta, Multiplicacion y Division
class Suma : public Operacion {
private:
    int valor;
public:
    Suma(int val) : valor(val) {}

    void ejecutar(int& resultado) override {
        resultado += valor;
    }

    void deshacer(int& resultado) override {
        resultado -= valor;
    }
};

class Resta : public Operacion {
private:
    int valor;
public:
    Resta(int val) : valor(val) {}

    void ejecutar(int& resultado) override {
        resultado -= valor;
    }

    void deshacer(int& resultado) override {
        resultado += valor;
    }
};

class Multiplicacion : public Operacion {
private:
    int valor;
public:
    Multiplicacion(int val) : valor(val) {}

    void ejecutar(int& resultado) override {
        resultado *= valor;
    }

    void deshacer(int& resultado) override {
        resultado /= valor;
    }
};

class Division : public Operacion {
private:
    int valor;
public:
    Division(int val) : valor(val) {}

    void ejecutar(int& resultado) override {
        resultado /= valor;
    }

    void deshacer(int& resultado) override {
        resultado *= valor;
    }
};

// Clase Calculadora
class Calculadora {
private:
    std::vector<Operacion*> operaciones;
    int resultado;
public:
    Calculadora() : resultado(0) {}

    void realizarOperacion(Operacion* operacion) {
        operacion->ejecutar(resultado);
        operaciones.push_back(operacion);
    }

    void deshacer() {
        if (!operaciones.empty()) {
            Operacion* operacion = operaciones.back();
            operacion->deshacer(resultado);
            operaciones.pop_back();
            delete operacion;
        }
    }

    void rehacer() {
        if (!operaciones.empty()) {
            Operacion* operacion = operaciones.back();
            operacion->ejecutar(resultado);
            operaciones.push_back(operacion);
        }
    }

    int getResultado() const {
        return resultado;
    }
};
