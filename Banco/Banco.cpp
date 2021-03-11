// Banco.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <Windows.h>
#include <conio.h>
#include<iostream>
#include <limits>
#include <stdexcept>
#include "Cuenta.h"
#include "Cuenta_universitario.h"
#include <ctime>
#include <vector>
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

  void color( WORD color = 0x07 )
    {
    SetConsoleTextAttribute( hConOut, color );
    }

  HANDLE                     hConOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  };

void gotoxy(int x, int y);
void tema()
{
	int i,j;
	j=2;
	for(i=1;i<50;i++)
	{
		gotoxy(i,j);
		cout<<"-";
	}
	j=24;
	for(i=0;i<50;i++)
	{
		gotoxy(i,j);
		cout<<"-";
	}
	i=0;
	for(j=1;j<24;j++)
	{
		gotoxy(i,j);
		cout<<"|";
	}
	i=49;
	for(j=1;j<24;j++)
	{
		gotoxy(i,j);
		cout<<"|";
	}
	gotoxy(1,2);
	cout<<"$$$$$$$Banco \42El Tiranito\42 S.A. de C.V.$$$$$$$$$";
}


console con(50,25);
int _tmain(int argc, _TCHAR* argv[])
{
	
	int opcion=0, cuenta=0;
	Cuenta obj1;
	Cuenta_universitario obj2;
	while(opcion!=4)
	{
	system("cls");
	tema();
	gotoxy(1,3);
	cout<<"\250Que desea hacer?"<<endl;
	gotoxy(1,4);
	cout<<"1) Abrir cuenta"<<endl;
	gotoxy(1,5);
	cout<<"2) Abrir cuenta universitaria"<<endl;
	gotoxy(1,6);
	cout<<"3) Accdeder a Super Net";
	gotoxy(1,7);
	cout<<"4) Salir";
	gotoxy(1,8);
	cin>>opcion;
	switch(opcion)
	{
	case 1:
		{
			system("cls");
			tema();
			if(cuenta==0)
			{
			obj1.Apertura();
			cuenta=1;
			gotoxy(1,23);
			system("pause");
			}
			else
			{
				gotoxy(1,3);
				cout<<"Usted ya ha creado una cuenta";
				Sleep(500);
				gotoxy(1,4);
				cout<<"Volviendo al men\243";
				Sleep(700);
			}
			break;
		}
	case 2:
		{
			system("cls");
			tema();
			if(cuenta==0)
			{
			obj2.Apertura_cuenta_univeritaria();
			cuenta=2;
			gotoxy(1,23);
			system("pause");
			}
			else
			{
				gotoxy(1,3);
				cout<<"Usted ya ha creado una cuenta";
				Sleep(500);
				gotoxy(1,4);
				cout<<"Volviendo al men\243";
				Sleep(700);
			}
			break;
		}
	case 3:
		{
			switch(cuenta)
			{
			case 1:
				{
				obj1.Acceso();
				break;
				}
			case 2:
				{
				obj2.Supernet_universitaria();
				break;
				}
			default:
				{
					system("cls");
					tema();
					gotoxy(1,3);
					cout<<"No existe ninguna cuenta creada";
					gotoxy(1,4);
					system("pause");
					break;
				}

			}
	case 4:
		{
			system("cls");
			tema();
			gotoxy(1,3);
			cout<<"Gracias por usar este servicio";
			break;
		}
		}
	default:
		{
			system("cls");
			tema();
			gotoxy(1,3);
			cout<<"Opci\242n no valida vuelva a capturar";
			gotoxy(1,4);
			system("pause");
		}
	}
	}
	gotoxy(1,23);
	system("pause");
	return 0;

}

