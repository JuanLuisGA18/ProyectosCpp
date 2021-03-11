#pragma once
#include <iostream>
class Nodo_lis
{
	//Variables
public:
	char palabra[24];
	char definicion[250];
	int clave;
	int identificador;
	Nodo_lis *Sig;
	Nodo_lis *Ant;
	//Metodos
public:
	void imprimir();
	void copiar(Nodo_lis *&copia);
	void copiar2(Nodo_lis copia);
	Nodo_lis(void);
	~Nodo_lis(void);
	//void Insertar(Nodo_lis *nuevo);
	//void Imprimir();
	
};

