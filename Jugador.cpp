#include "Jugador.h"

Jugador::Jugador(std::string ficha) {
	id = numero;
	numero++;
	cartaBloquearTurno = false;
	cartaJuegaDoble = false;
	cartaDobleFicha = false;
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

int Jugador::getCartasRestantes() {
	return cartasRestantes;
}

int Jugador::getFichasRestantes() {
	return fichasRestantes;
}

bool Jugador::getCartaBloquearTurno() {
	return cartaBloquearTurno;
}

bool Jugador::getCartaJuegaDoble() {
	return cartaJuegaDoble;
}

bool Jugador::getCartaDobleFicha() {
	return cartaDobleFicha;
}

void Jugador::usarCartaBloquearTurno() {
	cartaBloquearTurno = true;
}

void Jugador::usarCartaJuegaDoble() {
	cartaJuegaDoble = true;
}

void Jugador::usarCartaDobleFicha() {
	cartaDobleFicha = true;
}

void Jugador::restarCarta() {
	cartasRestantes--;
}

