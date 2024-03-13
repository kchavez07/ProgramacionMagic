#pragma once
#include "Preriquisites.h"

// Componente Base
class CComponent {
public:
    // Operaci�n virtual a ser implementada por las hojas y nodos compuestos
    virtual void operacion() = 0;
};

// Hoja (Leaf)
class Leaf : public CComponent {
public:
    void operacion() override {
        cout << "Operacion en la hoja." << endl;
    }
};

// Nodo Compuesto
class Compuesto : public CComponent {
public:
    // Implementaci�n de la operaci�n que realiza la operaci�n en todas las hojas
    void operacion() override {
        cout << "Operacion en el compuesto. Contiene " << Leafs.size() << " hojas." << endl;
        for (CComponent* Leaf : Leafs) {
            Leaf->operacion();
        }
    }

    // M�todo para agregar una hoja al nodo compuesto
    void agregarLeaf(CComponent* _Leaf) {
        Leafs.push_back(_Leaf);
    }

private:
    vector<CComponent*> Leafs;
};