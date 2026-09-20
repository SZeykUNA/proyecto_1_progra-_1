#include "RegistroEspera.h"

RegistroEspera::RegistroEspera() {
	this->numeroConsecutivo = 0;
	this->cliente = nullptr;
	this->cancha = nullptr;
	this->franjaHoraria = 0;
	this->estado = "esperando";
}

RegistroEspera::RegistroEspera(int numeroConsecutivo, Cliente* cliente, Cancha* cancha, int franjaHoraria) {
	this->numeroConsecutivo = numeroConsecutivo;
	this->cliente = cliente;
	this->cancha = cancha;
	this->franjaHoraria = franjaHoraria;
	this->estado = "esperando";
}

RegistroEspera::~RegistroEspera() {}

int RegistroEspera::getNumeroConsecutivo() const { return this->numeroConsecutivo; }
Cliente* RegistroEspera::getCliente() const { return this->cliente; }
Cancha* RegistroEspera::getCancha() const { return this->cancha; }
int RegistroEspera::getFranjaHoraria() const { return this->franjaHoraria; }
string RegistroEspera::getEstado() const { return this->estado; }

void RegistroEspera::setEstado(string estado) { this->estado = estado; }

void RegistroEspera::mostrarRegistro() const {
	cout << "----------------------------------------" << endl;
	cout << "Num Espera:     #" << numeroConsecutivo << endl;
	cout << "Estado:         " << estado << endl;
	if (cliente != nullptr) {
		cout << "Cliente:        " << cliente->getNombreCompleto() << " (ID: " << cliente->getId() << ")" << endl;
	}
	if (cancha != nullptr) {
		cout << "Cancha:         " << cancha->getCodigo() << endl;
	}
	cout << "Franja:         [" << franjaHoraria << "]" << endl;
	cout << "----------------------------------------" << endl;
}