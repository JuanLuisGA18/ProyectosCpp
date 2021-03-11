#include "StdAfx.h"
#include "Arbol.h"
using namespace std;

Arbol::Arbol(void)
{
}
Arbol::Arbol(Nodo *&inicial)
{
	
	raiz=inicial;
	raiz->Padre==NULL;
	raiz->Hijo_der=NULL;
	raiz->Hijo_izq=NULL;
}
void Arbol::busqueda(char palabra[24])
{
	bool continuar=true;
	int i=0,clave=0;
	while(i<24&&palabra[i]!=NULL)
	{//while obtener clave
		clave+=palabra[i];
		i++;
	}//Fin while obtener clave
	clave+=NULL;
	while(continuar)
		
		{//While principal
				if(clave==raiz->clave)
			{//Si se encuentra una coincidencia
				raiz->Imprimir();
				break;
			}//Fin si se encuentra una coincidencia
			else if(clave>raiz->clave&&raiz->Hijo_der==NULL)
			{//Si no sé encuentra y el siguinete lugar es la derecha
				bool agregar=true;
				while(agregar)
				{//Menú para agregar una nueva palabra
					char opcion[24];
					cout<<"La definici\242n no se encuentra registrada \250Desea agregarla? 1 si, 2 no: ";
					gets(opcion);
					switch(opcion[0])
					{//Evaluación de las opciones
					case '1':
						{//Sí si se desea agregar la definición
							int i=0;
							Nodo *nuevo= new Nodo;
							
							while(i<23&palabra[i]!=NULL)
							{//Se copia la palabra
								nuevo->palabra[i]=palabra[i];
								i++;
							}//Fin copiar la palabra
							nuevo->palabra[i]=NULL;
							nuevo->clave=clave;
							nuevo->identificador=NULL;
							cout<<"\250Como define esta palabra? ";
							gets(nuevo->definicion);
							//Se agrega el nodo al árbol
							Ins_der(nuevo);
							Volver();
							agregar=false;
							break;
						}//Fin agregar palabra
					case '2':
						{//Si no se desea agregar la palabra
							Volver();
							agregar=false;
							break;
						}//Fin no agregar palabra
					default :
						{
							cout<<"Se ingreso un valor no valido, vuelva a capturar"<<endl;
							break;
						}
					}//Fin casos posibles
				}//Fin while de opción
				break;
			}//Fin agregar a la derecha
			else if(clave<raiz->clave&&raiz->Hijo_izq==NULL)
			{//Si no se encuentra la palabra y su lugar es a la derecha
				bool agregar=true;
				while(agregar)
				{//Menú para agregar una nueva palabra
					char opcion[24];
					cout<<"La definici\242n no se encuentra registrada \250Desea agregarla? 1 si, 2 no: ";
					gets(opcion);
					switch(opcion[0])
					{//Evaluación de las opciones
					case '1':
						{//Sí si se desea agregar la definición
							int i=0;
							Nodo *nuevo= new Nodo;
							
							while(i<23&palabra[i]!=NULL)
							{//Se copia la palabra
								nuevo->palabra[i]=palabra[i];
								i++;
							}//Fin copiar la palabra
							nuevo->palabra[i]=NULL;
							nuevo->clave=clave;
							nuevo->identificador=NULL;
							cout<<"\250Como define esta palabra? ";
							gets(nuevo->definicion);
							//Se agrega el nodo al árbol
							Ins_izq(nuevo);
							Volver();
							agregar=false;
							break;
						}//Fin agregar palabra
					case '2':
						{//Si no se desea agregar la palabra
							Volver();
							agregar=false;
							break;
						}//Fin no agregar palabra
					default :
						{
							cout<<"Se ingreso un valor no valido, vuelva a capturar"<<endl;
							break;
						}//Fin default
					}//Fin casos posibles
				}//Fin while de opción
				break;
			}//Fin agregar a la izquierda
			else if(clave>raiz->clave)
			{//Si es mayor se desplasa a la derecha
			//	cout<<raiz->palabra;
				raiz=raiz->Hijo_der;

			}//Fin derecha
			else if(clave<raiz->clave)
			{//Si es menor se desplaza a la izquierda
			//	cout<<raiz->palabra;
				raiz=raiz->Hijo_izq;
			}//Fin izquierda
			
	}//fin while principal
}//Fin función
void Arbol::Ins_der(Nodo *&elemento)
{
	elemento->Padre=raiz;
	elemento->Hijo_der=NULL;
	elemento->Hijo_izq=NULL;
	raiz->Hijo_der=elemento;
	raiz=elemento;
	raiz->fin=false;

}
void Arbol::Ins_izq(Nodo *&elemento)
{
	
	
	elemento->Padre=raiz;
	elemento->Hijo_der=NULL;
	elemento->Hijo_izq=NULL;
	raiz->Hijo_izq=elemento;
	raiz=elemento;
	raiz->fin=false;
}
void Arbol::Volver()
{
	while(raiz->Padre!=NULL)
	{
		raiz=raiz->Padre;
		//cout<<raiz->palabra;
	}
}
Arbol::~Arbol(void)
{
}
