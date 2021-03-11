#include "StdAfx.h"
#include "Cuenta.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <ctime>
using namespace std;
void tema();

void gotoxy(int x,int y)
{
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon,dwPos);
}
void Cuenta::Apertura()
{
	gotoxy(1,3);
	cin.ignore();
	cout<<"Ingrese nombre del cliente ";
	gotoxy(31,3);
	gets(nombre_cliente);
	gotoxy(1,4);
	cout<<"Ingrese direcci\242n ";
	gotoxy(31,4);
	gets(direccion);
	gotoxy(1,5);
	cout<<"Ingrese n\243mero de t\202lefono ";
	gotoxy(31,5);
	gets(telefono);
	gotoxy(1,6);
	cout<<"Ingrese comisi\242n mensual ";
	gotoxy(38,6);
	cout<<"%";
	gotoxy(31,6);
	cin>>comision;
	gotoxy(1,7);
	cout<<"Ingrese n\243mero de cuenta ";
	gotoxy(31,7);
	cin>>no_cuenta;
	gotoxy(1,8);
	cout<<"Ingrese deposito inicial ";
	gotoxy(31,8);
	cin>>saldo;
	time_t now= time(0);
	//tm *time =localtime(&now);
	fecha=ctime(&now);	
	gotoxy(1,9);
	cout<<"La cuenta se creo el  "<<fecha;
}
void Cuenta::Deposito()
{
	int deposito;
	system("cls");
	tema();
	gotoxy(1,3);
	cout<<"Bienvenido al sistema de depositos";
	gotoxy(1,4);
	cout<<"\250Cuanto desea ingresar? ";
	cin>>deposito;
	saldo+=deposito;
}
void Cuenta::Retiro()
{
	int retiro=1;
	while(retiro!=0)
	{
	system("cls");
	tema();
	gotoxy(1,3);
	cout<<"Bienvenido al sistema de retiros";
	gotoxy(1,4);
	cout<<"\250Cuanto desea retirar? ";
	cin.ignore();
	cin>>retiro;
	if(retiro<saldo)
	{
		saldo-=retiro;
		retiro=0;
		break;
	}
	else
	{
		gotoxy(1,8);
		cout<<"Saldo inssuficiente vuelva a intentar";
		gotoxy(1,9);
		system("pause");
		
	}
	}

}
void Cuenta::Super_net()
{
	
	int opcion=0;
	while(opcion!=4)
	{
	system("cls");
	tema();
	gotoxy(1,3);
	cout<<"Bienvenido a Super Net";
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
	}
	switch(opcion)
	{
	case 1:
		{

			Datos();
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
			cout<<"Gracias por usar Super Net";
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


void Cuenta::Datos()
{
	system("cls");
	tema();
	gotoxy(1,3);
	cout<<"Nombre del cliente: ";
	gotoxy(31,3);
	cout<<nombre_cliente;
	gotoxy(1,4);
	cout<<"Direcci\242n: ";
	gotoxy(31,4);
	cout<<direccion;
	gotoxy(1,5);
	cout<<"N\243mero de t\202lefono: ";
	gotoxy(31,5);
	cout<<telefono;
	gotoxy(1,6);
	cout<<"Comisi\242n mensual: ";
	gotoxy(31,6);
	cout<<comision;
	gotoxy(38,6);
	cout<<"%";
	gotoxy(1,7);
	cout<<"N\243mero de cuenta: ";
	gotoxy(31,7);
	cout<<no_cuenta;
	gotoxy(1,8);
	cout<<"Saldo ";
	gotoxy(31,8);
	cout<<saldo;
	gotoxy(1,9);
	cout<<"La cuenta se creo el  "<<fecha;

}
void Cuenta::Acceso()
{
	Super_net();
}
Cuenta::Cuenta(void)
{
}


Cuenta::~Cuenta(void)
{
}
