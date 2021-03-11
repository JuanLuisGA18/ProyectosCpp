#pragma once
#include "Entrega.h"
#include <iostream>
class Recoger :
	public Entrega
{
public:
	void entregar();
	void ticket();
	Recoger(void);
	~Recoger(void);
};

