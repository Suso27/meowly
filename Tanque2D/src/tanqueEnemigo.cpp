#include "tanqueEnemigo.h"


tanqueEnemigo::tanqueEnemigo(){
	Inicializa();
}

void tanqueEnemigo::Inicializa() {
	posicion.x =  0.75;
	posicion.y = 0.0;
	apuntado.x = 1.0;
	apuntado.y = 0.0;
	velocidad.x = 0.0;
	velocidad.y = 0.0;
	vel = 0.004f;
	proyectiles.setMunicion(30);//tiene que ser menor que MAX_POYECTILES
	color.set(76, 76, 95);
	vida = 1;
}

void tanqueEnemigo::Mueve(float t,Vector2D posJ) {
	static float T = 0;
	if (T > 4) {
		tanque::Dispara();
		T = 0;
	}
	else T += t;

	if (posicion.x > 1.0f)posicion.x = 1.0f;
	if (posicion.x < -1.0f)posicion.x = -1.0f;

	setApuntado(posJ);

    velocidad = posJ - posicion;
	velocidad = velocidad.unitario()* vel;

	//if(t)

	if ((posJ - posicion).modulo() > 0.6) {
		posicion = posicion + velocidad;
	}
	proyectiles.mueve(t);
}

void tanqueEnemigo::obstaculos() {

}
