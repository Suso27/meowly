#include "tanqueEnemigoA.h"

tanqueEnemigoA::tanqueEnemigoA() {}

tanqueEnemigoA::tanqueEnemigoA(float x, float y) :tanqueEnemigo(x, y,"Imagenes/EnemigoA.png") {
	Inicializa();
}
tanqueEnemigoA::~tanqueEnemigoA() {}

void tanqueEnemigoA::Inicializa() {
	apuntado.x = 1.0;
	apuntado.y = 0.0;
	velocidad.x = 0.0;
	velocidad.y = 0.0;
	vel = 0.0f;
	//proyectiles.setMunicion(30);//tiene que ser menor que MAX_POYECTILES
	color.set(76, 76, 95);
	vida = 1;
	cadencia = 0.6f; //segundos
	nMaxRebotes = 0;
	vProyectil = 2;
}
