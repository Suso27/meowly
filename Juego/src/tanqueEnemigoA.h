#pragma once
#include "tanqueEnemigo.h"
class tanqueEnemigoA :
    public tanqueEnemigo
{
public:
    tanqueEnemigoA();
    ~tanqueEnemigoA();
    tanqueEnemigoA(float x, float y);
    void Inicializa();

};

