#pragma once
#include "Prereriquisites.h"

// Clase base Componente
class Componente {
public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void destroy() = 0;
    virtual ~Componente() {}
};

// Clase RenderComponente
class RenderComponente : public Componente {
public:
    void init() override {
        cout << "Se inicializa el componente de renderizado" << endl;
    }

    void update() override {
        cout << "Se actualiza la posición de la malla" << endl;
    }

    void render() override {
        cout << "Se renderiza el objeto" << endl;
    }

    void destroy() override {
        cout << "Se destruye el componente de renderizado" << endl;
    }
};

// Clase PhysicsComponente
class PhysicsComponente : public Componente {
public:
    void init() override {
        cout << "Se inicializa el componente de física" << endl;
    }

    void update() override {
        cout << "Se actualiza el proceso matemático" << endl;
    }

    void render() override {
        cout << "Se actualiza la física del objeto" << endl;
    }

    void destroy() override {
        cout << "Se destruye el componente de física" << endl;
    }
};

// Clase IAComponente
class IAComponente : public Componente {
public:
    void init() override {
        cout << "Se inicializa el componente de IA" << endl;
    }

    void update() override {
        cout << "Se actualiza el proceso de IA" << endl;
    }

    void render() override {
        cout << "Se actualiza la IA del objeto" << endl;
    }

    void destroy() override {
        cout << "Se destruye el componente de IA" << endl;
    }
};

// Clase Entidad
class Entidad {
public:
    void agregarComponente(Componente* componente) {
        componentes.push_back(componente);
    }

    void initComponentes() {
        for (auto componente : componentes) {
            componente->init();
        }
    }

    void updateComponentes() {
        for (auto componente : componentes) {
            componente->update();
        }
    }

    void renderComponentes() {
        for (auto componente : componentes) {
            componente->render();
        }
    }

    void destroyComponentes() {
        for (auto componente : componentes) {
            componente->destroy();
            delete componente; // Liberar memoria de cada componente
        }
        componentes.clear(); // Limpiar el vector de componentes
    }

private:
    vector<Componente*> componentes;
};