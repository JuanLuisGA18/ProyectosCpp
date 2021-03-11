// Herencia.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <conio.h>
#include <Windows.h>
#include<iostream>
#include"Caballero.h"
#include"Personaje.h"
#include "Monstruo.h"
#include "Dragon.h"
#include "Hombre_rana.h"
using namespace std;



struct console
  {
  console( unsigned width, unsigned height )
    {
    SMALL_RECT r;
    COORD      c;
    hConOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (!GetConsoleScreenBufferInfo( hConOut, &csbi ))
      throw runtime_error( "You must be attached to a human." );

    r.Left   =
    r.Top    = 0;
    r.Right  = width -1;
    r.Bottom = height -1;
    SetConsoleWindowInfo( hConOut, TRUE, &r );

    c.X = width;
    c.Y = height;
    SetConsoleScreenBufferSize( hConOut, c );
    }

  ~console()
    {
    SetConsoleTextAttribute(    hConOut,        csbi.wAttributes );
    SetConsoleScreenBufferSize( hConOut,        csbi.dwSize      );
    SetConsoleWindowInfo(       hConOut, TRUE, &csbi.srWindow    );
    }

  HANDLE                     hConOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  };
void gotoxy(int x, int y)
{
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon,dwPos);
}
void tema(int salud, int puntos)
{
	int i,j;
	j=2;
	for(i=2;i<69;i++)
	{
		gotoxy(i,j);
		cout<<"-";

	}
	j=24;
	for(i=2;i<69;i++)
	{
		gotoxy(i,j);
		cout<<"-";

	}
	i=1;
	for(j=3;j<24;j++)
	{
		gotoxy(i,j);
		cout<<"|";

	}
	i=69;
	for(j=3;j<24;j++)
	{
		gotoxy(i,j);
		cout<<"|";

	}
	gotoxy(4,1);
	cout<<"Knight fight";
	gotoxy(23,1);
	cout<<"          ";
	gotoxy(23,1);
	cout<<"Salud="<<salud<<"%";
	gotoxy(36,1);
	cout<<"Puntos="<<puntos;
	

}
void mapa()
{
	int i,j;
	j=7;
	for(i=2;i<40;i++)
	{
		gotoxy(i,j);
		cout<<"-";
	}
	j=18;
	for(i=7;i<40;i++)
	{
		gotoxy(i,j);
		cout<<"-";
	}
	j=21;
	for(i=2;i<35;i++)
	{
		gotoxy(i,j);
		cout<<"-";
	}
	j=9;
	for(i=45;i<69;i++)
	{
		gotoxy(i,j);
		cout<<"-";
	}
	i=7;
	for(j=10;j<18;j++)
	{
		gotoxy(i,j);
		cout<<"|";
	}
	j=11;
	for(i=40;i<54;i++)
	{
		gotoxy(i,j);
		cout<<"-";
	}
	i=40;
	for(j=15;j<24;j++)
	{
		gotoxy(i,j);
		cout<<"|";
	}
	i=40;
	for(j=4;j<11;j++)
	{
		gotoxy(i,j);
		cout<<"|";
	}
	i=54;
	for(j=12;j<22;j++)
	{
		gotoxy(i,j);
		cout<<"|";
	}
	gotoxy(2,23);
	cout<<"Salida";
	
	

}
bool lim(int x, int y)
{
	if(y<3||y>23)
	{
		return false;
	}
	if(x<2||x>68)
	{
		return false;
	}
	
	if(y==7&&x>=2&&x<40)
	{
		return false;
	}
	if(y==18&&x>=7&&x<40)
	{
		return false;
	}
	if(y==21&&x>=2&&x<35)
	{
		return false;
	}
	if(y==9&&x>=45&&x<69)
	{
		return false;
	}
		if(y==11&&x>=40&&x<54)
	{
		return false;
	}
	if(x==7&&y>=10&&y<18)
	{
		return false;
	}

	if(x==40&&y>=15&&y<24)
	{
		return false;
	}
	if(x==40&&y>=4&&y<11)
	{
		return false;
	}
	if(x==54&&y>=12&&y<22)
	{
		return false;
	}

	return true;
}
void Game_over(int puntos,int salud,int i)
{
	system("cls");
	puntos=((salud*100)+puntos);
	gotoxy(20,10);
	if(i==1)
	{
		cout<<"\255Felicidades!";
	}
	if(i==0)
	{
		cout<<"Suerte la proxima";
	}
	gotoxy(20,11);
	cout<<"Puntuaci\242n:";
	gotoxy(35,11);
	cout<<puntos;
}
void inicio()
{
	gotoxy(4,5);
	cout<<"\13400/";
	gotoxy(14,5);
	cout<<"\13400/";
	gotoxy(9,6);
	cout<<"\134+/";
	gotoxy(4,7);
	cout<<"Bienvenido a Knight fight";
	gotoxy(4,8);
	cout<<"El objetivo del juego es llegar a la salida";
	gotoxy(4,9);
	cout<<"que est\240 indicada abajo";
	gotoxy(4,10);
	cout<<"Para lograrlo deber\240s enfrentar o esquivar los monstruos";
	gotoxy(4,11);
	cout<<"Matar a un drag\242n \13400/ te d\240 100 puntos y un hombre rana 0/ 50 ";
	gotoxy(4,12);
	cout<<"Usa los cursores para moverte y la barra espaciadora";
	gotoxy(4,13);
	cout<<"para atacar o detener el tiempo";
	gotoxy(4,14);
	cout<<"\255Buena suerte!";
	gotoxy(4,15);
	system("pause");
}
console con(70,25);
int _tmain(int argc, _TCHAR* argv[])
{
	int i=0;
	int l=0;
	int puntos=0;
	bool juego=true;
	while(juego)
	{
	inicio();
	Caballero cab(5,5);
	Dragon D1(14,10,10,10,10,10,0);
	Dragon D2(50,7,10,10,10,10,2);
	Hombre_rana HR (46,4,4,8,64,45);
	system("cls");
	while(cab.salud>0)
	{
			tema(cab.salud,puntos);
			mapa();
			cab.movimiento(D1,D2,HR);
			l=cab.i;
			HR.Movimiento();
			D1.volar();
			D2.volar();
			if(l==1)
			{
				D1.salud-=cab.daño_ataque;
				
			
			}
			if(l==2)
			{
				D2.salud-=cab.daño_ataque;
				
			}
			if(l==3)
			{
				HR.salud-=cab.daño_ataque;
			
			}
			if(D1.salud==0&&D1.vivo==true)
			{
				puntos+=100;
				D1.vivo=false;
			}
	
				if(D2.salud==0&&D2.vivo==true)
			{
			
				puntos+=100;
				D2.vivo=false;
			}
			if(HR.salud==0&&HR.vivo==true)
			{
			
				puntos+=50;
				HR.vivo=false;
			}
			Sleep(20);
			if(cab.x>2&&cab.x<8&&cab.y==23)
			{
				i=1;
				break;
			}
		}
	Game_over(puntos,cab.salud,i);
	puntos=0;
	cab.salud=100;
	D1.salud=30;
	D2.salud=30;
	HR.salud=15;
	cab.x=4;
	cab.y=4;
	D1.vivo=true;
	D2.vivo=true;
	HR.vivo=true;

	}
	gotoxy(20,12);
	system("pause");
	return 0;
}

