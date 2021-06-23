#include <iostream>
#include "Juego.h"
using namespace std;

int main() {
	Juego juego(5,5,1);
	int input = -1;
	int contador = 1;

	while(input != 0) {
		string ficha;
		cout << "Ingresar ficha para jugador " << contador++ << ": ";
		cin >> ficha;
		juego.agregarJugador(ficha);
		cout << "Agregar otro jugador? 1: si  -  0: no ";
		cin >> input;
	}

	input = -1;

	while(input != 0) {
		cout << "--------------------------------------------------------" << endl;
		cout << "Turno de jugador: " << juego.getJugadorActual()->getNumero() << ", ficha " << juego.getJugadorActual()->getFicha()<< endl;

		cout << "Ingresar columna: ";
		cin >> input;

		juego.colocarFicha(juego.getJugadorActual()->getFicha(), input, 1);
		juego.mostrarTablero();
		juego.pasarJugador();
	}

	return 0;
}
