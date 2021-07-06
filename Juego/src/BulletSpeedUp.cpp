#include "BulletSpeedUp.h"
void BulletSpeedUp::aplicarEfecto(tanqueJugador& j)
{
	j.aumentarVproyectil(2);
}

BulletSpeedUp::BulletSpeedUp() {
	float LO = -9.9f; //serian todos 10, un poco menos para evitar las paredes de la caja
	float HI = 9.9f;
	posicion.x = 0.1f * (get_random(LO, HI));
	posicion.y = 0.1f * (get_random(LO, HI));

	color.set(0, 255, 0);

	//sprite
	spriteObjeto = { "imagenes/bulletspeed.png" };
	spriteObjeto.setCenter(0, 0);
	spriteObjeto.setSize(0.1, 0.1);
}
