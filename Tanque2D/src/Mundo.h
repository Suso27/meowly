#include "tanque.h"
#include "Vector2D.h"
#include "tanqueJugador.h"
#include "tanqueEnemigo.h"
#include "Pared.h"
#include "Caja.h"
#include "ListaCajas.h"

#define ALTO 800.0F
#define ANCHO 1600.0F
#define ESCALA 200.0F

class Mundo
{
private:
	Vector2D raton;
	tanqueJugador tankJ;
	tanqueEnemigo tankE;
	Caja caja;
	ListaCajas cajas;
	//ListaCajas cajas;
	Objeto objeto1;
	Objeto objeto2;
public: 
	Mundo();
	void tecla(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char);
	void setRaton(int x, int y);
};
