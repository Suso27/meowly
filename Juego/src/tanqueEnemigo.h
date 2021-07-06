#pragma once
#include "tanque.h"


class tanqueEnemigo : public tanque{
public:
	friend class Interaccion;

	tanqueEnemigo();
	virtual ~tanqueEnemigo();
	tanqueEnemigo(float x, float y,const char* s);
	void Inicializa(float x,float y);
	void Mueve(float t, Vector2D posJ);
};

