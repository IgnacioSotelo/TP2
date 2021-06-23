/*
 * Plano.cpp
 *
 *  Created on: 22 jun. 2021
 *      Author: ignacio
 */
#include "Plano.h"

Plano::Plano() {
	columnas = new Lista<Columna*>;
}

Plano::~Plano() {
	delete columnas;
}

void Plano::agregarColumna(Columna *columna) {
	columnas->agregar(columna);
}

int Plano::getTamanio() {
	return columnas->contarElementos();
}

int Plano::getDimensionColumna() {
	return columnas->obtener(1)->getTamanio();
}

Columna* Plano::getColumna(int posicion) {
	return columnas->obtener(posicion);
}

int Plano::getCelda( int x,  int y) {
	return columnas->obtener(x)->getCelda(y);
}

void Plano::setCelda( int dato, int x,  int y) {
	columnas->obtener(x)->setCelda(dato, y);
}

void Plano::imprimirPlano() {
	for(int i = 1; i <= columnas->obtener(1)->getTamanio(); i++) {
		for( int j = 1; j <= columnas->contarElementos(); j++) {
			if(columnas->obtener(j)->getCelda(i) == 0) std::cout << " . ";
			if(columnas->obtener(j)->getCelda(i) == 1) std::cout << " X ";
			if(columnas->obtener(j)->getCelda(i) == 2) std::cout << " O ";
		}
		std::cout << std::endl;
	}
}
