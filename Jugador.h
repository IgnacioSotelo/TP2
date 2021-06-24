#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <iostream>

class Jugador {
private:
	int id;
	std::string ficha;
	bool cartaBloquearTurno; // = t (t : usada, f: disponible)
	bool cartaJuegaDoble;    // "  "
	bool cartaDobleFicha;
	int fichasRestantes;
	int cartasRestantes;

public:
	static int numero;

	Jugador(std::string ficha);

	int getNumero();

	std::string getFicha();

	int getCartasRestantes();

	int getFichasRestantes();

	bool getCartaBloquearTurno();

	bool getCartaJuegaDoble();

	bool getCartaDobleFicha();

	void usarCartaBloquearTurno();

	void usarCartaJuegaDoble();

	void usarCartaDobleFicha();

	void restarCarta();

};


#endif /* JUGADOR_H_ */
