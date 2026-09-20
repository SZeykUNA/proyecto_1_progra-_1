#include "Reserva.h"

// Constructor por defecto
Reserva::Reserva() {
	this->numeroReserva = 0;
	this->cliente = nullptr;
	this->cancha = nullptr;
	this->franjaInicial = 0;
	this->cantidadFranjas = 0;
	this->montoTotal = 0.0f;
	this->activa = false;
}

// Constructor con parametros
Reserva::Reserva(int numeroReserva, Cliente* cliente, Cancha* cancha, int franjaInicial, int cantidadFranjas) {
	this->numeroReserva = numeroReserva;
	this->cliente = cliente;
	this->cancha = cancha;
	this->franjaInicial = franjaInicial;
	this->cantidadFranjas = cantidadFranjas;
	this->activa = true; // Toda reserva nueva nace activa
	calcularMonto();
}

Reserva::~Reserva() {
	// No hacemos delete a cliente ni cancha porque son punteros referenciados
}

// Getters
int Reserva::getNumeroReserva() const { return this->numeroReserva; }
Cliente* Reserva::getCliente() const { return this->cliente; }
Cancha* Reserva::getCancha() const { return this->cancha; }
int Reserva::getFranjaInicial() const { return this->franjaInicial; }
int Reserva::getCantidadFranjas() const { return this->cantidadFranjas; }
float Reserva::getMontoTotal() const { return this->montoTotal; }
bool Reserva::isActiva() const { return this->activa; }

void Reserva::setActiva(bool activa) { this->activa = activa; }

// Calcula el precio multiplicando horas por el precio de la cancha
void Reserva::calcularMonto() {
	if (cancha != nullptr) {
		this->montoTotal = cantidadFranjas * cancha->getPrecioHora();
	}
	else {
		this->montoTotal = 0.0f;
	}
}

// Imprime los detalles de la reserva
void Reserva::mostrarReserva() const {
	cout << "----------------------------------------" << endl;
	cout << "Num Reserva:    #" << numeroReserva << endl;
	cout << "Estado:         " << (activa ? "ACTIVA" : "CANCELADA") << endl;
	if (cliente != nullptr) {
		cout << "Cliente:        " << cliente->getNombreCompleto() << " (ID: " << cliente->getId() << ")" << endl;
	}
	if (cancha != nullptr) {
		cout << "Cancha:         " << cancha->getCodigo() << " (" << cancha->getDeporte() << ")" << endl;
	}
	cout << "Franja inicio:  [" << franjaInicial << "]" << endl;
	cout << "Horas:          " << cantidadFranjas << endl;
	cout << "Monto Total:    " << montoTotal << endl;
	cout << "----------------------------------------" << endl;
}