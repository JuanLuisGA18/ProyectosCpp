#include "StdAfx.h"
#include "Nodo_lis.h"
using namespace std;

Nodo_lis::Nodo_lis(void)
{
	int i;

	Sig=NULL;
	Ant=NULL;
	for(i=0;i<24;i++)
	{
		palabra[i]=NULL;
	}
	for(i=0;i<250;i++)
	{
		definicion[i]=NULL;
	}
	clave=NULL;
	identificador=NULL;
}

void Nodo_lis::imprimir()
{
	cout<<palabra;
	cout<<definicion;
}
void Nodo_lis::copiar(Nodo_lis *&copia)
{
	int i=0;
	while(copia->palabra[i]!=NULL)
	{
		palabra[i]=copia->palabra[i];
		i++;
	}
	palabra[i]=NULL;
	i=0;
	while(copia->definicion[i]!=NULL)
	{
		definicion[i]=copia->definicion[i];
		i++;
	}
	definicion[i]=NULL;
	identificador=copia->identificador;
	clave=copia->clave;
	//Sig=copia;
}
void Nodo_lis::copiar2(Nodo_lis copia)
{
	int i=0;
	while(copia.palabra[i]!=NULL)
	{
		palabra[i]=copia.palabra[i];
		i++;
	}
	palabra[i]=NULL;
	i=0;
	while(copia.definicion[i]!=NULL)
	{
		definicion[i]=copia.definicion[i];
		i++;
	}
	definicion[i]=NULL;
	identificador=copia.identificador;
	clave=copia.clave;
	//Sig=copia;
}
Nodo_lis::~Nodo_lis(void)
{
	
}
