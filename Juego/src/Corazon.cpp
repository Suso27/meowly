#include "Corazon.h"

void Corazon::aplicarEfecto(tanqueJugador& j)
{
	if (j.getVidaMax()<10)
	j.aumentarVidaMax();
	j.aumentarVida();
	
}

Corazon::Corazon() {
	float LO = -9.9f; //serian todos 10, un poco menos para evitar las paredes de la caja
	float HI = 9.9f;
	posicion.x = 0.1f * (get_random(LO, HI));
	posicion.y = 0.1f * (get_random(LO, HI));

	color.set(255, 0, 0);

}

