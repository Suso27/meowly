#include "Coordinador.h"

Coordinador::Coordinador():estado(INICIO){}

Coordinador::~Coordinador(){

}
void Coordinador::dibuja()
{
	if (estado == INICIO) {
		mundo.inicializa();
		mundo.dibuja();


		dibujaCartel("imagenes/controles.png", -0.8f, -0.2f, 0.8f, -1.0f);
		dibujaCartel("imagenes/empezar.png", -0.5f, 0.9f, 0.5f, 0.3f);

	}
	else if (estado == JUEGO)
	{
		mundo.dibujaStats();
		mundo.dibuja();
	}
	else if (estado == PAUSA)
	{
		dibujaCartel("imagenes/pausa.png", -0.7f, 0.9f, 0.7f, 0.3f);
		mundo.dibuja();
	}
	else if (estado == GAMEOVER)
	{
		dibujaCartel("imagenes/gameover.png", -0.8f, 0.9f, 0.8f, 0.3f);
		mundo.dibuja();
	}
	else if (estado == FIN)
	{
		dibujaCartel("imagenes/final.png", -0.8f, 0.9f, 0.8f, 0.3f);
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
		ETSIDI::stopMusica();
		mundo.mueve();
	}
	if (estado == JUEGO)
	{
		mundo.mueve();
		if (mundo.getNumTanques() == 0)
		{
			if (!mundo.cargarNivel()) {
				ETSIDI::stopMusica();
				ETSIDI::playMusica("sonidos/Mantis.wav", true);
				estado = FIN;
			}
		}
		if (mundo.getVida()==0 || mundo.getVida() < 0)
		{
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/Engi.wav", true);
			estado = GAMEOVER;
		}
	}
}
void Coordinador::tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		switch (key)
		{
		case GLUT_LEFT_BUTTON:
			Vector2D raton = mundo.getRaton();
			if (raton.x < 0.5 && raton.x > -0.5 && raton.y < 0.9 && raton.y > 0.6) {
				estado = JUEGO;
				ETSIDI::playMusica("sonidos/MilkyWay.wav", true);
			}
			else if (raton.x < 0.5 && raton.x > -0.5 && raton.y < 0.6 && raton.y > 0.3) {
				exit(0);
			}
			break;
		}
	}
	else if (estado == JUEGO)
	{
		mundo.tecla(key);
		if (key == 'p') {
		ETSIDI::stopMusica();
		estado = PAUSA;
		}
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
		ETSIDI::playMusica("sonidos/MilkyWay.wav");
	}
	else if (estado == GAMEOVER)
	{
		if (key == 'c') {
			estado = INICIO;
			mundo.reset();
		}
	}
	else if (estado == FIN)
	{
		if (key == 'c') {
			estado = INICIO;
			mundo.reset();
		}
	}
}

void Coordinador::setRaton(int x, int y) {  
	mundo.setRaton(x, y); 
}

void Coordinador::crearObjeto() {
	if(estado == JUEGO)
	mundo.crearObjeto();
}

void Coordinador::dibujaCartel(const char* s, float l1x, float l1y, float l2x, float l2y) {
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(s).id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex2f(l1x, l1y);
	glTexCoord2d(0, 1); glVertex2f(l1x, l2y);
	glTexCoord2d(1, 1); glVertex2f(l2x, l2y);
	glTexCoord2d(1, 0); glVertex2f(l2x, l1y);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}



