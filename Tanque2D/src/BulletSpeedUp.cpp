#include "BulletSpeedUp.h"
void BulletSpeedUp::aplicarEfecto(tanqueJugador& j)
{
	if (j.getVidaActual() < j.getVidaMax())
		j.aumentarVida();

}

BulletSpeedUp::BulletSpeedUp() {
	int LO = -9.9; //serian todos 10, un poco menos para evitar las paredes de la caja
	int HI = 9.9;
	posicion.x = 0.1 * (get_random(LO, HI));
	posicion.y = 0.1 * (get_random(LO, HI));

	color.set(0, 255, 0);

}
