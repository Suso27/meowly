#include "Objeto.h"
#include <cstdlib>
#include "Caja.h"
#include <random>

Vector2D Objeto::getPos() {
	return posicion;
}
float get_random(double i, double j) 
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
	int LO_x = -9.9; //serian todos 10, un poco menos para evitar las paredes de la caja
	int HI_x = 9.9;
	int LO_y = -9.9;
	int HI_y = 9.9;
	/*srand(static_cast <unsigned> (time(0))); //seed para generar numero aleatorio, ejecutar 1 vez por run
	posicion.x=0.01*(LO_x + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI_x - LO_x))));
	
	posicion.y=0.1*(LO_y + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI_y - LO_y))));*/
	posicion.x = 0.1 * (get_random(LO_x, HI_x));
	posicion.y = 0.1 * (get_random(LO_y, HI_y));

	color.r = color.g = color.b = 250;
}


void Objeto::dibuja() {
	glBegin(GL_QUADS);
	glColor3f(color.r / 255.0f, color.g / 255.0f, color.b / 255.f);
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