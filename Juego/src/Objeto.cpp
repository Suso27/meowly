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
Objeto::Objeto(const char* s){
	float LO  = -9.9f; //serian todos 10, un poco menos para evitar las paredes de la caja
	float HI  = 9.9f;
	posicion.x = 0.1f * (get_random(LO, HI));
	posicion.y = 0.1f * (get_random(LO, HI));

	this->s = s;
}

Objeto::Objeto() :s("imagenes/cora.png") {
}


void Objeto::dibuja() {
	/*glBegin(GL_QUADS);
	glColor3f(color.r , color.g , color.b ); /// 255.f
	glVertex2f(posicion.x - 0.02f, posicion.y - 0.02f);
	glVertex2f(posicion.x + 0.02f, posicion.y - 0.02f);
	glVertex2f(posicion.x + 0.02f, posicion.y + 0.02f);
	glVertex2f(posicion.x - 0.02f, posicion.y + 0.02f);
	glEnd();*/



	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(s).id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex2f(posicion.x - 0.05f, posicion.y + 0.05f);
	glTexCoord2d(0, 1); glVertex2f(posicion.x - 0.05f, posicion.y - 0.05f);
	glTexCoord2d(1, 1); glVertex2f(posicion.x + 0.05f, posicion.y - 0.05f);
	glTexCoord2d(1, 0); glVertex2f(posicion.x + 0.05f, posicion.y + 0.05f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}

float Objeto::distancia(Vector2D punto) { //para la interaccion con tanque jugador
	float delta_x = posicion.x - punto.x;
	float delta_y = posicion.y - punto.y;
	float norma = delta_x * delta_x + delta_y * delta_y;
	float dist = sqrt(norma);
	return dist;

}