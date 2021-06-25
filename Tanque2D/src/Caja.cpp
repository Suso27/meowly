#include "Caja.h"

Caja::Caja(){};

Caja::Caja(float l1x, float l1y, float l2x, float l2y) {

	limite1.x = l1x;
	limite1.y = l1y;
	limite2.x = l2x;
	limite2.y = l2y;

	pared_arib.setPos(l1x, l1y, l2x, l1y);
	pared_abj.setPos(l1x, l2y, l2x, l2y);
	pared_dcha.setPos(l1x, l1y, l1x, l2y);
	pared_izq.setPos(l2x, l1y, l2x, l2y);
};
Caja::~Caja() {};

void Caja::Inicializa(float l1x, float l1y, float l2x, float l2y) {

	limite1.x = l1x;
	limite1.y = l1y;
	limite2.x = l2x;
	limite2.y = l2y;

	pared_arib.setPos(l1x, l1y, l2x, l1y);
	pared_abj.setPos(l1x, l2y, l2x, l2y);
	pared_dcha.setPos(l1x, l1y, l1x, l2y);
	pared_izq.setPos(l2x, l1y, l2x, l2y);
};

void Caja::Dibuja(){

	glBegin(GL_QUADS);
	glColor3f(76/255.0f,76/255.0f,65/255.0f);

	glVertex2f(limite1.x, limite1.y);
	glVertex2f(limite2.x, limite1.y);
	glVertex2f(limite2.x, limite2.y);
	glVertex2f(limite1.x, limite2.y);

	//glVertex2f(- 0.05f, - 0.05f);
	//glVertex2f(+ 0.05f, - 0.05f);
	//glVertex2f(+ 0.05f, + 0.05f);
	//glVertex2f(- 0.05f, + 0.05f);

	//glVertex2f(limite2.y, limite1.x);
	//glVertex2f(limite2.x, limite2.y);
	//glVertex2f(limite1.x, limite2.y);
	//glVertex2f(limite1.x, limite1.y);


	glEnd();
}

Vector2D Caja::GetLim(int i) {
	if (i == 1) return limite1;
	if (i == 2) return limite2;

}