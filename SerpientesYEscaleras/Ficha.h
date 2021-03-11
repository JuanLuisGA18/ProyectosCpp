#pragma once
class Ficha
{
public:
	char nombre;
	int x;
	int y;
	int posicion;
private:
	bool sentido;
public:
	Ficha(void);
	~Ficha(void);
	void movimiento(int casillas);
	Ficha(int _X, int _Y, char _Nombre);
	void pintar();
private:
	void Borrar();
	void Atajo();

};

