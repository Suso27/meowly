#pragma once
#include "Objeto.h"
class Botiquin :
    public Objeto
{
public:
    Botiquin();
    void aplicarEfecto(tanqueJugador& j);

};

