#pragma once 
#include "Lista.h"
#include "Nodo_lis.h"
#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include "Arbol.h"
#include "Nodo.h"
Lista *&Abrir();
int *Orden_de_nodos(int tamaño);
void guardar(Arbol *&resultado);
//void Ordenar(Nodo_lis &lista,int tamaño);
float exp(int tamaño);
Nodo_lis *copiar(Nodo *copia,int j);