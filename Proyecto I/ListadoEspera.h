#pragma once
#include "RegistroEspera.h"
#include <iostream>

using namespace std;

class ListadoEspera {
private:
	static const int MAX_ESPERA = 10; 
	RegistroEspera** vectorEspera;
	int cantidadActual;
	int siguienteConsecutivo;

public:
	ListadoEspera();
	~ListadoEspera();

	bool registrarEnEspera(Cliente* cliente, Cancha* cancha, int franjaHoraria);
	bool cambiarEstadoEspera(int consecutivo, string nuevoEstado);
	void verificarEsperasPorCanchaYFranja(string codigoCancha, int franjaHoraria) const;
	void mostrarListadoEspera() const;

	int getCantidadActual() const;
};
