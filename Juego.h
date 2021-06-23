#ifndef JUEGO_H_
#define JUEGO_H_

#include "Tablero.h"
#include "Jugadores.h"

class Juego {
private:
	Tablero *tablero;
	Jugadores *jugadores;
public:

	/*
	 * PRE : -
	 * POST: Inicia un nuevo juego
	 */
	Juego(int filas, int columnas, int profundidad);

	/*
	 * PRE : -
	 * POST: Destructor
	 */
	~Juego();

	/*
	 * PRE : La fila y columna debe existir
	 * POST: Coloca una ficha en el tablero
	 */
	void colocarFicha(std::string ficha, int columna, int profundidad);

	/*
	 * PRE : -
	 * POST: Muestra el tablero en pantalla
	 */
	void mostrarTablero();

	/*
	 * PRE : -
	 * POST: Agrega un jugador a la lista de jugadores
	 */
	void agregarJugador(std::string ficha);

	/*
	 * PRE : -
	 * POST: Devuelve el jugador en curso
	 */
	Jugador* getJugadorActual();

	void pasarJugador();

};

#endif /* JUEGO_H_ */
