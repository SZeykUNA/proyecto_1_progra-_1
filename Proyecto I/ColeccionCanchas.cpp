#include "ColeccionCanchas.h"

ColeccionCanchas::ColeccionCanchas() {
	this->cantidadActual = 0;
	this->vectorCanchas = new Cancha * [MAX_CANCHAS];
	for (int i = 0; i < MAX_CANCHAS; i++) {
		this->vectorCanchas[i] = nullptr;
	}
}

ColeccionCanchas::~ColeccionCanchas() {
	for (int i = 0; i < cantidadActual; i++) {
		if (vectorCanchas[i] != nullptr) {
			delete vectorCanchas[i];
		}
	}
	delete[] vectorCanchas;
}

bool ColeccionCanchas::agregarCancha(Cancha* nuevaCancha) {
	if (nuevaCancha == nullptr) return false;

	if (cantidadActual >= MAX_CANCHAS) {
		cout << "Error: Se alcanzo el limite maximo de canchas (10)." << endl;
		return false;
	}

	if (buscarCanchaPorCodigo(nuevaCancha->getCodigo()) != nullptr) {
		cout << "Error: Ya existe una cancha con ese codigo." << endl;
		return false;
	}

	vectorCanchas[cantidadActual] = nuevaCancha;
	cantidadActual++;
	cout << "Cancha registrada con exito" << endl;
	return true;
}

Cancha* ColeccionCanchas::buscarCanchaPorCodigo(string codigo) const {
	for (int i = 0; i < cantidadActual; i++) {
		if (vectorCanchas[i]->getCodigo() == codigo) {
			return vectorCanchas[i];
		}
	}
	return nullptr;
}

void ColeccionCanchas::mostrarTodasLasCanchas() const {
	if (cantidadActual == 0) {
		cout << "No hay canchas registradas en el sistema." << endl;
		return;
	}

	cout << "          LISTADO DE CANCHAS            " << endl;

	for (int i = 0; i < cantidadActual; i++) {
		cout << i + 1 << ". ";
		vectorCanchas[i]->mostrarInformacion();
	}
}

bool ColeccionCanchas::modificarPrecioCancha(string codigo, float nuevoPrecio) {
	if (nuevoPrecio <= 0) {
		cout << "Error: El precio nuevo debe ser mayor a cero." << endl;
		return false;
	}

	Cancha* canchaEncontrada = buscarCanchaPorCodigo(codigo);
	if (canchaEncontrada == nullptr) {
		cout << "Error: No se encontro la cancha especificada." << endl;
		return false;
	}

	canchaEncontrada->setPrecioHora(nuevoPrecio);
	cout << "Precio modificado con exito" << endl;
	return true;
}

int ColeccionCanchas::getCantidadActual() const { return this->cantidadActual; }
int ColeccionCanchas::getMaxCanchas() const { return MAX_CANCHAS; }

Cancha* ColeccionCanchas::getCanchaEnPosicion(int pos) const {
	if (pos >= 0 && pos < cantidadActual) {
		return vectorCanchas[pos];
	}
	return nullptr;
}