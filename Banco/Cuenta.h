#pragma once
#include <ctime>
#include<vector>
class Cuenta
{
public:
	char nombre_cliente[30];
	char direccion[30];
	char* fecha;
	char telefono[20];
	float comision;
	int saldo;
private:
	int no_cuenta;
public:
	void Apertura();
	Cuenta(void);
	~Cuenta(void);
	void Deposito();
	void Retiro();
	void Consulta();
	void Acceso();
	
protected:
	void Super_net();
	void Datos();
};

