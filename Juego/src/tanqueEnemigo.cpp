#include "tanqueEnemigo.h"


tanqueEnemigo::tanqueEnemigo(){}

tanqueEnemigo::tanqueEnemigo(float x, float y,const char* s):tanque(x,y,s) {}

tanqueEnemigo::~tanqueEnemigo() {}

void tanqueEnemigo::Mueve(float t,Vector2D posJ) {
	if (tRecarga > cadencia) {
		tanque::Dispara();
		tRecarga = 0;
		ETSIDI::play("sonidos/sfx_wpn_laser8.wav");
	}
	else tRecarga += t;

	setApuntado(posJ);

    velocidad = posJ - posicion;
	velocidad = velocidad.unitario()* vel;

	//if(t)

	if ((posJ - posicion).modulo() > 0.9) {
		posicion = posicion + velocidad;
	}
	proyectiles.mueve(t);
}
