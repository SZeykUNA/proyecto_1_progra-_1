#include "Cliente.h"

// Constructor por defecto
Cliente::Cliente() {
    this->nombreCompleto = "";
    this->id = "";
    this->telefono = "";
}

// Constructor con parámetros
Cliente::Cliente(string nombreCompleto, string id, string telefono) {
    this->nombreCompleto = nombreCompleto;
    this->id = id;
    this->telefono = telefono;
}

// Destructor
Cliente::~Cliente() {}

// Getters
string Cliente::getNombreCompleto() const {
    return this->nombreCompleto;
}

string Cliente::getId() const {
    return this->id;
}

string Cliente::getTelefono() const {
    return this->telefono;
}

// Setters
void Cliente::setNombreCompleto(string nombreCompleto) {
    this->nombreCompleto = nombreCompleto;
}

void Cliente::setId(string id) {
    this->id = id;
}

void Cliente::setTelefono(string telefono) {
    this->telefono = telefono;
}

// Mostrar los datos en consola
void Cliente::mostrarCliente() const {
    cout << "ID: " << id
        << " | Nombre: " << nombreCompleto
        << " | Telefono: " << telefono << endl;
}