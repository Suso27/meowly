#include "Proyectil.h"
#include "freeglut.h"
#include <math.h>
#define PI 3.1415

Proyectil::Proyectil(){}

Proyectil::Proyectil(Vector2D vel, Vector2D pos) {
	posicion = pos;
	velocidad = vel*3;
	radio = 0.01;
};
Proyectil::~Proyectil() {};

void Proyectil::dibuja()
{

	glTranslatef(posicion.x, posicion.y, 0.0f);  // Translate to (xPos, yPos)
   // Use triangular segments to form a circle
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.2, 0.2f, 0.2f);  // Blue
	glVertex2f(0.0f, 0.0f);       // Center of circle
	int numSegments = 50;
	GLfloat angle;
	for (int i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
		angle = i * 2.0f * PI / numSegments;  // 360 deg for all segments
		glVertex2f(cos(angle) * radio, sin(angle) * radio);
	}
	glEnd();
	glTranslatef(-posicion.x, -posicion.y, 0.0f);



}

void Proyectil::mueve(float t) {
	posicion = posicion + velocidad*t;
}

//void Proyectil::setVel(Vector2D apuntando) {
//	velocidad = apuntando*3;//3 es la velocidad, crear atributo
//	//disparado = true;
//}

void Proyectil::setPos(Vector2D tpos) {
	posicion = tpos;
}

//bool Proyectil::getDisparado() {
//	return disparado;
//}
