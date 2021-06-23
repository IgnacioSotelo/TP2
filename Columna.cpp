#include "Columna.h"

Columna::Columna() {
	celdas = new Lista<std::string>;
}

Columna::~Columna() {
	delete celdas;
}

void Columna::agregarCelda(std::string dato) {
	celdas->agregar(dato);
}

void Columna::agregarCelda(std::string dato, int posicion) {
	celdas->agregar(dato, posicion);
}

void Columna::setCelda(std::string dato, int posicion) {
	celdas->asignar(dato, posicion);
}

std::string Columna::getCelda(int posicion) {
	return celdas->obtener(posicion);
}

int Columna::getTamanio() {
	return celdas->contarElementos();
}


