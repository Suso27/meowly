#include "Proyectil.h"
#define PI 3.1415

Proyectil::Proyectil():radio(0),rebotes(0){
	
}

Proyectil::Proyectil(Proyectil* p) {
	rebotes = p->rebotes;
	nMaxRebotes = p->nMaxRebotes;
	da�o = p->da�o;
	posicion = p->posicion;
	velocidad = p->velocidad;
	radio = p->radio;
}


Proyectil::Proyectil(Vector2D vel, Vector2D pos,int d,int n,float velModulo) {
	rebotes = 0;
	nMaxRebotes = n;
	da�o = d;
	posicion = pos;
	velocidad = vel * velModulo;
	radio = 0.01f;
};

//Proyectil::Proyectil(Vector2D vel, Vector2D pos) {
//	rebotes = 0;
//	posicion = pos;
//	velocidad = vel*3;
//	radio = 0.01f;
//};
Proyectil::~Proyectil() {};

void Proyectil::dibuja() const
{

	glTranslatef(posicion.x, posicion.y, 0.0f);  // Translate to (xPos, yPos)
   // Use triangular segments to form a circle
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.2f, 0.2f, 0.2f);  // Blue
	glVertex2f(0.0f, 0.0f);       // Center of circle
	int numSegments = 50;
	GLfloat angle;
	for (int i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
		angle = i * 2.0f * (float)PI / numSegments;  // 360 deg for all segments
		glVertex2f((float)cos(angle) * radio, (float)sin(angle) * radio);
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

void Proyectil::setDa�o(int dmg) {
	//da�o = dmg;
}

Vector2D Proyectil::getPos() const{
	return posicion;
}

float Proyectil::getRadio()
{
	return radio;
}
