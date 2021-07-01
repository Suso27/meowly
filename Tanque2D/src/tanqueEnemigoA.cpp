#include "tanqueEnemigoA.h"

void tanqueEnemigoA::Inicializa(float x, float y) {
	posicion.x = x;
	posicion.y = y;
	apuntado.x = 1.0;
	apuntado.y = 0.0;
	velocidad.x = 0.0;
	velocidad.y = 0.0;
	vel = 0.0f;
	proyectiles.setMunicion(30);//tiene que ser menor que MAX_POYECTILES
	color.set(76, 76, 95);
	vida = 1;
	cadencia = 0.6f; //segundos
	nMaxRebotes = 0;
	vProyectil = 2;
}