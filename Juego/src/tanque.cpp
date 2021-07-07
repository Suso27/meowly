#include "tanque.h"

tanque::tanque():s("imagenes/Jugador.png"){
}

tanque::tanque(float x, float y, const char* s) {

	posicion.x = x;
	posicion.y = y;
	velocidad.x = 1.0f;
	velocidad.y = 0.0f;

	vel = 0.04f;
	vida = 1;
	vidaMax = 10;
	cadencia = 1.0f;//periodo con el que dispara
	tRecarga = 0.0f;//tiempo que ha pasado desde el último disparo
	this->s = s;

	daño = 1;
	nMaxRebotes = 2;
    vProyectil = 3;
}

void tanque::Dibuja() const{

	//proyectil.dibuja();
	proyectiles.dibuja();


	//Dibuja el cañon
	glBegin(GL_LINES);
	glColor3f(0.2f, 0.278f, 0.274f);
	glVertex2d(posicion.x, posicion.y);
	glVertex2d(apuntado.x + posicion.x, apuntado.y + posicion.y);
	glEnd();

	Vector2D aux(-velocidad.x + velocidad.y,velocidad.x + velocidad.y);
	aux = aux.unitario();
	aux *= 0.08f;//0.08 tamaño del tanque


	//Dibuja el tanque
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(s).id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex2f(posicion.x + aux.x, posicion.y - aux.y);
	glTexCoord2d(0, 1); glVertex2f(posicion.x + aux.y, posicion.y + aux.x);
	glTexCoord2d(1, 1); glVertex2f(posicion.x - aux.x, posicion.y + aux.y);
	glTexCoord2d(1, 0); glVertex2f(posicion.x - aux.y, posicion.y - aux.x);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	/*glTexCoord2d(0, 0); glVertex2f(posicion.x - 0.06f, posicion.y + 0.06f);
	glTexCoord2d(0, 1); glVertex2f(posicion.x - 0.06f, posicion.y - 0.06f);
	glTexCoord2d(1, 1); glVertex2f(posicion.x + 0.06f, posicion.y - 0.06f);
	glTexCoord2d(1, 0); glVertex2f(posicion.x + 0.06f, posicion.y + 0.06f);*/

}

void tanque::Mueve(float t) {
	proyectiles.mueve(t);
}
void tanque::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void tanque::aumentarVel()
{
	vel += 0.005f;
}
float tanque::getVel() {
	
	return vel;
}

void tanque::setApuntado(float x, float y) {

	apuntado.x = x - posicion.x; 
	apuntado.y = y - posicion.y;
	apuntado = apuntado.unitario() * 0.2f;//0.2 es el tamaño del cañon
}

void tanque::setApuntado(Vector2D v) {
	apuntado.x = v.x - posicion.x;
	apuntado.y = v.y - posicion.y;
	apuntado = apuntado.unitario() * 0.2f;//0.2 es el tamaño del cañon
}


void tanque::Dispara() {

	Proyectil* d = new Proyectil(apuntado,posicion,daño,nMaxRebotes,vProyectil);
	proyectiles.agregar(d);
}

Vector2D tanque::getPos() const{
	return posicion;
}

void tanque::setPos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}

void tanque::setDaño(int dmg)
{
	daño = dmg;
}

void tanque::setVidaMax(int vida)
{
	vidaMax = vida;
}

int tanque::getVidaMax() const
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

void tanque::aumentarDaño()
{
	++daño;
}

int tanque::getDaño()
{
	return daño;
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

int tanque::getVidaActual() const
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

