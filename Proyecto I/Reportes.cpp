#include "Reportes.h"

Reportes::Reportes() {}
Reportes::~Reportes() {}

// 1. Cancha con mayor cantidad de reservas activas
void Reportes::canchaConMasReservas(const ColeccionCanchas& coleccionCanchas, const ColeccionReservas& coleccionReservas) {
	if (coleccionCanchas.getCantidadActual() == 0 || coleccionReservas.getCantidadActual() == 0) {
		cout << "No hay suficiente informacion registrada para este reporte." << endl;
		return;
	}

	Cancha* canchaMayor = nullptr;
	int maxReservas = -1;

	for (int i = 0; i < coleccionCanchas.getCantidadActual(); i++) {
		// Para cada cancha contamos sus reservas activas
		int conteo = 0;
		Cancha* canchaActual = nullptr;

		// Buscamos las reservas activas asociadas a esta cancha
		for (int j = 0; j < coleccionReservas.getCantidadActual(); j++) {
			Reserva* res = coleccionReservas.getReservaEnPosicion(j);
			if (res != nullptr && res->isActiva()) {
				canchaActual = res->getCancha();
				// Si la reserva coincide con la cancha que estamos evaluando
				for (int k = 0; k < coleccionCanchas.getCantidadActual(); k++) {
					if (res->getCancha()->getCodigo() == res->getCancha()->getCodigo()) {
						conteo++;
						break;
					}
				}
			}
		}

		if (conteo > maxReservas) {
			maxReservas = conteo;
			canchaMayor = canchaActual;
		}
	}

	cout << "\n=== REPORTES: CANCHA MAS RESERVADA ===" << endl;
	if (canchaMayor != nullptr && maxReservas > 0) {
		cout << "Cancha: " << canchaMayor->getCodigo() << " (" << canchaMayor->getDeporte() << ")" << endl;
		cout << "Total de reservas activas: " << maxReservas << endl;
	}
	else {
		cout << "No hay reservas activas registradas todavia." << endl;
	}
}

// 2. Cliente con mayor cantidad de reservas activas
void Reportes::clienteConMasReservas(const ColeccionClientes& coleccionClientes, const ColeccionReservas& coleccionReservas) {
	if (coleccionClientes.getCantidadActual() == 0 || coleccionReservas.getCantidadActual() == 0) {
		cout << "No hay suficiente informacion registrada para este reporte." << endl;
		return;
	}

	Cliente* clienteMayor = nullptr;
	int maxReservas = 0;

	for (int i = 0; i < coleccionClientes.getCantidadActual(); i++) {
		int conteo = 0;
		for (int j = 0; j < coleccionReservas.getCantidadActual(); j++) {
			Reserva* res = coleccionReservas.getReservaEnPosicion(j);
			if (res != nullptr && res->isActiva()) {
				if (res->getCliente()->getId() == res->getCliente()->getId()) {
					conteo++;
				}
			}
		}

		if (conteo > maxReservas) {
			maxReservas = conteo;
			// Guardamos la referencia
			for (int k = 0; k < coleccionReservas.getCantidadActual(); k++) {
				Reserva* res = coleccionReservas.getReservaEnPosicion(k);
				if (res != nullptr && res->isActiva()) {
					clienteMayor = res->getCliente();
					break;
				}
			}
		}
	}

	cout << "\n=== REPORTES: CLIENTE CON MAS RESERVAS ===" << endl;
	if (clienteMayor != nullptr && maxReservas > 0) {
		cout << "Nombre: " << clienteMayor->getNombreCompleto() << " | ID: " << clienteMayor->getId() << endl;
		cout << "Total de reservas activas: " << maxReservas << endl;
	}
	else {
		cout << "No hay reservas activas registradas todavia." << endl;
	}
}

// 3. Ingreso total generado por reservas activas
void Reportes::ingresoTotalReservas(const ColeccionReservas& coleccionReservas) {
	float ingresoTotal = 0.0f;
	int conteoActivas = 0;

	for (int i = 0; i < coleccionReservas.getCantidadActual(); i++) {
		Reserva* res = coleccionReservas.getReservaEnPosicion(i);
		if (res != nullptr && res->isActiva()) {
			ingresoTotal += res->getMontoTotal();
			conteoActivas++;
		}
	}

	cout << "\n=== REPORTES: INGRESO TOTAL ===" << endl;
	cout << "Cantidad de reservas activas: " << conteoActivas << endl;
	cout << "Ingreso Total Generado: " << ingresoTotal << endl;
}

// 4. Porcentaje de ocupacion de cada cancha
void Reportes::porcentajeOcupacionPorCancha(const ColeccionCanchas& coleccionCanchas) {
	if (coleccionCanchas.getCantidadActual() == 0) {
		cout << "No hay canchas registradas." << endl;
		return;
	}

	cout << "\n=== PORCENTAJE DE OCUPACION POR CANCHA ===" << endl;
	for (int i = 0; i < coleccionCanchas.getCantidadActual(); i++) {
		// Se ocuparia obtener el puntero de la cancha
		// En 12 franjas totales: porcentaje = (ocupadas / 12) * 100
		cout << "Cancha " << i + 1 << ": Evaluando disponibilidad de las 12 franjas..." << endl;
	}
}

// 5. Horas con mayor y menor cantidad de reservas
void Reportes::horasConMayorYMenorOcupacion(const ColeccionReservas& coleccionReservas) {
	int contadorFranjas[12] = { 0 };

	for (int i = 0; i < coleccionReservas.getCantidadActual(); i++) {
		Reserva* res = coleccionReservas.getReservaEnPosicion(i);
		if (res != nullptr && res->isActiva()) {
			int inicio = res->getFranjaInicial();
			int cant = res->getCantidadFranjas();
			for (int j = inicio; j < inicio + cant; j++) {
				if (j >= 0 && j < 12) {
					contadorFranjas[j]++;
				}
			}
		}
	}

	int maxOcupacion = -1, minOcupacion = 999;
	int horaMasOcupada = 0, horaMenosOcupada = 0;

	for (int i = 0; i < 12; i++) {
		if (contadorFranjas[i] > maxOcupacion) {
			maxOcupacion = contadorFranjas[i];
			horaMasOcupada = i;
		}
		if (contadorFranjas[i] < minOcupacion) {
			minOcupacion = contadorFranjas[i];
			horaMenosOcupada = i;
		}
	}

	cout << "\n=== HORAS CON MAYOR Y MENOR RESERVA ===" << endl;
	cout << "Hora con MAYOR ocupacion: Franja [" << horaMasOcupada << "] (" << (8 + horaMasOcupada) << ":00) con " << maxOcupacion << " reservas." << endl;
	cout << "Hora con MENOR ocupacion: Franja [" << horaMenosOcupada << "] (" << (8 + horaMenosOcupada) << ":00) con " << minOcupacion << " reservas." << endl;
}