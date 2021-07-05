#pragma once
#include "Objeto.h"
class ObjetoRicochet :
    public Objeto
{
public:
    ObjetoRicochet();
    void aplicarEfecto(tanqueJugador& j);

};

