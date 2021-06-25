#pragma once
#include "Pared.h"

class Caja{
private:	

	Vector2D limite1; //Esquina superior izquierda
	Vector2D limite2; //Esquina inferior derecha

	Pared pared_abj;
	Pared pared_arib;
	Pared pared_izq;
	Pared pared_dcha;

public:
	    Caja();
		Caja(float l1x, float l1y, float l2x, float l2y);
		void Inicializa(float l1x, float l1y, float l2x, float l2y);
		virtual ~Caja();
		void Dibuja();
		friend class Interaccion;
		Vector2D GetLim(int i);
};

