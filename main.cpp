#include <iostream>
#include "Juego.h"
using namespace std;

int main() {
	Juego juego(5,5,1);
	string ficha;
	int input = -1;
	cout << "Ingresar fichas (caracteres) para cada jugador" << endl << "[0 para terminar]" << endl;

	while(ficha != "0") {
		cout << "Ingresar ficha para jugador " << juego.getCantidadJugadores() + 1 << ": ";
		cin >> ficha;

		if(ficha != "0") {
			juego.agregarJugador(ficha);
		}
	}

	while(input != 0) {
		int cartaSeleccionada = -1;

		cartaSeleccionada = juego.pedirCarta();

		cout << "  Ingresar columna > ";
		cin >> input;

		juego.seleccionarColumna(input, cartaSeleccionada);

		if(cartaSeleccionada == 1) {
			cout << "El jugador " << juego.getIdJugadorSiguiente() << " pierde un turno" << endl;
			juego.pasarJugador();
		}

		if(cartaSeleccionada == 2) {
			juego.mostrarTablero();
			cout << "Jugador " << juego.getJugadorActual()->getNumero() << " juega nuevamente: " << endl;
			cout << "  Ingresar columna > ";
			cin >> input;

			juego.seleccionarColumna(input, cartaSeleccionada);
			juego.pasarJugador();
		}

		juego.mostrarTablero();
	}

	return 0;
}
