#include "StdAfx.h"
#include "Domicilio.h"
using namespace std;

void gotoxy(int x,int y);
Domicilio::Domicilio(void)
{
}
void Domicilio::ticket()
{
	pedido.ticket();
	gotoxy(2,pedido.linea);
	cout<<"Comisi\242n entrega domicilio          ";
	cout<<"$50";
	gotoxy(1,1);
	cout<<"Folio: "<<folio;
	pedido.linea++;
	pedido.total+=50;
	gotoxy(45,pedido.linea);
	cout<<"Total: "<<pedido.total;
	pedido.linea++;
	gotoxy(2,pedido.linea);
	cout<<"Gracias por su compra";
	gotoxy(2,30);
	system("pause");
	system("cls");
}
void Domicilio::entregar()
{
	
	pedido.ordenar();
	ticket();
	lleno=true;

}

Domicilio::~Domicilio(void)
{
}
