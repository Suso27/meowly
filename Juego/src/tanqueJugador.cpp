#include "tanqueJugador.h"

tanqueJugador::tanqueJugador():tanque(0.0f,0.0f,"imagenes/Jugador.png"){
	municion = 3;
	vel = 0.01f;
	color.set(132, 134, 59);//233,208,154
	vida = 3;
	vidaMax = 3;
	nMaxRebotes = 2;
	vProyectil = 3;
	daño = 1;
	municion = 2;
}

tanqueJugador::~tanqueJugador() {}

void tanqueJugador::Dispara() {
	if (municion >= proyectiles.getNum()) {
		Proyectil* d = new Proyectil(apuntado, posicion, daño, nMaxRebotes, vProyectil);
		proyectiles.agregar(d);
	}
}

void tanqueJugador::Inicializa(float x,float y) {
	posicion.x = x;
	posicion.y = y;
	proyectiles.destruirContenido();
}

void tanqueJugador::Reset() {
	posicion.x = 0.0f;
	posicion.y = 0.0f;
	proyectiles.destruirContenido();
	municion = 3;
	vel = 0.01f;
	vida = 3;
	vidaMax = 3;
	nMaxRebotes = 2;
	vProyectil = 3;
	daño = 1;
	municion = 2;
}


//void tanqueJugador::mueveTecla(unsigned char key) {
//	switch (key)
//	{
//	case GLUT_KEY_LEFT:
//		posicion.x -= vel;
//		break;
//	case GLUT_KEY_RIGHT:
//		posicion.x += vel;
//		break;
//	case GLUT_KEY_UP:
//		posicion.y += vel;
//		break;
//	case GLUT_KEY_DOWN:
//		posicion.y -= vel;
//		break;
//	}
//}

void tanqueJugador::mueveTecla(unsigned char key) {
	switch (key)
	{
	case 'a':
		posicion.x -= vel;
		velocidad = { 1.0f,0.0f };
		break;
	case 'd':
		posicion.x += vel;
		velocidad = { 1.0f,0.0f };
		break;
	case 'w':
		posicion.y += vel;
		velocidad = { 0.0f,1.0f };
		break;
	case 's':
		posicion.y -= vel;
		velocidad = { 0.0f,1.0f };
		break;
	}
}
//habría que lograr que se moviese en diagonales también

