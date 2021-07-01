#include "tanqueJugador.h"
#include"freeglut.h"

tanqueJugador::tanqueJugador(){}

void tanqueJugador::Inicializa(float x,float y) {
	posicion.x = x;
	posicion.y = y;
	vel = 0.01f;
	proyectiles.setMunicion(30);//tiene que ser menor que MAX_POYECTILES
	color.set(132, 134, 59);//233,208,154
	vida = 3;
	nMaxRebotes = 3;
	vProyectil = 5;
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

