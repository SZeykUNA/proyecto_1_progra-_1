#pragma once
#include "Cliente.h"
#include "Cancha.h"
#include <iostream>
#include <string>

using namespace std;

class RegistroEspera {
private:
	int numeroConsecutivo;
	Cliente* cliente;
	Cancha* cancha;
	int franjaHoraria;
	string estado; // "esperando", "asignado", "cancelado"

public:
	RegistroEspera();
	RegistroEspera(int numeroConsecutivo, Cliente* cliente, Cancha* cancha, int franjaHoraria);
	~RegistroEspera();

	// Getters y Setters
	int getNumeroConsecutivo() const;
	Cliente* getCliente() const;
	Cancha* getCancha() const;
	int getFranjaHoraria() const;
	string getEstado() const;

	void setEstado(string estado);

	void mostrarRegistro() const;
};