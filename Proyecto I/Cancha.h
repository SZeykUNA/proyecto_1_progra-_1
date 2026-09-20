#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cancha {
private:
	static const int CANTIDAD_FRANJAS = 12; // 12 franjas horarias de 08:00 a 20:00
	string codigo;
	string deporte;
	float precioHora;
	char franjas[CANTIDAD_FRANJAS]; // Arreglo con estados 'L', 'O', 'M'

public:
	// Constructores y Destructor
	Cancha();
	Cancha(string codigo, string deporte, float precioHora);
	~Cancha();

	// Getters y Setters básicos
	string getCodigo() const;
	string getDeporte() const;
	float getPrecioHora() const;

	void setCodigo(string codigo);
	void setDeporte(string deporte);
	void setPrecioHora(float precioHora);

	// Métodos para el manejo de franjas horarias
	char getEstadoFranja(int pos) const;
	bool setEstadoFranja(int pos, char estado); // Modificar una franja válida
	bool ponerEnMantenimiento(int pos);         // Regla: No se puede si está 'O'
	bool retirarMantenimiento(int pos);        // Cambiar 'M' a 'L'

	// Visualización
	void mostrarInformacion() const;
	void mostrarDisponibilidad() const;

	// Getter auxiliar de la constante de franjas
	static int getCantidadFranjas();
};