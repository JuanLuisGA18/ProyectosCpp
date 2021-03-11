#pragma once
class Monstruo
{
public:
	int x;
	int y;
	int lim_sup;
	int lim_inf;
	int lim_der;
	int lim_izq;
	bool vivo;
	Monstruo(int _X, int _Y,int Lim_sup, int Lim_inf, int Lim_der, int Lim_izq);
	Monstruo(void);
	~Monstruo(void);
};

