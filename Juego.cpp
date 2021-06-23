#include "Juego.h"

Juego::Juego(int filas, int columnas, int profundidad) {
	tablero = new Tablero(filas, columnas, profundidad);
	tablero->iniciarTablero();
}

Juego::~Juego() {
	delete tablero;
}

void Juego::colocarFicha(int ficha, int columna, int profundidad) {
	int finDeColumna = tablero->getDimensionColumna();

	while((tablero->getCelda(columna, finDeColumna, profundidad) != 0) && finDeColumna >= 1) {
		finDeColumna--;
	}

	tablero->setCelda(ficha, columna, finDeColumna, profundidad);
}

void Juego::mostrarTablero() {
	tablero->mostrarTablero();
}
