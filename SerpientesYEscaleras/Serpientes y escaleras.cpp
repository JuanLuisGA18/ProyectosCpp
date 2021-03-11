// Serpientes y escaleras.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <time.h>
#include "Ficha.h"
using namespace std;

bool AjustarVentana(int Ancho, int Alto) {
	_COORD Coordenada;
	Coordenada.X = Ancho;
	Coordenada.Y = Alto;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Right = Ancho - 1;
	Rect.Bottom = Alto - 1;

	// Obtener el handle de la consola
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ajustar el buffer al nuevo tamaño
	SetConsoleScreenBufferSize(hConsola, Coordenada);

	// Cambiar tamaño de consola a lo especificado en el buffer
	SetConsoleWindowInfo(hConsola, TRUE, &Rect);
	return TRUE;
}
void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}
void tema(char J1, char J2, char J3)
{
	int i,j,cont=1;
	i=6;
	gotoxy(9,2);
	cout<<"Serpientes y escaleras";
	//Inicio while contador casilla
	while(cont<64)
	{
		
		//Contador for ascendente
		
		for(j=27;j>5;j-=3)
		{
		gotoxy(i,j);
		cout<<cont;
		cont++;
	
		}
		//Fin contador for ascendente
		i+=5;
		//Contador for descendente
		for(j=6;j<28;j+=3)
		{
			gotoxy(i,j);
			cout<<cont;
			cont++;
			
		}
			//Fin contador for descendente
		
		i+=5;
	}//Fin ciclo while contador casilla
	//Inicio serpiente 1
		j=27;
		for(i=18;i<26;i++)
		{
			//If primera subida
			if(j==27)
			{
				for(j;j>25;j--)
				{
					gotoxy(i,j);
					cout<<"|";
				}
			}
			
			//Fin if primera subida
			gotoxy(i,j);
			cout<<"_";
		}
		cout<<"|";
	//Fin serpiente 1
	//Inicio for serpiente 2
	j=22;
		for(i=18;i<37;i++)
		{
			//If primer salto
			if(i==18)
			{
				gotoxy(18,23);
				cout<<"|";
			}
			//Fin if primer saldo
		//Inicio if primera subida
			
			if(i==24)
			{
				//For primera subida
				for(j=22;j>16;j--)
				{
					gotoxy(i,j);
					cout<<"|";
				}
				//Fin for primera subida

			}
				//fin if primera subida
			gotoxy(i,j);
			cout<<"_";
		}
		cout<<"|";
		//Fin for serpiente 2
	//Inicio escalera 1
		j=12;
		for(i=13;i<32;i++)
		{
			//If subida
			if(i==13)
			{
				//Inicio for subida
				for(j=12;j>10;j--)
				{
					gotoxy(i,j);
					cout<<"+";
				}
				//Fin for subida
			}
			//Fin if subida
			//If segunda subida
			if(i==28)
			{
				//Inicio for segunda subida
				for(j=10;j>7;j--)
				{
					gotoxy(i,j);
					cout<<"+";
				}
				//Fin for segunda subida
			}
			//fin if segunda subida
			gotoxy(i,j);
			cout<<"+";
		}
	//Fin escalera 1
	//Inicio escalera 2
		j=19;
		for(i=32;i<42;i++)
		{
			gotoxy(i,j);
			cout<<"+";
			
			//Inicio if segunda bajada
			if(i==39)
			{
				//Inicio for primera bajada
				for(j=19;j<22;j++)
				{
					gotoxy(i,j);
					cout<<"+";
				}
				//Fin for primera bajada
			}
			//Fin if segunda bajada
		}
	//Fin escalera 2
	gotoxy(48,5);
	cout<<"-=Serpiente";
	gotoxy(48,6);
	cout<<"+=Escalera";
	gotoxy(61,5);
	cout<<"___";
	gotoxy(61,6);
	cout<<"| |";
	gotoxy(61,7);
	cout<<"\257\257\257";
	gotoxy(51,8);
	cout<<"Turno de:";
	gotoxy(50,11);
cout<<J1<<"    "<<J2<<"    "<<J3;
	gotoxy(50,12);
	cout<<"J1   J2   J3";
}
//Fin tema
int Dado()
{
	int casillas;
	srand(time(NULL));
	casillas=rand()%6+1;
	return casillas;
}

