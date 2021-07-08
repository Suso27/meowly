#include "tanqueEnemigoB.h"

tanqueEnemigoB::tanqueEnemigoB(){}

tanqueEnemigoB::tanqueEnemigoB(float x, float y):tanqueEnemigo(x,y,"Imagenes/EnemigoB.png"){
	Inicializa();
}

tanqueEnemigoB::~tanqueEnemigoB(){}

void tanqueEnemigoB::Inicializa() {
	apuntado.x = 1.0;
	apuntado.y = 0.0;
	velocidad.x = 0.0;
	velocidad.y = 0.0;
	vel = 0.003f;
	//proyectiles.setMunicion(30);//tiene que ser menor que MAX_POYECTILES
	color.set(114, 114, 142);
	vida = 3;
	cadencia = 2.0f; //segundos
	nMaxRebotes = 1;
}
