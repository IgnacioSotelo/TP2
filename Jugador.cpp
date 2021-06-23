#include "Jugador.h"

Jugador::Jugador(std::string ficha) {
	id = numero;
	numero++;
	cartaBloquearTurno = true;
	cartaJuegaDoble = true;
	cartaDobleFicha = true;
	fichasRestantes = 50;
	cartasRestantes = 3;
	this->ficha = ficha;
}

int Jugador::getNumero() {
	return id;
}

std::string Jugador::getFicha() {
	return ficha;
}
