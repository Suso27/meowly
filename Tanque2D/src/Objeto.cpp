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
	return dist(rd);
}
Objeto::Objeto() {
	int LO  = -9.9; //serian todos 10, un poco menos para evitar las paredes de la caja
	int HI  = 9.9;
	posicion.x = 0.1 * (get_random(LO, HI));
	posicion.y = 0.1 * (get_random(LO, HI));

	
}


void Objeto::dibuja() {
	glBegin(GL_QUADS);
	glColor3f(color.r , color.g , color.b ); /// 255.f
	glVertex2f(posicion.x - 0.02f, posicion.y - 0.02f);
	glVertex2f(posicion.x + 0.02f, posicion.y - 0.02f);
	glVertex2f(posicion.x + 0.02f, posicion.y + 0.02f);
	glVertex2f(posicion.x - 0.02f, posicion.y + 0.02f);
	glEnd();
}

float Objeto::distancia(Vector2D punto) { //para la interaccion con tanque jugador
	float delta_x = posicion.x - punto.x;
	float delta_y = posicion.y - punto.y;
	float norma = delta_x * delta_x + delta_y * delta_y;
	float dist = sqrt(norma);
	return dist;

}