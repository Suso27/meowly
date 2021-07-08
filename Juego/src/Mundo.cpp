#include "Mundo.h"
#include <string>
using namespace std;

Mundo::Mundo(){}
Mundo::~Mundo() {
	objetos.destruirContenido();
}

void Mundo::dibuja()
{        
	tankJ.Dibuja();
	tanques.Dibuja();
	contenedor.Dibuja();
	cajas.Dibuja();
	objetos.Dibuja();

}

void Mundo::dibujaTexto(const char* string, float x, float y)
{
	
	const char* c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c);
	}

}

void Mundo::dibujaStats()
{
	int v = tankJ.getVidaActual();
	int m = tankJ.getMunicion();
	int d = tankJ.getDaño();
	float s = tankJ.getVel();
	int r = tankJ.getnMaxRebotes();
	int b = tankJ.getvProyectil();
	int t = tankJ.getTipoDisparo();
	std::string vs = std::to_string(v);
	std::string ms = std::to_string(m);
	std::string ds = std::to_string(d);
	std::string ss = std::to_string(s);
	std::string rs = std::to_string(r);
	std::string bs = std::to_string(b);
	const char* pcharv = vs.c_str();
	const char* pcharm = ms.c_str();
	const char* pchard = ds.c_str();
	const char* pchars = ss.c_str();
	const char* pcharr = rs.c_str();
	const char* pcharb = bs.c_str();
	dibujaTexto("hp:", -1.7, 1.1);
	dibujaTexto("ammo:", -1.7, 0.9);
	dibujaTexto("damage:", -1.7, 0.7);
	dibujaTexto("speed:", -1.7, 0.5);
	dibujaTexto("rebotes:", -1.7, 0.3);
	dibujaTexto("bullet speed:", -1.7, 0.1);
	dibujaTexto("tipo disparo:", -1.7, -0.1);
	dibujaTexto(pcharv , -1.7, 1);
	dibujaTexto(pcharm, -1.7, 0.8);
	dibujaTexto(pchard, -1.7, 0.6);
	dibujaTexto(pchars, -1.7, 0.4);
	dibujaTexto(pcharr, -1.7, 0.2);
	dibujaTexto(pcharb, -1.7, 0.0);
	switch (t)
	{
	case 0:
		dibujaTexto("normal", -1.7, -0.2);
		break;
	case 1:
		dibujaTexto("cannon", -1.7, -0.2);
		break;
	case 2:
		dibujaTexto("ricochet", -1.7, -0.2);
		break;
	}
}


 
void Mundo::mueve()
{
	tankJ.Mueve(0.025f);
	tankJ.setApuntado(raton.x, raton.y);
	tanques.Mueve(0.025f, tankJ.getPos());

	Interaccion::rebote(tankJ, cajas);
	Interaccion::rebote(tankJ, contenedor);
	Interaccion::rebote(tanques, cajas);
	Interaccion::rebote(tanques, contenedor);
	Interaccion::colision(objetos, tankJ);
	Interaccion::colision(tankJ, tanques);

	
}

void Mundo::inicializa()
{
	tankJ.Inicializa(0.0, 0.0);


}

void Mundo::tecla(unsigned char key)
{
	switch (key)
	{
	case GLUT_LEFT_BUTTON:
		tankJ.Dispara();
		break;
	}
	tankJ.mueveTecla(key);
}



void Mundo::teclaEspecial(unsigned char key)
{
	tankJ.mueveTecla(key);
}

void Mundo::setRaton(int x, int y) {
	raton.x = (x - ANCHO/2)/ESCALA;
	raton.y = (ALTO/2 - y) / ESCALA;

}

Vector2D Mundo::getRaton() {
	return raton;
}

float get_random_obj(double i, double j)
{
	/*static std::default_random_engine e;
	static std::uniform_real_distribution<> dis(i, j); // rage 0 - 1
	return dis(e);*/
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(i, j);
	return float(dist(rd));
}

void Mundo::crearObjeto() //se llama a esta funcion cada 10s desde principal.cpp
{
	int i = 0;
	int j = N_TIPOS_OBJETO;
	float x = get_random_obj(i, j);

	if (x < 1.0)
	{
		Corazon* aux = new Corazon;
		//aux->setRadio(0.75 + i * 0.25);
		objetos.agregar(aux); // agregar a la lista 
	}
	else if (x < 2.0)
	{
		DmgUp* aux = new DmgUp;
		//aux->setRadio(0.75 + i * 0.25);
		objetos.agregar(aux); // agregar a la lista 
	}
	else if (x < 3.0)
	{
		Botiquin* aux = new Botiquin;
		//aux->setRadio(0.75 + i * 0.25);
		objetos.agregar(aux); // agregar a la lista 
	}
	else if (x < 4.0)
	{
		BulletSpeedUp* aux = new BulletSpeedUp;
		objetos.agregar(aux); // agregar a la lista 
	}
	else if (x < 5.0)
	{
		RebotesUp* aux = new RebotesUp;
		objetos.agregar(aux); // agregar a la lista 
	}
	else if (x < 6.0)
	{
		SpeedUp* aux = new SpeedUp;
		objetos.agregar(aux); // agregar a la lista 
	}
	else if (x < 7.0)
	{
		ObjetoRicochet* aux = new ObjetoRicochet;
		objetos.agregar(aux); // agregar a la lista 
	}
	else if (x < 8.0)
	{
		ObjetoCañon* aux = new ObjetoCañon;
		objetos.agregar(aux); // agregar a la lista 
	}
	else
	{
		CajaMunicion* aux = new CajaMunicion;
		objetos.agregar(aux); // agregar a la lista 
	}
}

bool Mundo::getVida() {
	return tankJ.getVidaActual();
}

int Mundo::getNumTanques() {
	return tanques.getNumero();
}

bool Mundo::cargarNivel() {
	nivel++;

	objetos.destruirContenido();
	tanques.destruirContenido();
	cajas.destruirContenido();

	if (nivel == 1) {

		tankJ.Inicializa(-0.75f, 0.0f);
		tanques.agregar(new tanqueEnemigoA(1.0f, 0.0f));
		contenedor.Inicializa(4);
		cajas.Inicializa(1);
	}
	if (nivel == 2) {
		tankJ.Inicializa(-0.7f, 1.0f);
		tanques.agregar(new tanqueEnemigoA(1.0f, -1.0f));
		tanques.agregar(new tanqueEnemigoB(1.0f, 1.0f));
		contenedor.Inicializa(4);
		cajas.Inicializa(2);
	}
	if (nivel == 3) {
		tankJ.Inicializa(-1.4f, -0.8f);
		tanques.agregar(new tanqueEnemigoB(0.0f, 0.8f));
		tanques.agregar(new tanqueEnemigoA(0.0f, -0.8f));
		tanques.agregar(new tanqueEnemigoB(0.8f, -0.8f));
		tanques.agregar(new tanqueEnemigoB(0.8f, 0.8f));
		contenedor.Inicializa(4);
		cajas.Inicializa(3);
	}
	if (nivel <= 3)
		return true;
	return false;
}

void Mundo::reset() {

	nivel = 0;
	tankJ.Inicializa(-0.0f, 0.0f);
	objetos.destruirContenido();
	tanques.destruirContenido();
	cajas.destruirContenido();
	contenedor.destruirContenido();
}
	




