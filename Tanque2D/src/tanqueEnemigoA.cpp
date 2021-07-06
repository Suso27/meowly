#include "tanqueEnemigoA.h"

tanqueEnemigoA::tanqueEnemigoA() {}

tanqueEnemigoA::tanqueEnemigoA(float x, float y) :tanqueEnemigo(x, y) {
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

	/*spriteTanque = { "imagenes/Desert/Bodies/body_halftrack.png", 2 };
	spriteAnimacionTanque = { "imagenes/Desert/Weapons/turret_01_mk1.png", 8 };
	spriteTanque.setCenter(posicion.x -1.5, posicion.y+0.2);
	spriteTanque.setSize(0.4, 0.4);
	spriteAnimacionTanque.setCenter(posicion.x - 1.5, posicion.y + 0.2);
	spriteAnimacionTanque.setSize(0.4, 0.4);
	spriteAnimacionTanque.setState(0, false);
	spriteTanque.setState(0, false);*/
}
