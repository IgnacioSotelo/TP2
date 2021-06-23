#include "Jugadores.h"

Jugadores::Jugadores() {
	jugadores = new Lista<Jugador*>;
	idJugadorActual = 1;
	cantidadJugadores = 0;
}

Jugadores::~Jugadores() {
	delete jugadores;
}

void Jugadores::agregarJugador(std::string ficha) {
	jugadores->agregar(new Jugador(ficha));
	cantidadJugadores++;
}

Jugador* Jugadores::getJugadorActual() {
	return jugadores->obtener(idJugadorActual);
}

void Jugadores::pasarJugador() {
	idJugadorActual >= cantidadJugadores ? idJugadorActual = 1:idJugadorActual ++;
}
