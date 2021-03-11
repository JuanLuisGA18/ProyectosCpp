#pragma once
class Ataque_dragon
{
public:
	int x;
	int y;
	int lado;
	void imprimir();
	void borrar();
	void movimiento();
	Ataque_dragon(void);
	Ataque_dragon(int _X, int _Y, int _Lado);
	~Ataque_dragon(void);
};

