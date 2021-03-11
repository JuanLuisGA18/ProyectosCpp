#pragma once
#include "Nodo_lis.h"
#include "Arbol.h"
class Lista
{
	//Variables
public:
	Nodo_lis *miembro;
	
	Nodo_lis *bandera;
	//Métodos
public:
	void Insertar(Nodo_lis *&nuevo);
	void imprimir();
	void Insertar_ar(Nodo *elemento,int j);
	//Nodo_lis* Eliminmar(Nodo_lis *a_borrar);
	//void Adelante();
	//void Atras();
	Lista(void);
	~Lista(void);
};

