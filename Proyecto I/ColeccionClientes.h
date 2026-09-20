#pragma once
#include "Cliente.h"
#include <iostream>

using namespace std;

class ColeccionClientes {
private:
	static const int MAX_CLIENTES = 100; // Constante para la capacidad máxima (100)
	Cliente** vectorClientes;             // Arreglo dinámico de punteros a Cliente
	int cantidadActual;                   // Cantidad de clientes registrados actualmente

public:
	// Constructor y Destructor
	ColeccionClientes();
	~ColeccionClientes();

	// Métodos principales
	bool agregarCliente(Cliente* nuevoCliente);
	Cliente* buscarClientePorId(string id) const;
	void mostrarListadoClientes() const;

	// Getters
	int getCantidadActual() const;
	int getMaxClientes() const;
};