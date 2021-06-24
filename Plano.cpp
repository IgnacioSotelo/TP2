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

std::string Plano::getCelda( int x,  int y) {
	return columnas->obtener(x)->getCelda(y);
}

void Plano::setCelda( std::string dato, int x,  int y) {
	columnas->obtener(x)->setCelda(dato, y);
}

void Plano::imprimirPlano() {
	for(int i = 1; i <= columnas->obtener(1)->getTamanio(); i++) {
		std::cout << "      ";
		for( int j = 1; j <= columnas->contarElementos(); j++) {
			std::cout << " " << columnas->obtener(j)->getCelda(i) << " ";
		}
		std::cout << std::endl;
	}
}
