#pragma once
#include <iostream>
#include "Nodo_lis.h"
class Nodo
{
	//Variables
public:
	int identificador;
	char palabra[24];
	char definicion[250];
	int clave;
	Nodo *Hijo_izq;
	Nodo *Hijo_der;
	Nodo *Padre;
	bool fin;
	//Metodos
public:
	void Imprimir();
	Nodo(void);
	Nodo(Nodo_lis base);
	void crear(Nodo_lis base);
	Nodo(char pal[24], char def[250]);
	~Nodo(void);
	bool recorrido();
};

