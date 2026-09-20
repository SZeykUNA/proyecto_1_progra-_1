#pragma once
#include "ColeccionCanchas.h"
#include "ColeccionClientes.h"
#include "ColeccionReservas.h"
#include <iostream>

using namespace std;

class Reportes {
public:
	Reportes();
	~Reportes();

	static void canchaConMasReservas(const ColeccionCanchas& coleccionCanchas, const ColeccionReservas& coleccionReservas);
	static void clienteConMasReservas(const ColeccionClientes& coleccionClientes, const ColeccionReservas& coleccionReservas);
	static void ingresoTotalReservas(const ColeccionReservas& coleccionReservas);
	static void porcentajeOcupacionPorCancha(const ColeccionCanchas& coleccionCanchas);
	static void horasConMayorYMenorOcupacion(const ColeccionReservas& coleccionReservas);
};