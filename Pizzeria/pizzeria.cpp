// pizzeria.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>;
#include "orden.h"
#include"Domicilio.h"
#include"Entrega.h"
#include"Recoger.h"
#include"Sucursal.h"

using namespace std;
void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}
void reporte()
{
		gotoxy(20,0);
		cout<<"La pizza fel\241z";
		gotoxy(20,1);
		cout<<"Reporte de ventas";
		gotoxy(1,2);
		cout<<"Folio";
		gotoxy(10,2);
		cout<<"Tipo de servicio";
		gotoxy(35,2);
		cout<<"Total";
		gotoxy(45,2);
		cout<<"Notas";
}
int _tmain(int argc, _TCHAR* argv[])
{
	Domicilio dom[20];
	Sucursal suc[20];
	Recoger rec[20];
	int reco=0, sucu=0, domi=0, opc,opci,it,linea=3;
	bool encendido=true, pedido=true;
	while(encendido)
	{
		system("cls");
		cout<<"\250Que desea hacer?"<<endl;
		cout<<"1) Crear un nuevo pedido"<<endl;
		cout<<"2) Consultar ventas"<<endl;
		cout<<"3) Consultar folio"<<endl;
		cin>>opc;
		switch(opc)
		{
		case 1:
			{
				while(pedido)
				{
					system("cls");
					cout<<"\250Que tipo de entrega es?"<<endl;
					cout<<"1) A domicilio"<<endl;
					cout<<"2) A recoger en sucursal"<<endl;
					cout<<"3) Para comer en sucursal"<<endl;
					cin>>opci;
					switch(opci)
					{
					case 1:
						{
						
							dom[domi].folio=domi;
							dom[domi].entregar();
							gotoxy(1,1);
							domi++;
							pedido=false;
							break;
						}
					case 2:
						{
							rec[reco].folio=reco;
							rec[reco].entregar();
							gotoxy(1,1);
						
							
							reco++;
							pedido=false;
							break;
						}
					case 3:
						{
							suc[sucu].folio=sucu;
							suc[sucu].entregar();
							gotoxy(1,1);
							sucu++;
							pedido=false;
							break;
						}
					default:
						{
							cout<<"opci\243n no valida, vuelva a capturar"<<endl;
							break;
						}
					}
				}
				pedido=true;
				break;
			}
		case 2:
			{
				system("cls");
				reporte();
				for(it=0;it<domi;it++)
				{
					if(dom[it].lleno)
					{
						gotoxy(1,linea);
						cout<<dom[it].folio;
						gotoxy(10,linea);
						cout<<"Domicilio";
						gotoxy(35,linea);
						cout<<dom[it].pedido.total;
						linea++;
					}
					else
					{
						break;
					}
				}
				for(it=0;it<reco;it++)
				{
					if(rec[it].lleno)
					{
						gotoxy(1,linea);
						cout<<rec[it].folio;
						gotoxy(10,linea);
						cout<<"Recoger en sucursal";
						gotoxy(35,linea);
						cout<<rec[it].pedido.total;
						linea++;
					}
					else
					{
						break;
					}
				}
				for(it=0;it<sucu;it++)
				{
					if(suc[it].lleno)
					{
						
						gotoxy(1,linea);
						cout<<suc[it].folio;
						gotoxy(10,linea);
						cout<<"Consumo en sucursal";
						gotoxy(35,linea);
						cout<<suc[it].pedido.total;
						gotoxy(45,linea);
						cout<<"Atendi\242: "<<suc[it].mesero;
						linea++;

					}
					else
					{
						break;
					}
				}
				gotoxy(2,linea);
				system("pause");
				break;
			}
		case 3:
			{
				int servicio,folio=-1;
				bool ser=true;
				
				while(ser)
				{
				system("cls");
				cout<<"¿Que tipo de servicio fue?"<<endl;
				cout<<"1) Servicio a domicilio"<<endl;
				cout<<"2) Recoger en sucursal"<<endl;
				cout<<"3) Consumo en sucursal"<<endl;
				cin>>servicio;
				if(servicio>0&&servicio<4)
				{

				switch(servicio)
				{		
				case 1:
					{
							if(domi>0)
							{
								cout<<"Ingrese el folio ";
								cin>>folio;
								if(folio>domi||folio<0)
								{
									cout<<"Error folio no encontrado o inexistente";
								}
								else
								{
									dom[folio].ticket();
								}
							}
							else
							{
								cout<<"Error no hay folos existentes"<<endl;
								system("pause");
							}


							break;
						}
					case 2:
					{
						if(reco>0)	
						{	
								cout<<"Ingrese el folio ";
									cin>>folio;
									if(folio>reco||folio<0)
									{
										cout<<"Error folio no encontrado o inexistente";
									}
									else
									{
										rec[folio].ticket();
									}
							}
							else
							{
								cout<<"Error no hay folos existentes"<<endl;
								system("pause");
							}
							break;
						}
						case 3:
						{
							if(sucu>0)	
							{
								cout<<"Ingrese el folio ";
								cin>>folio;
								if(folio>sucu||folio<0)
								{
									cout<<"Error folio no encontrado o inexistente";
								}
								else
								{
									suc[folio].ticket();
								}
							}
							else
							{
								cout<<"Error no hay folos existentes"<<endl;
								system("pause");
							}
							break;
						}
					
					}
					break;
				}
						else
						{
							cout<<"Opci\242n no valida";
						}
					}
					break;
			}
		default:
			{
				cout<<"opci\243n no valida, vuelva a capturar"<<endl;;
				
				break;
			}
		}
		system("cls");
	}
		
	return 0;
}

