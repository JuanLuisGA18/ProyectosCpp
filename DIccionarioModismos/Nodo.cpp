#include "StdAfx.h"
#include "Nodo.h"

#include <iostream>
using namespace std;
Nodo::Nodo(void)
{

	Hijo_izq=NULL;
	Hijo_der=NULL;
	Padre=NULL;
	fin=false;
}
Nodo::Nodo(char pal[24], char def[250])
{
	int i=0;
	clave=0;
	while(i<24&&pal[i]!=NULL)
	{
		palabra[i]=pal[i];
		clave+=palabra[i];
		i++;
	}
	palabra[i]=NULL;
	i=0;
	while(i<250&&def[i]!=NULL)
	{
		definicion[i]=def[i];
		i++;
	}
	definicion[i]=NULL;
	identificador=NULL;
	fin=false;
}
Nodo::Nodo(Nodo_lis base)
{
	Hijo_izq=NULL;
	Hijo_der=NULL;
	Padre=NULL;
	int i=0;
	identificador=base.identificador;
	while(base.palabra[i]!=NULL&&i<24)
	{
		palabra[i]=base.palabra[i];
		i++;
	}
		palabra[i]=NULL;
		i=0;
	while(base.definicion[i]!=NULL&&i<250)
	{
		definicion[i]=base.definicion[i];
		i++;
	}
	definicion[i]=NULL;
	clave=base.clave;
	fin=false;
}
bool Nodo::recorrido()
{
	fin=false;
	
		if((Hijo_izq->recorrido()==true&&Hijo_der->recorrido()==true))
		{
			fin=true;
		}
	return fin;
}

void Nodo::Imprimir()
{
	int i;
	cout<<"Palabra: "<<endl;
	cout<<palabra<<endl;
	cout<<"Definici\242n: "<<endl;
	cout<<definicion<<endl;
	system("pause");
}
void Nodo::crear(Nodo_lis base)
{
	Hijo_izq=NULL;
	Hijo_der=NULL;
	Padre=NULL;
	int i=0;
	identificador=base.identificador;
	while(base.palabra[i]!=NULL&&i<24)
	{
		palabra[i]=base.palabra[i];
		i++;
	}
		palabra[i]=NULL;
		i=0;
	while(base.definicion[i]!=NULL&&i<250)
	{
		definicion[i]=base.definicion[i];
		i++;
	}
	definicion[i]=NULL;
	clave=base.clave;
	fin=false;
}
Nodo::~Nodo(void)
{
}
