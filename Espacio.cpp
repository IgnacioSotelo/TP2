#include "Espacio.h"


Espacio::Espacio() {
	planos = new Lista<Plano*>;
}

Espacio::~Espacio() {
	delete planos;
}

void Espacio::agregarPlano(Plano* plano) {
	planos->agregar(plano);
}

int Espacio::getTamanio() {
	return planos->contarElementos();
}

int Espacio::getDimensionColumna() {
	return planos->obtener(1)->getDimensionColumna();
}

Plano* Espacio::getPlano(int posicion) {
	return planos->obtener(posicion);
}

std::string Espacio::getCelda( int x,  int y, int z) {
	return planos->obtener(z)->getColumna(x)->getCelda(y);
}

void Espacio::setCelda(std::string dato, int x, int y, int z) {
	planos->obtener(z)->setCelda(dato, x, y);
}

void Espacio::imprimirEspacio() {
	for(int i = 1; i <= planos->contarElementos(); i++) {
		std::cout << "Z = " << i << ": " << std::endl;
		planos->obtener(i)->imprimirPlano();
		std::cout << std::endl << std::endl;
	}
}


