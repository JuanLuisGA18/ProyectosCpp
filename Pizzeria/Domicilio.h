#pragma once
#include "Entrega.h"
#include<iostream>
class Domicilio :
	public Entrega
{
public:
	Domicilio(void);
	~Domicilio(void);
	void entregar();
	void ticket();
	
};

