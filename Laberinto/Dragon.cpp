#include "StdAfx.h"
#include "Dragon.h"
#include <iostream>
using namespace std;

void gotoxy(int x, int y);
bool lim(int x, int y);
Dragon::Dragon(void)
{
	
}
void Dragon::volar()
{

	borrar_drag();
	if(salud>0)
	{
		if(x_final==x)
		{
			x_final==(rand()%lim_der+lim_izq);
		}
		if(y_final==y)
		{
			y_final=(rand()%lim_inf+lim_sup);
		}
		if(y<y_final)
		{
			y++;
		}
		if(y>y_final)
		{
			y--;
		}
		if(x<x_final)
		{
			x++;
		}
			if(y>y_final)
		{
			x--;
		}
		imp_drag();
	}
}

void Dragon::imp_drag()
{
	gotoxy(x,y);
	cout<<"\13400/";
}
void Dragon::borrar_drag()
{
	gotoxy(x,y);
	cout<<"    ";
}
Dragon::Dragon(int _X, int _Y, int Lim_sup, int Lim_inf, int Lim_der, int Lim_izq,int Lad)
{
  lado=Lad;
  temp=0;
  x=_X;
  y=_Y;
  lim_sup=Lim_sup;
  lim_inf=Lim_inf;
  lim_der=Lim_der;
  lim_izq=Lim_izq;
  x_final=_X;
  y_final=_Y;
  salud=30;
daño_ataque=5;
}

Dragon::~Dragon(void)
{
}
