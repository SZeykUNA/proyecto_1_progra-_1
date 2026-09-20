#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
    string nombreCompleto;
    string id;
    string telefono;

public:
    // Constructores
    Cliente();
    Cliente(string nombreCompleto, string id, string telefono);

    // Destructor
    ~Cliente();

    // Getters
    string getNombreCompleto() const;
    string getId() const;
    string getTelefono() const;

    // Setters
    void setNombreCompleto(string nombreCompleto);
    void setId(string id);
    void setTelefono(string telefono);

    // Método para imprimir
    void mostrarCliente() const;
};
