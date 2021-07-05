#include "ObjetoRicochet.h"

void ObjetoRicochet::aplicarEfecto(tanqueJugador& j)
{
	j.setTipoDisparo(2);
}

ObjetoRicochet::ObjetoRicochet() {
	int LO = -9.9; //serian todos 10, un poco menos para evitar las paredes de la caja
	int HI = 9.9;
	posicion.x = 0.1 * (get_random(LO, HI));
	posicion.y = 0.1 * (get_random(LO, HI));

	color.set(255, 233, 0);

}