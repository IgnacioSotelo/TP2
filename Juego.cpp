#include "Juego.h"

int Jugador::numero = 1;

Juego::Juego(int filas, int columnas, int profundidad) {
	tablero = new Tablero(filas, columnas, profundidad);
	tablero->iniciarTablero();
	jugadores = new Jugadores;
}

Juego::~Juego() {
	delete tablero;
	delete jugadores;
}

void Juego::colocarFicha(std::string ficha, int columna, int profundidad) {
	int finDeColumna = tablero->getDimensionColumna();

	while((tablero->getCelda(columna, finDeColumna, profundidad) != ".") && finDeColumna >= 1) {
		finDeColumna--;
	}

	tablero->setCelda(ficha, columna, finDeColumna, profundidad);
}

void Juego::mostrarTablero() {
	tablero->mostrarTablero();
}

void Juego::agregarJugador(std::string ficha) {
	jugadores->agregarJugador(ficha);
}

Jugador* Juego::getJugadorActual() {
	return jugadores->getJugadorActual();
}

void Juego::pasarJugador() {
	jugadores->pasarJugador();
}
