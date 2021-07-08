#include "ProyectilCa�on.h"

ProyectilCa�on::ProyectilCa�on(Vector2D vel, Vector2D pos, int d, int n, float velModulo) {
	rebotes = 0;
	nMaxRebotes = n;
	da�o = d+10;
	posicion = pos;
	velocidad = vel * velModulo*0.4;
	radio = 0.08f; 
};