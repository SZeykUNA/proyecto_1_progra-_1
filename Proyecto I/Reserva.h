#pragma once
#include "Cliente.h"
#include "Cancha.h"
#include <iostream>

using namespace std;

class Reserva {
private:
	int numeroReserva;      // Consecutivo automatico
	Cliente* cliente;       // Puntero al cliente que reserva
	Cancha* cancha;         // Puntero a la cancha reservada
	int franjaInicial;      // Posicion inicial (0 a 11)
	int cantidadFranjas;    // Cuantas horas seguidas
	float montoTotal;       // Precio total calculado
	bool activa;            // true = activa, false = cancelada

public:
	// Constructores y Destructor
	Reserva();
	Reserva(int numeroReserva, Cliente* cliente, Cancha* cancha, int franjaInicial, int cantidadFranjas);
	~Reserva();

	// Getters y Setters
	int getNumeroReserva() const;
	Cliente* getCliente() const;
	Cancha* getCancha() const;
	int getFranjaInicial() const;
	int getCantidadFranjas() const;
	float getMontoTotal() const;
	bool isActiva() const;

	void setActiva(bool activa);

	// Metodos auxiliares
	void calcularMonto();
	void mostrarReserva() const;
};