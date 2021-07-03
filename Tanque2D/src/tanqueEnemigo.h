#pragma once
#include "tanque.h"


class tanqueEnemigo : public tanque{
public:
	tanqueEnemigo();
	void Inicializa(float x,float y)=0;
	void Mueve(float t, Vector2D posJ);
	void obstaculos();
};

