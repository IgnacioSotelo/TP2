/*
 * Columna.cpp
 *
 *  Created on: 22 jun. 2021
 *      Author: ignacio
 */
#include "Columna.h"

Columna::Columna() {
	celdas = new Lista<int>;
}

Columna::~Columna() {
	delete celdas;
}

void Columna::agregarCelda(int dato) {
	celdas->agregar(dato);
}

void Columna::agregarCelda(int dato, int posicion) {
	celdas->agregar(dato, posicion);
}

void Columna::setCelda(int dato, int posicion) {
	celdas->asignar(dato, posicion);
}

int Columna::getCelda( int posicion) {
	return celdas->obtener(posicion);
}

int Columna::getTamanio() {
	return celdas->contarElementos();
}


