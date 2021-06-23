#ifndef JUEGO_H_
#define JUEGO_H_

#include "Tablero.h"

class Juego {
private:
	Tablero *tablero;
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
	void colocarFicha(int ficha, int columna, int profundidad);

	/*
	 * PRE : -
	 * POST: Muestra el tablero en pantalla
	 */
	void mostrarTablero();

};

#endif /* JUEGO_H_ */
