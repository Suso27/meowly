#include "tanqueEnemigo.h"


tanqueEnemigo::tanqueEnemigo(){
	Inicializa();
}

void tanqueEnemigo::Inicializa() {
	posicion.x =  0.75;
	posicion.y = 0.0;
	apuntado.x = 1.0;
	apuntado.y = 0.0;
	vel = 0.01;
	proyectiles.setMunicion(30);//tiene que ser menor que MAX_POYECTILES
	color.set(76, 76, 95);
}