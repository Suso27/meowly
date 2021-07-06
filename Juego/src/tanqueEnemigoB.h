#pragma once
#include "tanqueEnemigo.h"
class tanqueEnemigoB :
    public tanqueEnemigo
{
public:
    tanqueEnemigoB();
    ~tanqueEnemigoB();
    tanqueEnemigoB(float x, float y);
    void Inicializa();
};

