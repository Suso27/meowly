#include "tanqueJugador.h"

tanqueJugador::tanqueJugador(){}

tanqueJugador::~tanqueJugador() {}

void tanqueJugador::Dispara() {

	switch (tipo) {
		case 0:
			if (municion >= proyectiles.getNum()) {
				Proyectil* d = new Proyectil(apuntado, posicion, da�o, nMaxRebotes, vProyectil);
				proyectiles.agregar(d);
			}
		break;
		case 1:
			if (municion >= proyectiles.getNum()) {
				ProyectilCa�on* c = new ProyectilCa�on(apuntado, posicion, da�o, nMaxRebotes, vProyectil);
				proyectiles.agregar(c);
			}
		break;
		case 2:
			if (municion >= proyectiles.getNum()) {
				ProyectilRicochet* r = new ProyectilRicochet(apuntado, posicion, da�o, nMaxRebotes, vProyectil);
				proyectiles.agregar(r);
			}
		break;
		default:
			if (municion >= proyectiles.getNum()) {
				Proyectil* d = new Proyectil(apuntado, posicion, da�o, nMaxRebotes, vProyectil);
				proyectiles.agregar(d);
			}
		break;
	}
}

void tanqueJugador::Inicializa(float x,float y) {
	posicion.x = x;
	posicion.y = y;
	vel = 0.01f;
	color.set(132, 134, 59);//233,208,154
	vida = 3;
	vidaMax = 3;
	nMaxRebotes = 1;
	vProyectil = 3;
	da�o = 1;
	proyectiles.destruirContenido();
	municion = 2;
	tipo = 0;
}


//alternativa para mover el tanque
void tanqueJugador::mueveTecla(unsigned char key) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		posicion.x -= vel;
		break;
	case GLUT_KEY_RIGHT:
		posicion.x += vel;
		break;
	case GLUT_KEY_UP:
		posicion.y += vel;
		break;
	case GLUT_KEY_DOWN:
		posicion.y -= vel;
		break;
	}
}
//habr�a que lograr que se moviese en diagonales tambi�n

void tanqueJugador::setTipoDisparo(int type)
{
	tipo = type;
}

int tanqueJugador::getMunicion()
{
	return municion;
}

void tanqueJugador::aumentarMunicion()
{
	++municion;
}
