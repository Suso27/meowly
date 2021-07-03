#include "Mundo.h"
#include "freeglut.h"
#include "Interaccion.h"
#include <math.h>
#include "Botiquin.h"
#include "Corazon.h"
#include "Filete.h"
#include <random>

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
	if (aux != 0)//si hay colision entre el objeto y el tanque
	{
		aux->aplicarEfecto(tankJ);
		objetos.eliminar(aux);
		
	}
	
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

float get_random_obj(double i, double j)
{
	/*static std::default_random_engine e;
	static std::uniform_real_distribution<> dis(i, j); // rage 0 - 1
	return dis(e);*/
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(i, j);
	return dist(rd);
}

void Mundo::crearObjeto() //se llama a esta funcion cada 10s desde principal.cpp
{
	int i = 0;
	int j = 3;
	float x = get_random_obj(i, j);
	
	if (x<1.0)
		{Corazon* aux = new Corazon;
		//aux->setRadio(0.75 + i * 0.25);
		objetos.agregar(aux); // agregar a la lista 
		}
	else if (x<2.0)
		{Filete* aux = new Filete;
		//aux->setRadio(0.75 + i * 0.25);
		objetos.agregar(aux); // agregar a la lista 
		}
	else
		{Botiquin* aux = new Botiquin;
		//aux->setRadio(0.75 + i * 0.25);
		objetos.agregar(aux); // agregar a la lista 
		}
	}
	




