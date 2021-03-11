#pragma once
#include"Monstruo.h"
#include "Personaje.h"
class Hombre_rana:public Personaje, public Monstruo
{
public:
	int lado;
	void Movimiento();
	Hombre_rana(void);
	Hombre_rana(int _x, int _y, int _lim_sup, int _lim_inf, int _lim_der, int _lim_izq);
	void imp_hr();
	void bor_hr();
	~Hombre_rana(void);
};

