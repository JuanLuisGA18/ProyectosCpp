#pragma once
#include "orden.h"
class Entrega
{
public: 
	int total;
	bool lleno;
	class orden pedido;
	int folio;
public:
	Entrega(void);
	~Entrega(void);
	void pedir();
	virtual void entregar()=0;
	virtual void ticket()=0;

};

