#include "Mundo.h"
#include "freeglut.h"
#include "Interaccion.h"
#include <math.h>

Mundo::Mundo(){}
Mundo::~Mundo() {
	objetos.destruirContenido();
}

void Mundo::dibuja()
{        
	tankJ.Dibuja();
	tankEA.Dibuja();
	tankEB.Dibuja();
	//caja.Dibuja();
	contenedor.Dibuja();
	cajas.Dibuja();
	objetos.Dibuja();
}

void Mundo::mueve()
{
	tankJ.Mueve(0.025f);
	tankJ.setApuntado(raton.x, raton.y);
	tankEA.Mueve(0.025f, tankJ.getPos());
	tankEB.Mueve(0.025f, tankJ.getPos());
    //Interaccion::rebote(tankJ, caja);
	for (int i = 0; i < contenedor.getNumero(); i++) {
		Interaccion::rebote(tankJ, *contenedor[i]);
		Interaccion::rebote(tankEA, *contenedor[i]);
		Interaccion::rebote(tankEB, *contenedor[i]);
	}

	for (int i = 0; i < cajas.getNumero(); i++) {
		Interaccion::rebote(tankJ, *cajas[i]);
		Interaccion::rebote(tankEA, *cajas[i]);
		Interaccion::rebote(tankEB, *cajas[i]);
	}

	Objeto* aux = objetos.colision(tankJ);
	if (aux != 0)//si alguna esfera ha chocado
		objetos.eliminar(aux);
}

void Mundo::inicializa()
{
	tankJ.Inicializa(-0.75,0.0);
	tankEA.Inicializa(1.7,-1.0);
	tankEB.Inicializa(1.7, 0.0);
	//caja.Inicializa(-0.04f, 0.2f, 0.04f,-0.2f);
	contenedor.Inicializa(4);
	cajas.Inicializa(2);


	
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



