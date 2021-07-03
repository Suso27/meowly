#pragma once
#include "tanque.h"


class tanqueEnemigo : public tanque{
public:
	tanqueEnemigo();
	virtual ~tanqueEnemigo();
	tanqueEnemigo(float x, float y);
	void Inicializa(float x,float y);
	void Mueve(float t, Vector2D posJ);
	void obstaculos();
};

