#pragma once
#include <iostream>
class orden
{
public :
	int total;
	int linea;
private:
	int **pizza;
	int *bebida;
	int *complemento;
	int num_piz;
	int num_beb;
	int num_comp;
	int *tam_piz;

public:
	void ordenar();

	void ticket();
	orden(void);
	~orden(void);
private:
	void calcular_total();
	void ordenar_pizza();
	void ordenar_complemento();
	void ordenar_bebida();
	
};

