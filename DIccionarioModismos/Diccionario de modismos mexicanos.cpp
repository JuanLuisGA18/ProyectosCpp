// Diccionario de modismos mexicanos.cpp: define el punto de entrada de la aplicación de consola.
//
//Librerias
#include "stdafx.h"
#include "Arbol.h"
#include "Lista.h"
#include "abrir.h"
#include <math.h>
using namespace std;
//Funciones
void guardar(Arbol *&resultado);
Lista *&Abrir();
int *Orden_de_nodos(int tamaño);
//Estructuras
struct info
{
	Nodo_lis el_dato;
	bool usado;
};

//Main
int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	// Se abre el archivo en una lista y se crea un puntero al último elemento
	
	Lista *def=Abrir();
	//Se crea una bandera a la lista
	Nodo_lis *bandera;
	bandera=new Nodo_lis;
	bandera=def->miembro;
	//Se define el número de elementos y se almacena en una variable
	int tamaño=(bandera->identificador+1); 
	info *datos= new info[tamaño];
	//Se regresa la lista al primer elemento
	while(bandera->Ant!=NULL)
	{
		bandera=bandera->Ant;
	}
	//Se guarda cada elemento en una estructua que determina si ha sido usado el dato (será usado más adelante)
	for(i=0;i<tamaño;i++)
	{
		datos[i].el_dato.copiar(bandera);
		datos[i].usado=false;
		//cout<<datos[i].el_dato.palabra;
		bandera=bandera->Sig;
	
	}
	
	delete def;
	int niveles=pow(2,exp(tamaño));
	int *ord=Orden_de_nodos(tamaño);
	int *posicion=new int[niveles];
	for(i=0;i<niveles;i++)
	{
		posicion[i]=*(ord+i);
		//cout<<posicion[i]<<"|";
			//cout<<posicion[i]<<" ";
	}
	//system("pause");
	delete ord;
	Nodo *inicial=new Nodo(datos[posicion[0]].el_dato);
	Arbol *busqueda=new Arbol(inicial);
	//cout<<busqueda->raiz->palabra;
	//system("pause");
	Nodo *band;
	band=busqueda->raiz;
	
	for(i=1;i<niveles;i++)
	{//Inicio for que busca en el arreglo la posición de cada dato
		//Inicio if que revisa que el valor no sea NULL
		if(posicion[i]!=NULL)
		{	
			//cout<<posicion[i];
			int continuar=true;
			
				Nodo *nuevo=new Nodo;
				nuevo->crear(datos[posicion[i]].el_dato);
				//Busqueda de la posicion en el árbol
			while(continuar)
				{
					if(nuevo->clave>band->clave&&band->Hijo_der==NULL)
					{
						busqueda->raiz=band;
						busqueda->Ins_der(nuevo);
						busqueda->Volver();
						band=busqueda->raiz;
						break;
					}
					else if(nuevo->clave<band->clave&&band->Hijo_izq==NULL)
					{
						busqueda->raiz=band;
						busqueda->Ins_izq(nuevo);
						busqueda->Volver();
						band=busqueda->raiz;
						break;
					}
					else if(nuevo->clave>band->clave)
					{
						band=band->Hijo_der;
					}
					else if(nuevo->clave<band->clave)
					{
						band=band->Hijo_izq;
					}
					else if(nuevo->clave==band->clave)
					{
						//cout<<nuevo->clave;
						break;
					}
			}

				
			}//Fin if NULL
	}//Fin for de ubicación
	busqueda->Volver();
	band=busqueda->raiz;
	//system("pause");
	bool menu=true;
	while(menu)
	{
			char opcion[12];
			system("cls");
			cout<<"Diccionario de modismos mexicanos"<<endl;
			cout<<"Seleccione una opci\242n"<<endl;
			cout<<"1) Buscar una palabra"<<endl;
			cout<<"2) Guardar y salir"<<endl;
			cout<<"Nota: Para agregar una nueva palabra primero es necesario buscarla a trav\241s de la opci\242n 1"<<endl;
			cout<<"Su selecci\242n: ";
			gets(opcion);
			switch(opcion[0])
			{
			case '1':
				{//Buscar palabra
					char abuscar[24];
					int clave=0,i=0;
					cout<<"\250Que palabra desea buscar? ";
					gets(abuscar);
					busqueda->busqueda(abuscar);
					busqueda->Volver();
					band=busqueda->raiz;
					break;
				}//Fin buscar palabra
		
			case '2':
				{
					guardar(busqueda);
					menu=false;
					break;
				}
			default:
				{
					cout<<"Opci\242n no valida"<<endl;
					system("pause");
					break;
				}
				//Fin default
		}//fin switch
	}//Fin menu
	return 0;
}//Fin main
 
