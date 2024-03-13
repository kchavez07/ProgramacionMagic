#pragma once
#include "Preriquisites.h"

// Clase base del prototipo
class DocumentoPrototype {
public:
    // M�todo para clonar un documento
    virtual DocumentoPrototype* clonar() = 0;

    // M�todo para configurar el contenido del documento
    virtual void configurar(const string& contenido) = 0;

    // M�todo para mostrar el contenido del documento
    virtual void mostrar() = 0;
};

// Clase concreta para documentos de texto
class DocumentoTexto : public DocumentoPrototype {
private:
    string contenido;

public:
    // M�todo para clonar un documento de texto
    DocumentoPrototype* clonar() override {
        DocumentoTexto* copia = new DocumentoTexto();
        copia->configurar(contenido);
        return copia;
    }

    // M�todo para configurar el contenido del documento de texto
    void configurar(const string& nuevoContenido) override {
        contenido = nuevoContenido;
    }

    // M�todo para mostrar el documento de texto
    void mostrar() override {
        cout << "Documento de texto: " << contenido << endl;
    }
};

// Clase concreta para documentos de imagen
class DocumentoImagen : public DocumentoPrototype {
private:
    string contenido;

public:
    // M�todo para clonar un documento de imagen
    DocumentoPrototype* clonar() override {
        DocumentoImagen* copia = new DocumentoImagen();
        copia->configurar(contenido);
        return copia;
    }

    // M�todo para configurar el contenido del documento de imagen
    void configurar(const string& nuevoContenido) override {
        contenido = nuevoContenido;
    }

    // M�todo para mostrar el documento de imagen
    void mostrar() override {
        cout << "Documento de imagen: " << contenido << endl;
    }
};
