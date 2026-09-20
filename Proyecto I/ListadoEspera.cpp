#include "ListadoEspera.h"

ListadoEspera::ListadoEspera() {
	this->cantidadActual = 0;
	this->siguienteConsecutivo = 1;

	this->vectorEspera = new RegistroEspera * [MAX_ESPERA];
	for (int i = 0; i < MAX_ESPERA; i++) {
		this->vectorEspera[i] = nullptr;
	}
}

ListadoEspera::~ListadoEspera() {
	for (int i = 0; i < cantidadActual; i++) {
		if (vectorEspera[i] != nullptr) {
			delete vectorEspera[i];
		}
	}
	delete[] vectorEspera;
}

// Registrar un cliente en lista de espera validando todas las reglas del PDF
bool ListadoEspera::registrarEnEspera(Cliente* cliente, Cancha* cancha, int franjaHoraria) {
	if (cliente == nullptr || cancha == nullptr) {
		cout << "Error: Cliente o cancha invalida." << endl;
		return false;
	}

	if (cantidadActual >= MAX_ESPERA) {
		cout << "Error: El listado de espera esta lleno (Maximo 10)." << endl;
		return false;
	}

	// Regla: Solo franjas en 'O' (Ocupada) entran en espera. En 'M' no se permite.
	char estadoFranja = cancha->getEstadoFranja(franjaHoraria);
	if (estadoFranja != 'O') {
		if (estadoFranja == 'M') {
			cout << "Error: La franja esta en mantenimiento, no genera lista de espera." << endl;
		}
		else {
			cout << "Error: La franja esta libre, puede reservarla directamente." << endl;
		}
		return false;
	}

	// Regla: Un mismo cliente no puede estar 2 veces en espera para la misma cancha y franja
	for (int i = 0; i < cantidadActual; i++) {
		if (vectorEspera[i]->getEstado() == "esperando" &&
			vectorEspera[i]->getCliente()->getId() == cliente->getId() &&
			vectorEspera[i]->getCancha()->getCodigo() == cancha->getCodigo() &&
			vectorEspera[i]->getFranjaHoraria() == franjaHoraria) {
			cout << "Error: Este cliente ya esta registrado en espera para esta cancha y franja." << endl;
			return false;
		}
	}

	vectorEspera[cantidadActual] = new RegistroEspera(siguienteConsecutivo, cliente, cancha, franjaHoraria);
	cantidadActual++;
	siguienteConsecutivo++;

	cout << "¡Cliente agregado a la lista de espera con exito!" << endl;
	return true;
}

// Cambiar estado ("esperando", "asignado", "cancelado")
bool ListadoEspera::cambiarEstadoEspera(int consecutivo, string nuevoEstado) {
	for (int i = 0; i < cantidadActual; i++) {
		if (vectorEspera[i]->getNumeroConsecutivo() == consecutivo) {
			vectorEspera[i]->setEstado(nuevoEstado);
			cout << "Estado actualizado a '" << nuevoEstado << "'." << endl;
			return true;
		}
	}
	cout << "Error: No se encontro el registro de espera #" << consecutivo << "." << endl;
	return false;
}

// Aviso de personas en espera al cancelar una reserva
void ListadoEspera::verificarEsperasPorCanchaYFranja(string codigoCancha, int franjaHoraria) const {
	bool hayEsperando = false;
	cout << "\n=== VERIFICANDO LISTADO DE ESPERA ===" << endl;
	for (int i = 0; i < cantidadActual; i++) {
		if (vectorEspera[i]->getEstado() == "esperando" &&
			vectorEspera[i]->getCancha()->getCodigo() == codigoCancha &&
			vectorEspera[i]->getFranjaHoraria() == franjaHoraria) {

			cout << "AVISO: El cliente " << vectorEspera[i]->getCliente()->getNombreCompleto()
				<< " (ID: " << vectorEspera[i]->getCliente()->getId() << ")"
				<< " esta en ESPERA para esta franja (Registro #"
				<< vectorEspera[i]->getNumeroConsecutivo() << ")." << endl;
			hayEsperando = true;
		}
	}
	if (!hayEsperando) {
		cout << "No hay personas en espera para esta cancha y franja." << endl;
	}
}

void ListadoEspera::mostrarListadoEspera() const {
	if (cantidadActual == 0) {
		cout << "No hay clientes en el listado de espera." << endl;
		return;
	}
	cout << "\n=== LISTADO DE ESPERA ===" << endl;
	for (int i = 0; i < cantidadActual; i++) {
		vectorEspera[i]->mostrarRegistro();
	}
}

int ListadoEspera::getCantidadActual() const { return this->cantidadActual; }