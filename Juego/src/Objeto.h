#pragma once
#include "Vector2D.h"
#include <ctime>
#include "ColorRGB.h"
#include "tanqueJugador.h"
#include "ETSIDI.h"
using ETSIDI::Sprite;
class Objeto
{
	friend class Interaccion;
protected:
	Vector2D posicion;
	ColorRGB color;


	Sprite spriteObjeto{ "imagenes/cora.png"};
public:
	Vector2D getPos();
	//intentar meter el setPos(vector2D)
	void setPos(Vector2D pos);

	Objeto();
	void dibuja();
	float distancia(Vector2D punto);
	virtual void aplicarEfecto(tanqueJugador& j) { };
	float get_random(double i, double j);
};

