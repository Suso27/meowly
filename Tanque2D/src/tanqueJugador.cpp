#include "tanqueJugador.h"
#include"freeglut.h"

tanqueJugador::tanqueJugador(){}

void tanqueJugador::Inicializa() {
	posicion.x = -0.75;
	posicion.y = 0.0;
	vel = 0.01f;
	proyectiles.setMunicion(30);//tiene que ser menor que MAX_POYECTILES
	color.set(132, 134, 59);//233,208,154
	vida = 3;
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

