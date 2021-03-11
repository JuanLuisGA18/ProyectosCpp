#include "StdAfx.h"
#include "Hombre_rana.h"
#include<iostream>
using namespace std;

void gotoxy(int x, int y);
Hombre_rana::Hombre_rana(int _x, int _y, int _lim_sup, int _lim_inf, int _lim_der, int _lim_izq)
{
	x=_x;
	y=_y;
	lim_sup=_lim_sup;
	lim_inf=_lim_inf;
	lim_der=_lim_der;
	lim_izq=_lim_izq;
	lado=1;
	salud=15;
	daño_ataque=2;
}
Hombre_rana::Hombre_rana(void)
{
}
void Hombre_rana::Movimiento()
{
	bor_hr();
	if(salud>0)
	{
	if(lado==1)
	{
		if(x>=lim_der)
		{
			lado=2;
		}
		x++;
	}
	if(lado==2)
	{
		lado=3;
		if(y<=lim_inf)
		{
			lado=3;
		}
		y++;
		
	}
	if(lado==3)
	{
		if(x<=lim_izq)
		{
			lado=4;
		}
		
		x--;
		
	}
	if(lado==4)
	{
		if(y<=lim_sup)
		{
			lado=1;
		}
		
		y--;
		
	}
		imp_hr();
	}
}
void Hombre_rana::imp_hr()
{
	gotoxy(x,y);
	cout<<"0/";
}
void Hombre_rana::bor_hr()
{
	gotoxy(x,y);
	cout<<"  ";
}
Hombre_rana::~Hombre_rana(void)
{
}
