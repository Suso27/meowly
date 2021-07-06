#include "tanqueJugador.h"

tanqueJugador::tanqueJugador(){
	
}

tanqueJugador::~tanqueJugador() {}

void tanqueJugador::Dispara() {
	switch (tipo) {
		case 0:
			if (municion >= proyectiles.getNum()) {
				Proyectil* d = new Proyectil(apuntado, posicion, daño, nMaxRebotes, vProyectil);
				proyectiles.agregar(d);
			}
		break;
		case 1:
			if (municion >= proyectiles.getNum()) {
				ProyectilCañon* c = new ProyectilCañon(apuntado, posicion, daño, nMaxRebotes, vProyectil);
				proyectiles.agregar(c);
			}
		break;
		case 2:
			if (municion >= proyectiles.getNum()) {
				ProyectilRicochet* r = new ProyectilRicochet(apuntado, posicion, daño, nMaxRebotes, vProyectil);
				proyectiles.agregar(r);
			}
		break;
		default:
			if (municion >= proyectiles.getNum()) {
				Proyectil* d = new Proyectil(apuntado, posicion, daño, nMaxRebotes, vProyectil);
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
	daño = 1;
	proyectiles.destruirContenido();
	municion = 2;
	tipo = 0;

	/*spriteTanque = { "imagenes/Purple/Bodies/body_halftrack.png", 2 };
	spriteAnimacionTanque = { "imagenes/Purple/Weapons/turret_01_mk1.png", 8 };
	//sprite
	spriteTanque.setCenter(0.2, 0.2);
	spriteTanque.setSize(0.4, 0.4);
	spriteAnimacionTanque.setCenter(0.2, 0.2);
	spriteAnimacionTanque.setSize(0.4, 0.4);
	spriteAnimacionTanque.setState(0, false);
	spriteTanque.setState(0, false);*/
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
//habría que lograr que se moviese en diagonales también

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
