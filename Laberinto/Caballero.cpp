#include "StdAfx.h"
#include "Caballero.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#define arriba 72
#define izquierda 75
#define derecha 77
#define abajo 80
#define espacio 32
using namespace std;
bool lim(int x, int y);
void gotoxy(int x, int y);
Caballero::Caballero(void)
{
}
Caballero::Caballero(int _X,int _Y)
{
	salud=100;
	daño_ataque=100;
	x=_X;
	y=_Y;
	gotoxy(x,y);
	cout<<"+";
	i=0;
}
void Caballero::ataque(class Dragon D1, class Dragon D2, class Hombre_rana HR)
{
				imp_espadas();
				if((D1.x==(x+1)||(D1.x+3)==x)&&(D1.y==y))
				{
					i=1;
				}
			
				if((D2.x==(x+1)||(D2.x+3)==x)&&(D2.y==y))
				{
				
					i=2;
				}
				if((HR.x==(x+1)||(HR.x+1)==x)&&(HR.y==y))
				{
				
					i=3;
				}
				Sleep(200);
				borr_espadas();
				
}
void Caballero::movimiento(class Dragon D1, class Dragon D2, class Hombre_rana HR)
{
	i=0;
	borrar_cab();
	if(kbhit())
	{
	
		char tecla=getch();
			if(tecla==espacio)
			{
				ataque(D1,D2,HR);

			
			}
			if(tecla==arriba&&lim(x,(y-1)))
			{
				y--;
			}
			if(tecla==abajo&&lim(x,(y+1)))
			{
						y++;
			}
			if(tecla==izquierda&&lim((x-1),y))
			{
				
						x--;
					
			}
			if(tecla==derecha&&lim((x+1),y))
			{
						x++;
			}
	}
		
	if(((D1.x>=(x)&&D1.x<=(x+4))&&D1.y==y))
	{
		salud-=D1.daño_ataque;
	}
	if(((D2.x>=(x)&&D2.x<=(x+4))&&D2.y==y))
	{
		salud-=D1.daño_ataque;
	}
	if(((HR.x>=(x)&&HR.x<=(x+1))&&HR.y==y))
	{
		salud-=HR.daño_ataque;
	}
	imp_cab();
	
}

void Caballero::imp_cab()
{
	gotoxy(x,y);
	cout<<"+";
}
void Caballero::borrar_cab()
{
	gotoxy(x,y);
	cout<<" ";
}
void Caballero::imp_espadas()
{
	gotoxy((x-1),y);
    cout<<"\134";
	gotoxy(x,y);
	cout<<"+";
	gotoxy((x+1),y);
    cout<<"/";
}
void Caballero::borr_espadas()
{
	
	gotoxy((x-1),y);
    cout<<" ";
	gotoxy(x,y);
	cout<<"+";
	gotoxy((x+1),y);
    cout<<" ";
}
Caballero::~Caballero(void)
{
}