int _tmain(int argc, _TCHAR* argv[])
{
	bool juego=true, inicio=true;
	int dado=0;
	char jugadores[30];
	Ficha J1(4,26,'A');
	Ficha J2(5,26,'B');
	Ficha J3(6,26,'C');
	AjustarVentana(85,30);
	gotoxy(6,3);
	//Bucle de inicio
	while(inicio)
	{
		system("cls");
		gotoxy(2,3);
		cout<<"Bienvenido a serpientes y escaleras";
		gotoxy(2,4);
		cout<<"El juego es de m\241ximo 3 jugadores \250Cuantos desean jugar? (2-3) ";
		cin>>jugadores;
		//Switch número de jugadores

		switch(jugadores[0])
		{
			// 1 jugador
		case '1':
			{
				gotoxy(6,5);
				cout<<"No puede jugar 1 sola persona";
				gotoxy(6,6);
				system("pause");
				break;
			}
			//fin 1 jugador
		case '2':
			//2 Jugadores
			{
				char nombre1[30], nombre2[30];
				gotoxy(6,5);
				cout<<"\250Cual es el nombre del jugador 1? ";
				cin.ignore();
				gets(nombre1);
				gotoxy(6,6);
				cout<<"J1= "<<nombre1[0];
				J1.nombre=nombre1[0];
				gotoxy(6,7);
				cout<<"\250Cual es el nombre del jugador 2? ";
				gets(nombre2);
				gotoxy(6,8);
				cout<<"J2= "<<nombre2[0];
				J2.nombre=nombre2[0];
				J3.posicion=0;
				J3.nombre='X';
				inicio=false;
				break;
			}
			//Fin 2 jugadores
		//3 Jugadores
		case '3':
			{
				char nombre1[30], nombre2[30],nombre3[30];
				gotoxy(6,5);
				cout<<"\250Cual es el nombre del jugador 1? ";
				cin.ignore();
				gets(nombre1);
				gotoxy(6,6);
				cout<<"J1= "<<nombre1[0];
				J1.nombre=nombre1[0];
				gotoxy(6,7);
				cout<<"\250Cual es el nombre del jugador 2? ";
				gets(nombre2);
				gotoxy(6,8);
				cout<<"J2= "<<nombre2[0];
				J2.nombre=nombre2[0];
				gotoxy(6,9);
				cout<<"\250Cual es el nombre del jugador 3? ";
				gets(nombre3);
				gotoxy(6,10);
				cout<<"J3= "<<nombre3[0];
				J3.nombre=nombre3[0];
				inicio=false;
				break;
			}
			//Fin 3 jugadores
			//Default
		default:
			{
				gotoxy(6,5);
				cout<<"Opci\242n no valida";
				gotoxy(6,6);
				system("pause");
				break;
			}
			//Fin default
		}
	//Fin switch número de jugadores
	}//Fin bucle de inicio
		
	while(juego)
	{
		//system("cls");
		int turno=1;
		system("cls");
		tema(J1.nombre,J2.nombre,J3.nombre);
		J1.pintar();
		J2.pintar();
		if(J3.posicion>0)
		{
			J3.pintar();
		}
		//Turno del primer jugador
		if(turno==1)
		{
			
			int dado;
			gotoxy(45,16);
			system("pause");
			gotoxy(61,8);
			cout<<J1.nombre;
			dado=Dado();
			gotoxy(62,6);
			cout<<dado;
			J1.movimiento(dado);
			turno=2;
			gotoxy(45,16);
			system("pause");
		}
		//Turno del primer jugador
		//Condición victoria del primer jugador
		if(J1.posicion==64)
		{
			system("cls");
			gotoxy(30,10);
			cout<<"El jugador 1 ha ganado";
			gotoxy(30,11);
			system("pause");
			juego=false;
			break;
		}
		//Fin condición victoria primer jugador
		//Turno del segundo jugador
		if(turno==2)
		{
			int dado;
			dado=Dado();
			gotoxy(61,8);
			cout<<J2.nombre;
			gotoxy(62,6);
			cout<<dado;
			J2.movimiento(dado);
			if(J3.posicion>0)
			{
			turno=3;
			}
			else
			{
				turno=1;
			}
			gotoxy(45,16);
			system("pause");
		}
		//Turno del segundo jugador
		//Condición victoria del segundo jugador
		if(J2.posicion==64)
		{
			system("cls");
			gotoxy(30,10);
			cout<<"El jugador 2 ha ganado";
			gotoxy(30,11);
			system("pause");
			juego=false;
			break;
		}
		//Fin condición victoria segundo jugador
		//Turno del tercer jugador
		if(turno==3)
		{
			int dado;
			dado=Dado();
			gotoxy(61,8);
			cout<<J3.nombre;
			gotoxy(62,6);
			cout<<dado;
			J3.movimiento(dado);
			turno=1;
			gotoxy(45,16);
			
		}
		//Turno del tercer jugador
		//Condición victoria del tercer jugador
		if(J3.posicion==64)
		{
			system("cls");
			gotoxy(30,10);
			cout<<"El jugador 3 ha ganado";
			gotoxy(30,11);
			system("pause");
			juego=false;
			break;
		}
		//Fin condición victoria tercer jugador
	}//Fin ciclo del juego
	return 0;
}//Fin main

