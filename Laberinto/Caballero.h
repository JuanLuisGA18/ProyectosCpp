#pragma once
#include "Personaje.h"
#include "Dragon.h"
#include "Hombre_rana.h"
class Caballero:public Personaje
{
public:
	int x;
	int y;
	int tmp;
	int i;
public:
	Caballero(void);
	Caballero(int _X, int _Y);
	~Caballero(void);
	void ataque(class Dragon D1, class Dragon D2, class Hombre_rana HR);
	void movimiento(class Dragon D1, class Dragon D2, class Hombre_rana HR);
	void imp_espadas();
	void borr_espadas();
	void imp_cab();
	void borrar_cab();
};

