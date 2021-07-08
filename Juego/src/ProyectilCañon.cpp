#include "ProyectilCañon.h"

ProyectilCañon::ProyectilCañon(Vector2D vel, Vector2D pos, int d, int n, float velModulo) {
	rebotes = 0;
	nMaxRebotes = n;
	daño = d+10;
	posicion = pos;
	velocidad = vel * velModulo*0.4;
	radio = 0.08f; 
};