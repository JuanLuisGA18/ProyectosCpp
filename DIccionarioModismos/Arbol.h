#pragma once
#include "Nodo.h"
#include "Lista.h"
class Arbol
{
	//Variables
public:
	Nodo *raiz;

//Métodos
public:
	void Ins_der(Nodo *&elemento);
	void Ins_izq(Nodo *&elemento);
	void busqueda(char palabra[24]);
	void Volver();
	Arbol(void);
	Arbol(Nodo *&inicial);
	~Arbol(void);
};

