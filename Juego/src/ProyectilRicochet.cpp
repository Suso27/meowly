#include "ProyectilRicochet.h"

ProyectilRicochet::ProyectilRicochet(Vector2D vel, Vector2D pos, int d, int n, float velModulo) {
	rebotes = 0;
	nMaxRebotes = n*2;
	daño = d;
	posicion = pos;
	velocidad = vel * velModulo * 1.75;
	radio = 0.01f;
};