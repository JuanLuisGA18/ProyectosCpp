#include "StdAfx.h"
#include "Ataque_dragon.h"
#include <iostream>
using namespace std;

void gotoxy(int x, int y);
Ataque_dragon::Ataque_dragon(void)
{
}
void Ataque_dragon::imprimir()
{
	gotoxy(x,y);
	cout<<"<0>";
}
void Ataque_dragon::borrar()
{
	gotoxy(x,y);
	cout<<"   ";
}

void Ataque_dragon::movimiento()
{
	switch(lado)
	{
	case 0:
		{
			borrar();
			x++;
			imprimir();
			break;
		}
	case 1:
		{
			borrar();
			x--;
			imprimir();
			break;
		}
		case 2:
		{
			borrar();
			y--;
			imprimir();
			break;
		}
		case 3:
		{
			borrar();
			y++;
			imprimir();
			break;
		}
	}
}
Ataque_dragon::Ataque_dragon(int _X, int _Y, int _Lado)
{
	x=_X;
	y=_Y;
	lado=_Lado;
}
Ataque_dragon::~Ataque_dragon(void)
{
}
