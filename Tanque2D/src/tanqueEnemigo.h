#pragma once
#include "tanque.h"


class tanqueEnemigo : public tanque{
public:
	tanqueEnemigo();
	void Inicializa();
	void Mueve(float t, Vector2D posJ);
	void obstaculos();
};

