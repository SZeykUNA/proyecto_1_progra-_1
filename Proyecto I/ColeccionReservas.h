#pragma once
#include "Reserva.h"
#include <iostream>

using namespace std;

class ColeccionReservas {
private:
	static const int MAX_RESERVAS = 120; // Limite de reservas
	Reserva** vectorReservas;             // Arreglo dinamico de punteros
	int cantidadActual;                  // Contador de reservas registradas
	int siguienteConsecutivo;            // Para autogenerar el ID de reserva

public:
	ColeccionReservas();
	~ColeccionReservas();

	// Metodos requeridos por el enunciado
	bool registrarReserva(Cliente* cliente, Cancha* cancha, int franjaInicio, int cantidadFranjas);
	bool cancelarReserva(int numeroReserva);
	Reserva* buscarReservaPorNumero(int numeroReserva) const;

	void mostrarTodasLasReservas() const;
	void mostrarReservasPorCliente(string idCliente) const;
	void mostrarReservasPorCancha(string codigoCancha) const;

	// Getters auxiliares para los reportes
	int getCantidadActual() const;
	Reserva* getReservaEnPosicion(int pos) const;
};