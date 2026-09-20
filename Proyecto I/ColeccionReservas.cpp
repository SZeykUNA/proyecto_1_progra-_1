#include "ColeccionReservas.h"

ColeccionReservas::ColeccionReservas() {
	this->cantidadActual = 0;
	this->siguienteConsecutivo = 1; // Arranca en la reserva #1

	this->vectorReservas = new Reserva * [MAX_RESERVAS];
	for (int i = 0; i < MAX_RESERVAS; i++) {
		this->vectorReservas[i] = nullptr;
	}
}

ColeccionReservas::~ColeccionReservas() {
	for (int i = 0; i < cantidadActual; i++) {
		if (vectorReservas[i] != nullptr) {
			delete vectorReservas[i];
		}
	}
	delete[] vectorReservas;
}

// Registrar reserva verificando disponibilidad
bool ColeccionReservas::registrarReserva(Cliente* cliente, Cancha* cancha, int franjaInicio, int cantidadFranjas) {
	if (cliente == nullptr || cancha == nullptr) {
		cout << "Error: Cliente o cancha invalida." << endl;
		return false;
	}

	if (cantidadActual >= MAX_RESERVAS) {
		cout << "Error: Se alcanzo el limite maximo de reservas (120)." << endl;
		return false;
	}

	// Validar rango de franjas
	if (franjaInicio < 0 || (franjaInicio + cantidadFranjas) > Cancha::getCantidadFranjas() || cantidadFranjas <= 0) {
		cout << "Error: Las franjas solicitadas estan fuera de rango." << endl;
		return false;
	}

	// Validar que TODAS las franjas solicitadas esten en 'L'
	for (int i = franjaInicio; i < franjaInicio + cantidadFranjas; i++) {
		if (cancha->getEstadoFranja(i) != 'L') {
			cout << "Error: La franja [" << i << "] no esta disponible." << endl;
			return false;
		}
	}

	// Cambiar las franjas de 'L' a 'O'
	for (int i = franjaInicio; i < franjaInicio + cantidadFranjas; i++) {
		cancha->setEstadoFranja(i, 'O');
	}

	// Crear la reserva y guardarla
	Reserva* nuevaReserva = new Reserva(siguienteConsecutivo, cliente, cancha, franjaInicio, cantidadFranjas);
	vectorReservas[cantidadActual] = nuevaReserva;
	cantidadActual++;
	siguienteConsecutivo++;

	cout << "Reserva #" << nuevaReserva->getNumeroReserva() << " registrada con exito!" << endl;
	return true;
}

// Buscar reserva por numero consecutivo
Reserva* ColeccionReservas::buscarReservaPorNumero(int numeroReserva) const {
	for (int i = 0; i < cantidadActual; i++) {
		if (vectorReservas[i]->getNumeroReserva() == numeroReserva) {
			return vectorReservas[i];
		}
	}
	return nullptr;
}

// Cancelar reserva: Cambia estado a inactiva y libera franjas ('O' a 'L')
bool ColeccionReservas::cancelarReserva(int numeroReserva) {
	Reserva* res = buscarReservaPorNumero(numeroReserva);
	if (res == nullptr) {
		cout << "Error: No existe una reserva con ese numero." << endl;
		return false;
	}

	if (!res->isActiva()) {
		cout << "Error: La reserva ya se encuentra cancelada." << endl;
		return false;
	}

	// Cambiar estado a inactiva
	res->setActiva(false);

	// Liberar las franjas de la cancha ('O' -> 'L')
	Cancha* cancha = res->getCancha();
	int inicio = res->getFranjaInicial();
	int cant = res->getCantidadFranjas();

	for (int i = inicio; i < inicio + cant; i++) {
		cancha->setEstadoFranja(i, 'L');
	}

	cout << "Reserva #" << numeroReserva << " cancelada exitosamente y franjas liberadas." << endl;
	return true;
}

void ColeccionReservas::mostrarTodasLasReservas() const {
	if (cantidadActual == 0) {
		cout << "No hay reservas en el sistema." << endl;
		return;
	}
	for (int i = 0; i < cantidadActual; i++) {
		vectorReservas[i]->mostrarReserva();
	}
}

void ColeccionReservas::mostrarReservasPorCliente(string idCliente) const {
	bool encontro = false;
	for (int i = 0; i < cantidadActual; i++) {
		if (vectorReservas[i]->getCliente()->getId() == idCliente) {
			vectorReservas[i]->mostrarReserva();
			encontro = true;
		}
	}
	if (!encontro) {
		cout << "No se encontraron reservas para el cliente especificado." << endl;
	}
}

void ColeccionReservas::mostrarReservasPorCancha(string codigoCancha) const {
	bool encontro = false;
	for (int i = 0; i < cantidadActual; i++) {
		if (vectorReservas[i]->getCancha()->getCodigo() == codigoCancha) {
			vectorReservas[i]->mostrarReserva();
			encontro = true;
		}
	}
	if (!encontro) {
		cout << "No se encontraron reservas para esta cancha." << endl;
	}
}

int ColeccionReservas::getCantidadActual() const { return this->cantidadActual; }

Reserva* ColeccionReservas::getReservaEnPosicion(int pos) const {
	if (pos >= 0 && pos < cantidadActual) {
		return vectorReservas[pos];
	}
	return nullptr;
}