#include "tanque.h"

tanque::tanque() {
}

tanque::tanque(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}

void tanque::Dibuja() {

	//proyectil.dibuja();
	proyectiles.dibuja();
	//spriteTanque.draw();

	glBegin(GL_QUADS);              
      glColor3f(color.r/255.0f,color.g/255.0f, color.b/255.f);
	  glVertex2f(posicion.x - 0.05f, posicion.y - 0.05f);   
	  glVertex2f(posicion.x + 0.05f, posicion.y - 0.05f);
	  glVertex2f(posicion.x + 0.05f, posicion.y + 0.05f);
	  glVertex2f(posicion.x - 0.05f, posicion.y + 0.05f);
	glEnd();

	//Dibuja el ca?on, podr?amos hacer un clase para el ca?on
	glBegin(GL_LINES);
	glColor3f(0.2f, 0.278f, 0.274f);
	glVertex2d(posicion.x, posicion.y);
	glVertex2d(apuntado.x+posicion.x, apuntado.y+posicion.y);
	glEnd();

	//sprite

/*	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	//gestion de direccion y animacion
	spriteAnimacionTanque.draw();
	spriteTanque.draw();
	glPopMatrix();*/
	
}
void tanque::Mueve(float t) {
	proyectiles.mueve(t);
	/*spriteTanque.loop();
	spriteAnimacionTanque.loop();*/
}
void tanque::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}
void tanque::aumentarVel()
{
	velocidad.x += 0.03f;
	velocidad.y += 0.03f;
}


void tanque::setApuntado(float x, float y) {

	apuntado.x = x - posicion.x; 
	apuntado.y = y - posicion.y;
	apuntado = apuntado.unitario() * 0.2f;//0.2 es el tama?o del ca?on
}

void tanque::setApuntado(Vector2D v) {
	apuntado.x = v.x - posicion.x;
	apuntado.y = v.y - posicion.y;
	apuntado = apuntado.unitario() * 0.2f;//0.2 es el tama?o del ca?on
}


void tanque::Dispara() {

	Proyectil* d = new Proyectil(apuntado,posicion,da?o,nMaxRebotes,vProyectil);
	proyectiles.agregar(d);
}

Vector2D tanque::getPos() {
	return posicion;
}

void tanque::setPos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}

void tanque::setDa?o(int dmg)
{
	da?o = dmg;
}

void tanque::setVidaMax(int vida)
{
	vidaMax = vida;
}

int tanque::getVidaMax()
{
	return vidaMax;
}

void tanque::aumentarVidaMax()
{
	++vidaMax;
}

void tanque::aumentarVida()
{
	if (vida<vidaMax)
		++vida;
}

void tanque::aumentarDa?o()
{
	++da?o;
}

float tanque::getvProyectil()
{
	return vProyectil;
}

void tanque::setvProyectil(float vel)
{
	vProyectil = vel;
}
void tanque::aumentarVproyectil(int v) {
	vProyectil += v;
}

int tanque::getVidaActual()
{
	return vida;
}



int tanque::getnMaxRebotes()
{
	return nMaxRebotes;
}

void tanque::aumentarnMaxRebotes()
{
	if (nMaxRebotes < 6)
		++nMaxRebotes;
}

