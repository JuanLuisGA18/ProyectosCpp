#pragma once
#include"Monstruo.h"
#include "Personaje.h"
#include "Ataque_dragon.h"
class Dragon:public Monstruo,public Personaje
{
public:
	Ataque_dragon fuego(int x,int y,int lado);
	int temp;
	int lado;
	int inicio;
	int x_final;
	int y_final;
	void volar();
	void borrar_drag();
	void imp_drag();
	Dragon(int _X, int _Y, int Lim_sup, int Lim_inf, int Lim_der, int Lim_izq,int Lad);
	Dragon(void);
	~Dragon(void);
};

