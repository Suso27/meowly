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

void Caja::Dibuja() const{

	glBegin(GL_QUADS);
	glColor3f(76/255.0f,76/255.0f,65/255.0f);

	glVertex2f(limite1.x, limite1.y);
	glVertex2f(limite2.x, limite1.y);
	glVertex2f(limite2.x, limite2.y);
	glVertex2f(limite1.x, limite2.y);

	glEnd();


	////dibujo del fondo
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tank.png").id);
	//glDisable(GL_LIGHTING);
	//glBegin(GL_POLYGON);
	//glColor3f(1, 1, 1);
	//glTexCoord2d(0, 1); glVertex2f(limite1.x, limite2.x);
	//glTexCoord2d(1, 1); glVertex2f(limite2.x, limite2.y);
	//glTexCoord2d(1, 0); glVertex2f(limite2.x, limite1.y);
	//glTexCoord2d(0, 0); glVertex2f(limite1.x, limite1.y);
	////glTexCoord2d(0, 1); glVertex2f(-1, 0);
	////glTexCoord2d(1, 1); glVertex2f(1, 0);
	////glTexCoord2d(1, 0); glVertex2f(1, 1);
	////glTexCoord2d(0, 0); glVertex2f(-1, 1);
	//glEnd();
	//glEnable(GL_LIGHTING);
	//glDisable(GL_TEXTURE_2D);
}

