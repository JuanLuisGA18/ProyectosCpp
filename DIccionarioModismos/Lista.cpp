#include "StdAfx.h"
#include "Lista.h"
using namespace std;

Lista::Lista(void)
{
	miembro=new Nodo_lis;
}
void Lista::Insertar(Nodo_lis *&nuevo)
{

	nuevo->Ant=miembro;
	nuevo->Sig=miembro->Sig;
	miembro->Sig=nuevo;
	miembro=nuevo;
	//if(miembro=NULL)
	
	
}
void Lista::imprimir()
{
	cout<<miembro->palabra<<endl;
	cout<<miembro->definicion<<endl;
	
}
void Lista::Insertar_ar(Nodo *elemento,int j)
{
	int i=0;
	Nodo_lis *nuevo= new Nodo_lis;
	nuevo->clave=elemento->clave;
	nuevo->identificador=j;
	while(i<24&&elemento->palabra[i]!=NULL)
	{
		nuevo->palabra[i]=elemento->palabra[i];
		i++;
	}
	nuevo->palabra[i]=NULL;
	i=0;
	while(i<250&&elemento->definicion[i]!=NULL)
	{
		nuevo->definicion[i]=elemento->definicion[i];
		i++;
	}
	nuevo->definicion[i]=NULL;
	nuevo->identificador=j;
	Insertar(nuevo);
}
/*Nodo_lis* Lista::Eliminmar(Nodo_lis *a_borrar)
{
	miembro->Ant=a_borrar->Ant;
	miembro->Sig=a_borrar->Sig;
	delete a_borrar;
	return miembro;
}*/
/*void Lista::Adelante()
{
	bandera=miembro->Sig;
}
void Lista::Atras()
{
	bandera=miembro->Ant;
}*/
Lista::~Lista(void)
{
}
