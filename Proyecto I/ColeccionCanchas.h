#pragma once
#include "Cancha.h"
#include <iostream>

using namespace std;

class ColeccionCanchas {
private:
	static const int MAX_CANCHAS = 10; // Máximo 10 canchas
	Cancha** vectorCanchas;            // Arreglo dinámico de punteros a Cancha
	int cantidadActual;

public:
	ColeccionCanchas();
	~ColeccionCanchas();

	bool agregarCancha(Cancha* nuevaCancha);
	Cancha* buscarCanchaPorCodigo(string codigo) const;
	void mostrarTodasLasCanchas() const;
	bool modificarPrecioCancha(string codigo, float nuevoPrecio);

	int getCantidadActual() const;
	int getMaxCanchas() const;
	Cancha* getCanchaEnPosicion(int pos) const;
};