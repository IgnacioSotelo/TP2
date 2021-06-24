#ifndef JUEGO_H_
#define JUEGO_H_

#include "Tablero.h"
#include "Jugadores.h"

class Juego {
private:
	Tablero *tablero;
	Jugadores *jugadores;
	int fichasPorCoincidir;
	bool finDeJuego;
public:

	/*
	 * PRE : -
	 * POST: Inicia un nuevo juego
	 */
	Juego(int filas, int columnas, int profundidad, int fichasPorCoincidir);

	/*
	 * PRE : -
	 * POST: Destructor
	 */
	~Juego();

	/*
	 * PRE : La fila y columna debe existir
	 * POST: Coloca una ficha en el tablero, devuelve false si la columna esta completa
	 */
	bool colocarFicha(std::string ficha, int columna, int profundidad);

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

	Tablero* getTablero();

	int pedirCarta();

	void seleccionarColumna(int columna, int cartaSeleccionada);

	int getCantidadJugadores();

	int getIdJugadorSiguiente();

	bool buscarGanadorX(int x, int y, int z, std::string ficha);

	bool buscarGanadorY(int x, int y, int z, std::string ficha);

	bool juegoFinalizado();
};

#endif /* JUEGO_H_ */
