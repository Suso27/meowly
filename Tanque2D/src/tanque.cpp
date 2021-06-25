#include "tanque.h"
#include"freeglut.h"


void tanque::Inicializa() {
	posicion = 0;
	vel = 0.01f;
	proyectiles.setMunicion(30);//tiene que ser menor que MAX_POYECTILES
	color.set(255, 255, 255);
}



tanque::tanque() {
	Inicializa();
}

void tanque::Dibuja() {

	//proyectil.dibuja();
	proyectiles.dibuja();


	glBegin(GL_QUADS);              
      glColor3f(color.r/255.0f,color.g/255.0f, color.b/255.f);
	  glVertex2f(posicion.x - 0.05f, posicion.y - 0.05f);   
	  glVertex2f(posicion.x + 0.05f, posicion.y - 0.05f);
	  glVertex2f(posicion.x + 0.05f, posicion.y + 0.05f);
	  glVertex2f(posicion.x - 0.05f, posicion.y + 0.05f);
	glEnd();

	//Dibuja el cañon, podríamos hacer un clase para el cañon
	glBegin(GL_LINES);
	glColor3f(0.2f, 0.278f, 0.274f);
	glVertex2d(posicion.x, posicion.y);
	glVertex2d(apuntado.x+posicion.x, apuntado.y+posicion.y);
	glEnd();


}
void tanque::Mueve(float t) {


	/*posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;*/
	//NO es la forma adecuada de resolverlo
	if (posicion.x > 1.0f)posicion.x = 1.0f;
	if (posicion.x < -1.0f)posicion.x = -1.0f;
	proyectiles.mueve(t);
}
void tanque::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void tanque::setApuntado(float x, float y) {

	apuntado.x = x - posicion.x;  //Generalizar para distintas dimensiones
	apuntado.y = y - posicion.y;
	apuntado = apuntado.unitario() * 0.2;//0.2 es el tamaño del cañon
}

void tanque::setApuntado(Vector2D v) {
	apuntado.x = v.x - posicion.x;  //Generalizar para distintas dimensiones
	apuntado.y = v.y - posicion.y;
	apuntado = apuntado.unitario() * 0.2f;//0.2 es el tamaño del cañon
}


void tanque::Dispara() {
	Proyectil* d = new Proyectil(apuntado,posicion);
	proyectiles.agregar(d);
}

Vector2D tanque::getPos() {
	return posicion;
}

void tanque::setDaño(int dmg)
{
	proyectiles.setDaño(dmg);
}

