#pragma once
#include "ColeccionClientes.h"
#include "ColeccionCanchas.h"
#include "ColeccionReservas.h"
#include "ListadoEspera.h"
#include "Reportes.h"
#include <iostream>
#include <string>

using namespace std;

class Interfaz {
private:
	ColeccionClientes coleccionClientes;
	ColeccionCanchas coleccionCanchas;
	ColeccionReservas coleccionReservas;
	ListadoEspera listadoEspera;

	// Métodos de validación
	int leerEntero(string mensaje);
	float leerFloat(string mensaje);
	string leerTexto(string mensaje);

	// Submenús
	void menuCanchas();
	void menuClientes();
	void menuReservas();
	void menuListadoEspera();
	void menuReportes();

public:
	Interfaz();
	~Interfaz();

	void ejecutar();
};