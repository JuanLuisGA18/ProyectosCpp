#include "StdAfx.h"
#include "Ficha.h"
#include <Windows.h>
#include <iostream>
using namespace std;
void gotoxy(int x, int y);
Ficha::Ficha(void)
{
	nombre='0';
	x=1;
	y=27;
	sentido=true;
	posicion=0;
}
Ficha::Ficha(int _X, int _Y, char _Nombre)
{
	x=_X;
	y=_Y;
	nombre=_Nombre;
	sentido=true;
	posicion=1;
}
void Ficha::movimiento(int casillas)
{
	int i,j;
//For contador de casillas
	for(j=casillas;j>0;j--)
	{
		pintar();
		Borrar();
		//Inicio condición casilla 64
		if (posicion==64)
		{
			//contador for inverso
			for(j;j>0;j--)
			{
				y-=3;
				posicion--;
				pintar();
				Sleep(300);

			}
			//fin contador for inverso
			break;
		}
		//Fin condicion casilla 64
		// Casilla!=64
		else
		{
			//Inicio condición borde
			if((posicion%8==0))
			{
				x+=5;
				posicion++;
				j++;
				
			}
			else if(sentido)
			{
				//Condición borde superior
				if((y-3)>=4)
				{
					y-=3;
					posicion++;
				}
				else
				{
					sentido=false;
				}
				//fin condición borde superior
			}
			else if(!sentido)
			{
				//Condición borde superior
				if((y+3)<=27)
				{
					y+=3;
					posicion++;
				}
				else
				{
					sentido=true;
				}
				//fin condición borde superior
			}
			//Fin condición borde
		
			pintar();
			Sleep(300);
			
		}
		//Fin casilla !=64
	
	}

//Fin for contador de caslillas
	Atajo();
	
}
void Ficha::pintar()
{
	gotoxy(x,y);
	cout<<nombre;
}
void Ficha::Borrar()
{
	gotoxy(x,y);
	cout<<" ";
}
void Ficha::Atajo()
{
	//Serpiente 1
	if(posicion==34)
	{
		Borrar();
		y=26;
		x=16;
		sentido=true;
		posicion=17;
	}
	//Fin Serpiente 1
	//Serpiente 2
	if(posicion==53)
	{
		Borrar();
		y=20;
		x=16;
		sentido=true;
		posicion=19;
		pintar();
		Sleep(300);
	}
	//Fin serpiente 2
	//Escalera 1
	if(posicion==11)
	{
		Borrar();
		y=5;
		x=32;
		sentido=false;
		posicion=41;
		pintar();
		Sleep(300);
	}
	//Fin escalera 1
	//Escalera 2
	if(posicion==45)
	{
		Borrar();
		y=20;
		x=42;
		sentido=false;
		posicion=62;
		pintar();
		Sleep(300);
	}
	//Fin escalera 2
}
Ficha::~Ficha(void)
{
}
