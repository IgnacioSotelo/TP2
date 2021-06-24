#include "Juego.h"

int Jugador::numero = 1;

Juego::Juego(int filas, int columnas, int profundidad, int fichasPorCoincidir) {
	tablero = new Tablero(filas, columnas, profundidad);
	tablero->iniciarTablero();
	jugadores = new Jugadores;
	this->fichasPorCoincidir = fichasPorCoincidir;
	finDeJuego = false;
}

Juego::~Juego() {
	delete tablero;
	delete jugadores;
}

bool Juego::colocarFicha(std::string ficha, int columna, int profundidad) {
	int finDeColumna = tablero->getDimensionColumna();

	while((tablero->getCelda(columna, finDeColumna, profundidad) != ".") && finDeColumna >= 1) {
		finDeColumna--;
	}

	if(finDeColumna < 1) {
		return false;
	}

	tablero->setCelda(ficha, columna, finDeColumna, profundidad);

	if(this->buscarGanadorX(columna, finDeColumna, profundidad, ficha)) {
		std::cout << std::endl <<" **** Gano el Jugador ****" << jugadores->getJugadorActual()->getNumero() << std::endl << std::endl;
		finDeJuego = true;
	}

	if(this->buscarGanadorY(columna, finDeColumna, profundidad, ficha)) {
		std::cout << std::endl <<" **** Gano el Jugador ****" << jugadores->getJugadorActual()->getNumero() << std::endl << std::endl;
		finDeJuego = true;
	}

	return true;
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

Tablero* Juego::getTablero() {
	return tablero;
}

void Juego::seleccionarColumna(int columna, int cartaSeleccionada) {
	if(columna > 0 && columna <= tablero->getDimensionColumna()) {

		if(this->colocarFicha(jugadores->getJugadorActual()->getFicha(), columna, 1)) {

			if(cartaSeleccionada == 3) {
				this->colocarFicha(jugadores->getJugadorActual()->getFicha(), columna, 1);
			}

			if(cartaSeleccionada != 2) {
				jugadores->pasarJugador();
			}

		} else {
			std::cout << "Columna completa, selecciona otra" << std::endl;
		}
	} else {
		std::cout << "** La columna debe estar entre 1 y " << tablero->getDimensionColumna()  << " ** " << std::endl;
	}
}

int Juego::pedirCarta() {
	int cartaSeleccionada = -1;
	bool usarCarta = false;

	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Turno de jugador: " << jugadores->getJugadorActual()->getNumero() << ", ficha " << jugadores->getJugadorActual()->getFicha()<< std::endl;
	std::cout << "Cartas restantes: " << jugadores->getJugadorActual()->getCartasRestantes() << std::endl;

	while(!usarCarta) {
		if(jugadores->getJugadorActual()->getCartasRestantes() > 0) {
			std::cout << "   1) [Carta Bloquear Turno]";
			if(jugadores->getJugadorActual()->getCartaBloquearTurno()) {
				std::cout << " ------> (NO DISPONIBLE)";
			}

			std::cout << std::endl << "   2) [Carta Juega Doble]";
			if(jugadores->getJugadorActual()->getCartaJuegaDoble()) {
				std::cout << " -------- > (NO DISPONIBLE)";
			}

			std::cout << std::endl << "   3) [Carta Doble Ficha]";
			if(jugadores->getJugadorActual()->getCartaDobleFicha()) {
				std::cout << " ---------> (NO DISPONIBLE)";
			}
			std::cout << std::endl << "   0) [No usar carta]";

			std::cout << std::endl << "  Ingresar carta   > ";

			std::cin >> cartaSeleccionada;

			if(cartaSeleccionada == 1) {
				if(!jugadores->getJugadorActual()->getCartaBloquearTurno()) {
					jugadores->getJugadorActual()->usarCartaBloquearTurno();
					jugadores->getJugadorActual()->restarCarta();
					usarCarta = true;
				} else {
					cartaSeleccionada = -1;
				}

			} else if(cartaSeleccionada == 2) {

				if(!jugadores->getJugadorActual()->getCartaJuegaDoble()) {
					jugadores->getJugadorActual()->usarCartaJuegaDoble();
					jugadores->getJugadorActual()->restarCarta();
					usarCarta = true;
				} else {
					cartaSeleccionada = -1;
				}
			} else if(cartaSeleccionada == 3) {

				if(!jugadores->getJugadorActual()->getCartaDobleFicha()) {
					jugadores->getJugadorActual()->usarCartaDobleFicha();
					jugadores->getJugadorActual()->restarCarta();
					usarCarta = true;
				} else {
					cartaSeleccionada = -1;
				}
			} else if(cartaSeleccionada == 0) {
				usarCarta = true;
			}

		} else {
			usarCarta = true;
			cartaSeleccionada = -1;
		}
	}

	return cartaSeleccionada;
}

int Juego::getCantidadJugadores() {
	return jugadores->getCantidadJugadores();
}

int Juego::getIdJugadorSiguiente() {
	return jugadores->getIdJugadorSiguiente();
}

bool Juego::buscarGanadorX(int x, int y, int z, std::string ficha) {
	int dimension = tablero->getNumeroDeColumnas();
	bool conexion = false;
	int contador = 0;

	for(int i = 1; i <= dimension; i++) {
		if(conexion) {
			if(tablero->getCelda(i, y, z) == ficha) {
				contador++;
			} else {
				conexion = false;
				contador = 0;
			}
		} else {
			if(tablero->getCelda(i, y, z) == ficha) {
				conexion = true;
				contador++;
			}
		}

		if(contador >= fichasPorCoincidir) {
			return true;
		}
	}

	return false;
}

bool Juego::buscarGanadorY(int x, int y, int z, std::string ficha) {
	int dimension = tablero->getNumeroDeColumnas();
	bool conexion = false;
	int contador = 0;

	for(int i = 1; i <= dimension; i++) {
		if(conexion) {
			if(tablero->getCelda(x, i, z) == ficha) {
				contador++;
			} else {
				conexion = false;
				contador = 0;
			}
		} else {
			if(tablero->getCelda(x, i, z) == ficha) {
				conexion = true;
				contador++;
			}
		}

		if(contador >= fichasPorCoincidir) {
			return true;
		}
	}

	return false;
}

bool Juego::juegoFinalizado() {
	return finDeJuego;
}
