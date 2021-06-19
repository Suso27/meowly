#include "Pared.h"

Pared::Pared():limite1(0.0f,0.0f),limite2(0.0f, 0.0f){
	color.set(255, 255, 255);
};
Pared::~Pared() {};

void Pared::Dibuja() const
{
	glBegin(GL_LINES);
	glColor3f(0.2f, 0.278f, 0.274f);
	glVertex2d(limite1.x,limite1.y);
	glVertex2d(limite2.x, limite2.y);
	glEnd();
}

void Pared::setPos(float l1x, float l1y, float l2x, float l2y) {
	limite1.x = l1x;
	limite1.y = l1y;
	limite2.x = l2x;
	limite2.y = l2y;
}

void Pared::setColor(char r, char v, char a) {
	color.set(r, v, a);
}

float Pared::distancia(Vector2D punto, Vector2D* direccion)
{
	Vector2D u = (punto - limite1);
	Vector2D v = (limite2 - limite1).unitario();
	float longitud = (limite1 - limite2).modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;
	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limite2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0) //si nos dan un vector…
		*direccion = dir.unitario();
	return distancia;
}