#ifndef JUGADORES_H_
#define JUGADORES_H_

#include "Jugador.h"
#include "Lista.h"

class Jugadores {
private:
	Lista<Jugador*> *jugadores;
	int idJugadorActual;
	int cantidadJugadores;
public:

	Jugadores();

	~Jugadores();

	void agregarJugador(std::string ficha);

	Jugador* getJugadorActual();

	void pasarJugador();

	int getCantidadJugadores();

	int getIdJugadorSiguiente();
};


#endif /* JUGADORES_H_ */
