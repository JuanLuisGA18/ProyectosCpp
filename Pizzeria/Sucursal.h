#pragma once
#include "entrega.h"
#include <iostream>
class Sucursal :
	public Entrega
{
public:
	char mesero[30];
public:
	void entregar();
	void ticket();
	Sucursal(void);
	~Sucursal(void);
};

