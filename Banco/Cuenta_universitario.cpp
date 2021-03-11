#include "StdAfx.h"
#include "Cuenta_universitario.h"
#include <iostream>
using namespace std;

void tema();
Cuenta_universitario::Cuenta_universitario(void)
{
}
void gotoxy(int x, int y);
void Cuenta_universitario::Apertura_cuenta_univeritaria()
{
	Apertura();
	gotoxy(1,10);
	cin.ignore();
	cout<<"Ingrese nombre universidad ";
	gotoxy(31,10);
	gets(nombre_universidad);
}
void Cuenta_universitario::Supernet_universitaria()
{
	int opcion=0;
	while(opcion!=4)
	{
	system("cls");
	tema();
	gotoxy(1,3);
	cout<<"Bienvenido a Super Net universitario";
	gotoxy(1,4);
	cout<<"Seleccione una de las siguientes opciones:";
	gotoxy(1,5);
	cout<<"1) Consultar saldo y datos";
	gotoxy(1,6);
	cout<<"2) Depositos";
	gotoxy(1,7);
	cout<<"3) Retiros";
	gotoxy(1,8);
	cout<<"4) Volver";
	gotoxy(1,9);
	cin>>opcion;
	switch(opcion)
	{
	case 1:
		{

			Datos_uni();
			gotoxy(1,23);
			system("pause");
			break;
		}
	case 2:
		{
			Deposito();
			break;
		}
	case 3:
		{
			Retiro();
			break;
		}
	case 4:
		{
			system("cls");
			tema();
			gotoxy(1,3);
			cout<<"Gracias por usar Super Net universitario";
			gotoxy(1,23);
			system("pause");
			break;
		}
	default:
		{

			break;
		}
	}
}
}
void Cuenta_universitario::Datos_uni()
{
	Datos();
	gotoxy(1,10);
	cout<<"La universidad es: ";
	gotoxy(31,10);
	cout<<nombre_universidad;
}

Cuenta_universitario::~Cuenta_universitario(void)
{
}
