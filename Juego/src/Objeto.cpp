#include "Objeto.h"
#include <cstdlib>
#include "Caja.h"
#include <random>

Vector2D Objeto::getPos() {
	return posicion;
}
float Objeto::get_random(double i, double j)
{
	/*static std::default_random_engine e;
	static std::uniform_real_distribution<> dis(i, j); // rage 0 - 1
	return dis(e);*/
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(i, j);
	return float(dist(rd));
}


Objeto::Objeto() {
	int LO = -9.9; //serian todos 10, un poco menos para evitar las paredes de la caja
	int HI = 9.9;
	posicion.x = 0.1 * (get_random(LO, HI));
	posicion.y = 0.1 * (get_random(LO, HI));

	//sprite
	spriteObjeto = { "imagenes/Ammo.png" };
	spriteObjeto.setCenter(0, 0);
	spriteObjeto.setSize(0.1, 0.1);
}


void Objeto::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	//gestion de direccion y animacion
	spriteObjeto.draw();
	glPopMatrix();

}

float Objeto::distancia(Vector2D punto) { //para la interaccion con tanque jugador
	float delta_x = posicion.x - punto.x;
	float delta_y = posicion.y - punto.y;
	float norma = delta_x * delta_x + delta_y * delta_y;
	float dist = sqrt(norma);
	return dist;

}