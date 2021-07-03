#include "Mundo.h"
#include "Interaccion.h"
#include <math.h>
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

void Mundo::mueve()
{
	tankJ.Mueve(0.025f);
	tankJ.setApuntado(raton.x, raton.y);
	tanques.Mueve(0.025f, tankJ.getPos());
	for (int i = 0; i < contenedor.getNumero(); i++) {//Hay que hacer interacciones entre listaCajas y tanque

		Interaccion::rebote(tankJ, *contenedor[i]);
		for (int j = 0; j < tanques.getNumero(); j++) {
			Interaccion::rebote(*tanques[j], *contenedor[i]);
		}

	}

	for (int i = 0; i < cajas.getNumero(); i++) {

		Interaccion::rebote(tankJ, *cajas[i]);
		for (int j = 0; j < tanques.getNumero(); j++) {
			Interaccion::rebote(*tanques[j], *cajas[i]);
		}
	}

	Objeto* aux = objetos.colision(tankJ);
	if (aux != 0)//si alguna esfera ha chocado
		objetos.eliminar(aux);
}

void Mundo::inicializa()
{
	tankJ.Inicializa(0.0,0.0);
}

void Mundo::tecla(unsigned char key)
{
	switch (key)
	{
	case GLUT_LEFT_BUTTON:
		tankJ.Dispara();
		break;
	}
}

void Mundo::teclaEspecial(unsigned char key)
{
	tankJ.mueveTecla(key); //Alternativa para mover el tanque
	//switch (key)
	//{
	//case GLUT_KEY_LEFT:
	//	tank.setVel(-5.0f, 0.0f);
	//	break;
	//case GLUT_KEY_RIGHT:
	//	tank.setVel(5.0f, 0.0f);
	//	break;
	//case GLUT_KEY_UP:
	//	tank.setVel(0.0f, 5.0f);
	//	break;
	//case GLUT_KEY_DOWN:
	//	tank.setVel(0.0f, -5.0f);
	//	break;
	//case GLUT_KEY_F1:
	//	tank.setVel(0.0f, 0.0f);
	//	break;
 //   }


}

void Mundo::setRaton(int x, int y) {
	raton.x = (x - ANCHO/2)/ESCALA;
	raton.y = (ALTO/2 - y) / ESCALA;

}

void Mundo::crearObjeto() //se llama a esta funcion cada 10s desde principal.cpp
{
	//for (int i = 0; i < 6; i++) //para probar la generacion de objetos
	//{
		Objeto* aux = new Objeto;
		//aux->setRadio(0.75 + i * 0.25);
		objetos.agregar(aux); // agregar a la lista 
	//}
}

bool Mundo::getImpacto(){
	return impacto;
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

		tankJ.Inicializa(-0.75, 0.0);
		tanques.agregar(new tanqueEnemigoA(1.7f, 0.0f));
		contenedor.Inicializa(4);
		cajas.Inicializa(1);
	}
	if (nivel == 2) {
		tankJ.Inicializa(-0.7, 1.0);
		tanques.agregar(new tanqueEnemigoA(1.7f, -1.0f));
		tanques.agregar(new tanqueEnemigoB(1.7f, 1.0f));
		contenedor.Inicializa(4);
		cajas.Inicializa(2);
	}
	if (nivel == 3) {
		tankJ.Inicializa(-1.4, -0.8);
		tanques.agregar(new tanqueEnemigoB(0.0f, 0.8f));
		tanques.agregar(new tanqueEnemigoB(0.0f, -0.8f));
		tanques.agregar(new tanqueEnemigoB(0.8f, -0.8f));
		tanques.agregar(new tanqueEnemigoA(0.8f, 0.8f));
		contenedor.Inicializa(4);
		cajas.Inicializa(3);
	}
	if (nivel <= 3)
		return true;
	return false;
}


