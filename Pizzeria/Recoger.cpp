#include "StdAfx.h"
#include "Recoger.h"
using namespace std;

void gotoxy(int x, int y);
Recoger::Recoger(void)
{
}
void Recoger::ticket()
{
	pedido.ticket();
	gotoxy(45,pedido.linea);
	cout<<"Total: "<<pedido.total;
	gotoxy(1,1);
	cout<<"Folio: "<<folio;
	pedido.linea++;
	gotoxy(2,pedido.linea);
	cout<<"Gracias por su compra. Su pedido estar\240 listo en 15 min";
	gotoxy(2,30);
	system("pause");
}
void Recoger::entregar()
{
	pedido.ordenar();
	ticket();
	lleno=true;
	
}
Recoger::~Recoger(void)
{
}
