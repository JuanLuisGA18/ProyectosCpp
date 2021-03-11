#pragma once
#include "Cuenta.h"
class Cuenta_universitario:protected Cuenta
{
protected:
	char nombre_universidad[30];
	
public:
	void Apertura_cuenta_univeritaria();
	void Supernet_universitaria();
	void Consultar_saldo();
	void Realizar_pagos();
	void menu();
	void Datos_uni();
	Cuenta_universitario(void);
	~Cuenta_universitario(void);
};

