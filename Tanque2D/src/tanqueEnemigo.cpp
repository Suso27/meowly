#include "tanqueEnemigo.h"


tanqueEnemigo::tanqueEnemigo(){}

tanqueEnemigo::tanqueEnemigo(float x, float y):tanque(x,y) {}

tanqueEnemigo::~tanqueEnemigo() {}

void tanqueEnemigo::Mueve(float t,Vector2D posJ) {
	if (tRecarga > cadencia) {
		tanque::Dispara();
		tRecarga = 0;
	}
	else tRecarga += t;

	if (posicion.x > 1.0f)posicion.x = 1.0f;
	if (posicion.x < -1.0f)posicion.x = -1.0f;

	setApuntado(posJ);

    velocidad = posJ - posicion;
	velocidad = velocidad.unitario()* vel;

	//if(t)

	if ((posJ - posicion).modulo() > 0.9) {
		posicion = posicion + velocidad;
	}
	proyectiles.mueve(t);
}

void tanqueEnemigo::obstaculos() {

}
