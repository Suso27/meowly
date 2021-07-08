#include "tanqueJugador.h"
#include "ETSIDI.h"
tanqueJugador::tanqueJugador():tanque(0.0f,0.0f,"imagenes/Jugador.png"){
	municion = 3;
	vel = 0.01f;
	color.set(132, 134, 59);//233,208,154
	vida = 3;
	vidaMax = 3;
	nMaxRebotes = 1;
	vProyectil = 3;
	daño = 1;
	tipo=0;
}

tanqueJugador::~tanqueJugador() {}

void tanqueJugador::Dispara() {
	switch (tipo) {
	case 0:
		if (municion >= proyectiles.getNum()) {
			Proyectil* d = new Proyectil(apuntado, posicion, daño, nMaxRebotes, vProyectil);
			proyectiles.agregar(d);
			ETSIDI::play("sonidos/sfx_wpn_laser7.wav");
		}
		break;
	case 1:
		if (municion >= proyectiles.getNum()) {
			ProyectilCañon* c = new ProyectilCañon(apuntado, posicion, daño, nMaxRebotes, vProyectil);
			proyectiles.agregar(c);
			ETSIDI::play("sonidos/sfx_wpn_laser9.wav");
		}
		break;
	case 2:
		if (municion >= proyectiles.getNum()) {
			ProyectilRicochet* r = new ProyectilRicochet(apuntado, posicion, daño, nMaxRebotes, vProyectil);
			proyectiles.agregar(r);
			ETSIDI::play("sonidos/sfx_wpn_laser6.wav");
		}
		break;
	default:
		if (municion >= proyectiles.getNum()) {
			Proyectil* d = new Proyectil(apuntado, posicion, daño, nMaxRebotes, vProyectil);
			proyectiles.agregar(d);
			ETSIDI::play("sonidos/sfx_wpn_laser8.wav");
		}
		break;
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
	tipo = 0;
}

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

void tanqueJugador::setTipoDisparo(int type)
{
	tipo = type;
}

int tanqueJugador::getTipoDisparo()
{
	return tipo;
}

int tanqueJugador::getMunicion()
{
	return municion;
}

void tanqueJugador::aumentarMunicion()
{
	++municion;
}