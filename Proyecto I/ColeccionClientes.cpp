#include "ColeccionClientes.h"

// Constructor
ColeccionClientes::ColeccionClientes() {
	this->cantidadActual = 0;

	// Reservamos memoria para el arreglo de punteros de tamaño MAX_CLIENTES
	this->vectorClientes = new Cliente * [MAX_CLIENTES];
	for (int i = 0; i < MAX_CLIENTES; i++) {
		this->vectorClientes[i] = nullptr;
	}
}

// Destructor
ColeccionClientes::~ColeccionClientes() {
	for (int i = 0; i < cantidadActual; i++) {
		if (vectorClientes[i] != nullptr) {
			delete vectorClientes[i];
		}
	}
	delete[] vectorClientes;
}

// Registrar / Agregar cliente
bool ColeccionClientes::agregarCliente(Cliente* nuevoCliente) {
	if (nuevoCliente == nullptr) return false;

	// Uso de la constante para validar el límite
	if (cantidadActual >= MAX_CLIENTES) {
		cout << "Error: Se ha alcanzado el limite maximo de clientes (" << MAX_CLIENTES << ")." << endl;
		return false;
	}

	// Validar si ya existe un cliente con la misma identificación
	if (buscarClientePorId(nuevoCliente->getId()) != nullptr) {
		cout << "Error: Ya existe un cliente registrado con esa identificacion." << endl;
		return false;
	}

	vectorClientes[cantidadActual] = nuevoCliente;
	cantidadActual++;
	cout << "¡Cliente registrado con exito!" << endl;
	return true;
}

// Buscar cliente por cédula
Cliente* ColeccionClientes::buscarClientePorId(string id) const {
	for (int i = 0; i < cantidadActual; i++) {
		if (vectorClientes[i]->getId() == id) {
			return vectorClientes[i];
		}
	}
	return nullptr;
}

// Mostrar listado de clientes
void ColeccionClientes::mostrarListadoClientes() const {
	if (cantidadActual == 0) {
		cout << "No hay clientes registrados en el sistema." << endl;
		return;
	}
	cout << "          LISTADO DE CLIENTES           " << endl;
	for (int i = 0; i < cantidadActual; i++) {
		cout << i + 1 << ". ";
		vectorClientes[i]->mostrarCliente();
	}
}

int ColeccionClientes::getCantidadActual() const {
	return this->cantidadActual;
}

int ColeccionClientes::getMaxClientes() const {
	return MAX_CLIENTES;
}
