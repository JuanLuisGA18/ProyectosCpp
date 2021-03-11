#include "StdAfx.h"
#include "Sucursal.h"
using namespace std;
void gotoxy(int x, int y);
Sucursal::Sucursal(void)
{
}
void Sucursal::ticket()
{
	pedido.ticket();
	gotoxy(45,pedido.linea);
	cout<<"Total: "<<pedido.total;
	gotoxy(1,1);
	cout<<"Folio: "<<folio;
	pedido.linea++;
	gotoxy(2,pedido.linea);
	cout<<"Gracias por su compra. Atendi\242: "<<mesero;
	gotoxy(2,30);
	system("pause");
}
void Sucursal::entregar()
{
	cin.ignore();
	cout<<"\250Quien atiende? ";
	gets(mesero);
	pedido.ordenar();
	ticket();
	lleno=true;
	
}


Sucursal::~Sucursal(void)
{
}
