#include "Cancha.h"

// Constructor por defecto: inicializa franjas en 'L' (Libre)
Cancha::Cancha() {
	this->codigo = "";
	this->deporte = "";
	this->precioHora = 0.0f;
	for (int i = 0; i < CANTIDAD_FRANJAS; i++) {
		this->franjas[i] = 'L';
	}
}

// Constructor con parámetros
Cancha::Cancha(string codigo, string deporte, float precioHora) {
	this->codigo = codigo;
	this->deporte = deporte;
	this->precioHora = precioHora;
	for (int i = 0; i < CANTIDAD_FRANJAS; i++) {
		this->franjas[i] = 'L';
	}
}

Cancha::~Cancha() {}

// Getters y Setters
string Cancha::getCodigo() const { return this->codigo; }
string Cancha::getDeporte() const { return this->deporte; }
float Cancha::getPrecioHora() const { return this->precioHora; }

void Cancha::setCodigo(string codigo) { this->codigo = codigo; }
void Cancha::setDeporte(string deporte) { this->deporte = deporte; }
void Cancha::setPrecioHora(float precioHora) { this->precioHora = precioHora; }

// Obtener estado de una franja específica (0 a 11)
char Cancha::getEstadoFranja(int pos) const {
	if (pos >= 0 && pos < CANTIDAD_FRANJAS) {
		return this->franjas[pos];
	}
	return 'X'; // Carácter de error si la posición no es válida
}

// Cambiar estado directo de franja
bool Cancha::setEstadoFranja(int pos, char estado) {
	if (pos >= 0 && pos < CANTIDAD_FRANJAS) {
		this->franjas[pos] = estado;
		return true;
	}
	return false;
}

// No podrá colocarse en mantenimiento 'M' una franja que se encuentre ocupada 'O'
bool Cancha::ponerEnMantenimiento(int pos) {
	if (pos < 0 || pos >= CANTIDAD_FRANJAS) {
		cout << "Error: Posicion de franja invalida." << endl;
		return false;
	}
	if (franjas[pos] == 'O') {
		cout << "Error: No se puede poner en mantenimiento una franja ocupada ('O')." << endl;
		return false;
	}
	franjas[pos] = 'M';
	cout << "Franja " << pos << " colocada en Mantenimiento." << endl;
	return true;
}

// Retirar el mantenimiento 'M' y devolver la franja al estado 'L'
bool Cancha::retirarMantenimiento(int pos) {
	if (pos < 0 || pos >= CANTIDAD_FRANJAS) {
		cout << "Error: Posicion de franja invalida." << endl;
		return false;
	}
	if (franjas[pos] != 'M') {
		cout << "Error: La franja seleccionada no esta en mantenimiento." << endl;
		return false;
	}
	franjas[pos] = 'L';
	cout << "Mantenimiento retirado. Franja " << pos << " ahora esta Libre ('L')." << endl;
	return true;
}

// Imprimir datos básicos
void Cancha::mostrarInformacion() const {
	cout << "Codigo: " << codigo
		<< " | Deporte: " << deporte
		<< " | Precio/Hora: " << precioHora << endl;
}

// Formato de tabla horizontal de franjas horarias como lo solicita el PDF
void Cancha::mostrarDisponibilidad() const {
	cout << "\n-------------------------------------------------------------------------------------------------" << endl;
	cout << "Disponibilidad de la Cancha " << codigo << " (Deporte: " << deporte << ")" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;

	// Encabezado de horas
	cout << "Hora:  | 08:00 | 09:00 | 10:00 | 11:00 | 12:00 | 13:00 | 14:00 | 15:00 | 16:00 | 17:00 | 18:00 | 19:00 |" << endl;

	// Estados
	cout << "Estado:|  ";
	for (int i = 0; i < CANTIDAD_FRANJAS; i++) {
		cout << franjas[i] << "    |  ";
	}
	cout << endl;

	// Índices de arreglo
	cout << "Pos:   |  [0]  |  [1]  |  [2]  |  [3]  |  [4]  |  [5]  |  [6]  |  [7]  |  [8]  |  [9]  | [10]  | [11]  |" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "(L = Libre | O = Ocupada | M = Mantenimiento)" << endl;
}

int Cancha::getCantidadFranjas() {
	return CANTIDAD_FRANJAS;
}