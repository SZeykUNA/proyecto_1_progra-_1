#include "Interfaz.h"

Interfaz::Interfaz() {}
Interfaz::~Interfaz() {}

// Métodos de validación 
int Interfaz::leerEntero(string mensaje) {
	int valor;
	cout << mensaje;
	while (!(cin >> valor)) {
		cout << "Entrada invalida. Ingrese un numero entero: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	cin.ignore(1000, '\n');
	return valor;
}

float Interfaz::leerFloat(string mensaje) {
	float valor;
	cout << mensaje;
	while (!(cin >> valor) || valor < 0) {
		cout << "Entrada invalida. Ingrese un numero valido: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	cin.ignore(1000, '\n');
	return valor;
}

string Interfaz::leerTexto(string mensaje) {
	string texto;
	cout << mensaje;
	getline(cin, texto);
	return texto;
}

// Submenú de Canchas
void Interfaz::menuCanchas() {
	int opcion = 0;
	do {
		cout << "\n--- GESTION DE CANCHAS ---" << endl;
		cout << "1. Registrar cancha" << endl;
		cout << "2. Mostrar todas las canchas" << endl;
		cout << "3. Buscar cancha por codigo" << endl;
		cout << "4. Modificar precio de cancha" << endl;
		cout << "5. Mostrar disponibilidad de cancha" << endl;
		cout << "6. Cambiar mantenimiento de franja" << endl;
		cout << "7. Volver al menu principal" << endl;
		opcion = leerEntero("Seleccione una opcion: ");

		if (opcion == 1) {
			string cod = leerTexto("Codigo de cancha: ");
			string dep = leerTexto("Deporte: ");
			float precio = leerFloat("Precio por hora: ");
			coleccionCanchas.agregarCancha(new Cancha(cod, dep, precio));
		}
		else if (opcion == 2) {
			coleccionCanchas.mostrarTodasLasCanchas();
		}
		else if (opcion == 3) {
			string cod = leerTexto("Codigo a buscar: ");
			Cancha* c = coleccionCanchas.buscarCanchaPorCodigo(cod);
			if (c != nullptr) c->mostrarInformacion();
			else cout << "Cancha no encontrada." << endl;
		}
		else if (opcion == 4) {
			string cod = leerTexto("Codigo de cancha: ");
			float nuevoP = leerFloat("Nuevo precio: ");
			coleccionCanchas.modificarPrecioCancha(cod, nuevoP);
		}
		else if (opcion == 5) {
			string cod = leerTexto("Codigo de cancha: ");
			Cancha* c = coleccionCanchas.buscarCanchaPorCodigo(cod);
			if (c != nullptr) c->mostrarDisponibilidad();
			else cout << "Cancha no encontrada." << endl;
		}
		else if (opcion == 6) {
			string cod = leerTexto("Codigo de cancha: ");
			Cancha* c = coleccionCanchas.buscarCanchaPorCodigo(cod);
			if (c != nullptr) {
				int franja = leerEntero("Numero de franja (0 a 11): ");
				int accion = leerEntero("1. Poner mantenimiento / 2. Retirar mantenimiento: ");
				if (accion == 1) c->ponerEnMantenimiento(franja);
				else if (accion == 2) c->retirarMantenimiento(franja);
			}
			else {
				cout << "Cancha no encontrada." << endl;
			}
		}
	} while (opcion != 7);
}

// Submenú de Clientes
void Interfaz::menuClientes() {
	int opcion = 0;
	do {
		cout << "\n--- GESTION DE CLIENTES ---" << endl;
		cout << "1. Registrar cliente" << endl;
		cout << "2. Mostrar listado de clientes" << endl;
		cout << "3. Buscar cliente por identificacion" << endl;
		cout << "4. Mostrar reservas de un cliente" << endl;
		cout << "5. Volver al menu principal" << endl;
		opcion = leerEntero("Seleccione una opcion: ");

		if (opcion == 1) {
			string id = leerTexto("Identificacion: ");
			string nombre = leerTexto("Nombre completo: ");
			string tel = leerTexto("Telefono: ");
			coleccionClientes.agregarCliente(new Cliente(nombre, id, tel));
		}
		else if (opcion == 2) {
			coleccionClientes.mostrarListadoClientes();
		}
		else if (opcion == 3) {
			string id = leerTexto("Identificacion a buscar: ");
			Cliente* cl = coleccionClientes.buscarClientePorId(id);
			if (cl != nullptr) cl->mostrarCliente();
			else cout << "Cliente no encontrado." << endl;
		}
		else if (opcion == 4) {
			string id = leerTexto("Identificacion del cliente: ");
			coleccionReservas.mostrarReservasPorCliente(id);
		}
	} while (opcion != 5);
}

// Submenú de Reservas
void Interfaz::menuReservas() {
	int opcion = 0;
	do {
		cout << "\n--- GESTION DE RESERVAS ---" << endl;
		cout << "1. Registrar reserva" << endl;
		cout << "2. Mostrar todas las reservas" << endl;
		cout << "3. Buscar reserva por numero" << endl;
		cout << "4. Mostrar reservas por cancha" << endl;
		cout << "5. Cancelar reserva" << endl;
		cout << "6. Volver al menu principal" << endl;
		opcion = leerEntero("Seleccione una opcion: ");

		if (opcion == 1) {
			string idCl = leerTexto("Identificacion del cliente: ");
			Cliente* cl = coleccionClientes.buscarClientePorId(idCl);
			if (cl == nullptr) {
				cout << "Cliente no registrado." << endl;
				continue;
			}

			string codCa = leerTexto("Codigo de la cancha: ");
			Cancha* ca = coleccionCanchas.buscarCanchaPorCodigo(codCa);
			if (ca == nullptr) {
				cout << "Cancha no registrada." << endl;
				continue;
			}

			int inicio = leerEntero("Franja inicial (0 a 11): ");
			int cant = leerEntero("Cantidad de franjas seguidas: ");

			bool exito = coleccionReservas.registrarReserva(cl, ca, inicio, cant);
			if (!exito && ca->getEstadoFranja(inicio) == 'O') {
				int opcEspera = leerEntero("¿Desea agregar al cliente a la lista de espera para esta franja? (1. Si / 2. No): ");
				if (opcEspera == 1) {
					listadoEspera.registrarEnEspera(cl, ca, inicio);
				}
			}
		}
		else if (opcion == 2) {
			coleccionReservas.mostrarTodasLasReservas();
		}
		else if (opcion == 3) {
			int num = leerEntero("Numero de reserva: ");
			Reserva* r = coleccionReservas.buscarReservaPorNumero(num);
			if (r != nullptr) r->mostrarReserva();
			else cout << "Reserva no encontrada." << endl;
		}
		else if (opcion == 4) {
			string cod = leerTexto("Codigo de cancha: ");
			coleccionReservas.mostrarReservasPorCancha(cod);
		}
		else if (opcion == 5) {
			int num = leerEntero("Numero de reserva a cancelar: ");
			Reserva* r = coleccionReservas.buscarReservaPorNumero(num);
			if (r != nullptr && r->isActiva()) {
				string codCancha = r->getCancha()->getCodigo();
				int franja = r->getFranjaInicial();
				coleccionReservas.cancelarReserva(num);
				// Notificar si hay gente en espera
				listadoEspera.verificarEsperasPorCanchaYFranja(codCancha, franja);
			}
			else {
				cout << "No se pudo cancelar la reserva." << endl;
			}
		}
	} while (opcion != 6);
}

// Submenú de Lista de Espera
void Interfaz::menuListadoEspera() {
	int opcion = 0;
	do {
		cout << "\n--- LISTADO DE ESPERA ---" << endl;
		cout << "1. Mostrar listado de espera" << endl;
		cout << "2. Cambiar estado de un registro" << endl;
		cout << "3. Volver al menu principal" << endl;
		opcion = leerEntero("Seleccione una opcion: ");

		if (opcion == 1) {
			listadoEspera.mostrarListadoEspera();
		}
		else if (opcion == 2) {
			int num = leerEntero("Numero consecutivo de espera: ");
			string est = leerTexto("Nuevo estado (asignado / cancelado): ");
			listadoEspera.cambiarEstadoEspera(num, est);
		}
	} while (opcion != 3);
}

// Submenú de Reportes
void Interfaz::menuReportes() {
	int opcion = 0;
	do {
		cout << "\n--- REPORTES Y ESTADISTICAS ---" << endl;
		cout << "1. Cancha con mayor cantidad de reservas activas" << endl;
		cout << "2. Cliente con mayor cantidad de reservas activas" << endl;
		cout << "3. Ingreso total generado por reservas activas" << endl;
		cout << "4. Porcentaje de ocupacion de cada cancha" << endl;
		cout << "5. Horas con mayor y menor cantidad de reservas" << endl;
		cout << "6. Volver al menu principal" << endl;
		opcion = leerEntero("Seleccione una opcion: ");

		if (opcion == 1) Reportes::canchaConMasReservas(coleccionCanchas, coleccionReservas);
		else if (opcion == 2) Reportes::clienteConMasReservas(coleccionClientes, coleccionReservas);
		else if (opcion == 3) Reportes::ingresoTotalReservas(coleccionReservas);
		else if (opcion == 4) Reportes::porcentajeOcupacionPorCancha(coleccionCanchas);
		else if (opcion == 5) Reportes::horasConMayorYMenorOcupacion(coleccionReservas);
	} while (opcion != 6);
}

// Menú principal
void Interfaz::ejecutar() {
	int opcion = 0;
	do {
		cout << "\nCENTRO DEPORTIVO ZONA ACTIVA" << endl;
		cout << "1. Gestion de canchas" << endl;
		cout << "2. Gestion de clientes" << endl;
		cout << "3. Gestion de reservas" << endl;
		cout << "4. Gestion de listado de espera" << endl;
		cout << "5. Reportes y estadisticas" << endl;
		cout << "6. Salir" << endl;
		opcion = leerEntero("Seleccione una opcion: ");

		switch (opcion) {
		case 1: menuCanchas(); break;
		case 2: menuClientes(); break;
		case 3: menuReservas(); break;
		case 4: menuListadoEspera(); break;
		case 5: menuReportes(); break;
		case 6: cout << "Saliendo del sistema..." << endl; break;
		default: cout << "Opcion invalida." << endl; break;
		}
	} while (opcion != 6);
}