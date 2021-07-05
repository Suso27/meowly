#include "Coordinador.h"

Coordinador::Coordinador()
{
	estado = INICIO;
}
Coordinador::~Coordinador(){

}
void Coordinador::dibuja()
{
	if (estado == INICIO) {
		mundo.inicializa();
		mundo.dibuja();
	}
	else if (estado == JUEGO)
	{
		mundo.dibuja();
	}
	else if (estado == PAUSA)
	{
		mundo.dibuja();
		//ETSIDI::setTextColor(0, 1, 0);
		//ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		//ETSIDI::printxy("PAUSA", -2, 10);
		//ETSIDI::printxy("Pulsa C para continuar", -5, 5);
	}
	else if (estado == GAMEOVER)
	{
		mundo.dibuja();
		//ETSIDI::setTextColor(1, 0, 0);
		//ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		//ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		//ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (estado == FIN)
	{
		mundo.dibuja();
		//ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		//ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);
		//ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}
}

void Coordinador::teclaEspecial(unsigned char key)
{
	if (estado == JUEGO)
		mundo.teclaEspecial(key);
}

void Coordinador::mueve()
{

	if (estado == INICIO) {
		mundo.mueve();
	}
	if (estado == JUEGO)
	{
		mundo.mueve();
		if (mundo.getNumTanques() == 0)
		{
			if(!mundo.cargarNivel())
			estado = FIN;
		}
		if (mundo.getVida()==0)
		{
			estado = GAMEOVER;
		}
	}
}
void Coordinador::tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'e')
		{
			estado = JUEGO;
			mundo.cargarNivel();
		}
		if (key == 's')
			exit(0);
	}
	else if (estado == JUEGO)
	{
		mundo.tecla(key);
		if (key == 'p')
			estado = PAUSA;
		if (key == 'n') {
			if (!mundo.cargarNivel()) {
				estado = FIN;
			}
		}
		if (key == 'o')
			estado = GAMEOVER;
	}
	else if (estado == PAUSA)
	{
		estado = JUEGO;
	}
	else if (estado == GAMEOVER)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == FIN)
	{
		if (key == 'c')
			estado = INICIO;
	}
}

void Coordinador::setRaton(int x, int y) {  
	mundo.setRaton(x, y); 
}

void Coordinador::crearObjeto() {
	mundo.crearObjeto();
}