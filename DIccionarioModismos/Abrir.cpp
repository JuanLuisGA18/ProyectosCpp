#include "stdafx.h"
#include"abrir.h"
using namespace std;
/*Nodo_lis* Ordenar(Nodo_lis *&lista,int tamaño)
{
	
	for(i=0;i<tamaño;i++)
	{
		if(i<tamaño-1)
		{
			if(datos[i].clave>datos[i].clave)
			{
				cout<<"Otra vuelta";
				Ordenar(datos,tamaño);
			}
		}
	}
	for(i=0;i<tamaño;i++)
	{
		cout<<datos[i].palabra;
	}
	return datos;
}*/
bool salida(Nodo *band)
{
	if(band->Hijo_der==NULL&&band->Hijo_izq==NULL&&band->Padre==NULL)
	{
		return false;
	}
	else if((band->Hijo_der!=NULL&&band->Hijo_izq!=NULL))
	{
		if(band->Hijo_der->fin==true&&band->Hijo_izq->fin==true&&band->Padre==NULL)
		return false;
	}
	else 
	return true;
}
void guardar(Arbol *&resultado)
{
	Lista *AGuardar=new Lista;
	Nodo *band=resultado->raiz;
	Nodo_lis *bandera;
	AGuardar->miembro=copiar(band,0);
	int j=1;
	int i;
	while(salida(band))
	{//Fin while crar lista
		//cout<<"a";
		//¿Hijo derecho nulo?
		if(band->Hijo_der==NULL)
		{//Si
			//¿Hijo izquierdo nulo?
			if(band->Hijo_izq==NULL)
			{//si
				
					//nuevo=copiar(band,j);
					AGuardar->Insertar_ar(band,j);
					band->fin=true;
					j++;
					//cout<<AGuardar->miembro->palabra;
					if(band->Padre!=NULL)
					{
						band=band->Padre;
					}
			}//fin hijo izquierdo nulo 2
			else
			{//No
				//¿Hijo izquierdo usado?
				if(band->Hijo_izq->fin==true)
				{//si
				
					//nuevo=copiar(band,j);
					AGuardar->Insertar_ar(band,j);
					j++;
					band->fin=true;
					if(band->Padre!=NULL)
					{
						band=band->Padre;
					}
				}//Fin hijo izquierdo usado 3
				else
				{//No
					band=band->Hijo_izq;
				}//Fin hijo izquierdo usado 3
			}
		}//Fin hijo derecho nulo 1
		else
		{//Hijo derecho no es nulo 1
			//¿Hijo derecho usado?
			if(band->Hijo_der->fin==true)
			{
				//¿Hijo izquierdo nulo?
				if(band->Hijo_izq==NULL)
				{//Si
					//nuevo=copiar(band,j);
					
					
					AGuardar->Insertar_ar(band,j);
					j++;
					band->fin=true;
					if(band->Padre!=NULL)
					{
						band=band->Padre;
					}
				}// fin si hijo izquierdo nulo
				else
				{//Hijo izquierdo no nulo
					//¿Hijo izquierdo usado?
					if(band->Hijo_izq->fin==true)
					{//Si
					AGuardar->Insertar_ar(band,j);
					//nuevo
					j++;
					band->fin=true;
						if(band->Padre!=NULL)
						{
							band=band->Padre;
						}
					}
					else
					{
						band=band->Hijo_izq;
					}

				}
			}
			else
			{
				band=band->Hijo_der;
			}
		}
	
		//cout<<"No se agreaga";
	}//Fin while crear lista
	j=AGuardar->miembro->identificador;
	bandera=AGuardar->miembro;
	//cout<<j;
	//system("pause");
	Nodo_lis *ordenados =new Nodo_lis[j];
	while(bandera->Ant!=NULL)
	{
		bandera=bandera->Ant;
		//cout<<"a";
	}
	for(i=0;i<j;i++)
	{//Inicio guardar en arreglo
		ordenados[i].copiar(bandera);
		//cout<<ordenados[i].palabra<<endl;
		bandera=bandera->Sig;
			
	}//Guardar en arreglo
	//system("pause");
	
	int k,flag;
	Nodo_lis aux;
	
	for(i=0;i<j;i++)
	{
		flag=i;
		for(k=0;k<j;k++)
		{
			if(ordenados[i].clave>ordenados[k].clave)
			{
				flag=k;
			}
		}
		aux.copiar2(ordenados[i]);
		ordenados[i].copiar2(ordenados[flag]);
		ordenados[flag].copiar2(aux);
		
	}
	/*for(i=0;i<j;i++)
	{//Inicio guardar en arreglo
		//ordenados[i].copiar(bandera);
		cout<<ordenados[i].palabra<<endl;
		//bandera=bandera->Sig;
			
	}//Guardar en arreglo*/
	//system("pause");
	ofstream archivo;
	archivo.open("Diccionario.txt",ios::out);
	if(archivo.fail())
	{//Inicio si no se creo el archivo
		cout<<"Error";
		system("pause");
		//exit(1);
	}//Si no se creo el archivo
	else
	{//Else crear archivo
		for(i=0;i<j;i++)
		{//Inicio guardar en archivo
			archivo<<ordenados[i].palabra;
			archivo<<"|";
			archivo<<ordenados[i].definicion;
			archivo<<endl;
		}//Guardar en archivo
	}//Fin crear archivo
}//Fin función guardar
Nodo_lis* copiar(Nodo *copia,int j)
{
	static Nodo_lis *nuevo=new Nodo_lis;
	int i=0;
	nuevo->clave=copia->clave;
	nuevo->identificador=j;
	while(i<24&&copia->palabra[i]!=NULL)
	{
		nuevo->palabra[i]=copia->palabra[i];
		i++;
	}
	nuevo->palabra[i]=NULL;
	i=0;
	while(i<250&&copia->definicion[i]!=NULL)
	{
		nuevo->definicion[i]=copia->definicion[i];
		i++;
	}
	nuevo->definicion[i]=NULL;
	return nuevo;
}
Lista *&Abrir()
{
	//cout<<"Ingrese la ruta del archivo con las definiciones ";
	//char ruta[250];
	//gets(ruta);
	ifstream diccionario;
	diccionario.open("Diccionario.txt");
	char letra;
	//Se combrueba que se haya abierto el archivo
	if(diccionario.fail())
	{
		cout<<"Archivo no abierto";
			system("pause");
			exit(2);
	}
	diccionario.get(letra);
	Lista *def=new Lista;
	Nodo_lis *ptr;
	int i=0,j=1;
	//Captura de datos
	while(!diccionario.eof())
		{
			//Se crea un nuevo nodo de la lista
			
			//Se le asigna un identificador
			ptr= new Nodo_lis;;
			ptr->Ant=NULL;
			ptr->Sig=NULL;
			ptr->identificador=j;
			//Se lee la palabra
			i=0;
			while(letra!='|'&&i<24)
			{
				ptr->palabra[i]=letra;
				diccionario.get(letra);
				i++;
				if(letra=='|')
				{
					break;
				}
				
				
			}
			ptr->palabra[i]=NULL;
			i=0;
			//Se crea la clave de la palabra dentro del árbol
				while(ptr->palabra[i]!=NULL)
				{
					ptr->clave+=ptr->palabra[i];
					i++;
				}
				diccionario.get(letra);
				//Captura de la definición
				i=0;
				while(letra!='\n'&&i<250)
				{
					ptr->definicion[i]=letra;
					
					diccionario.get(letra);
					
					i++;
				}
					ptr->definicion[i]=NULL;
					if(!diccionario.eof())
					{
					diccionario.get(letra);
					}
					j++;
					/*cout<<ptr->palabra<<endl;
					cout<<ptr->definicion<<endl;
					system("pause");*/
					def->Insertar(ptr);
					//def->imprimir();
					//def->imprimir();
					//system("pause");
				}
	//Nodo_lis *bandera;
	//bandera=def->miembro->Ant;
//	def->Atras();
	//bandera->imprimir();
	//def->imprimir();
	//system("pause");
	//Fin while captura de datos
	diccionario.close();
	return def;
	
	
}//Fin función de apertura de archivo
float exp(int tamaño)
{
	float niveles=0;
	while(tamaño>1)
	{
		tamaño=(tamaño%2+tamaño)/2;
		niveles++;
	}
	return niveles;
}
int *Orden_de_nodos(int tamaño)
{
	int i;
	int *cantidad,tam=tamaño,niv2=0;
	float nivel=0;
	//Se define la cantidad de niveles del árbol
	while(tam>1)
	{
		nivel++;
		niv2++;
		tam=(tam%2+tam)/2;
	}
	cantidad =new int[niv2];
	i=0;
	//Se obtiene la cantidad a sumar o restar en cada nivel
	tam=tamaño;
	
	while(tam>1)
	{
		tam=(tam%2+tam)/2;
		cantidad[i]=tam;
		i++;
	}
	
	int exp=pow(2,nivel);
	static int *ord=new int[exp];
	bool *usado=new bool[tamaño];
	for(i=0;i<tamaño;i++)
	{
		usado[i]=false;
	}
	int i1=0,i2=1,i3=2;
	int niv3=0;
	for(i=0;i<exp;i++)
	{
		ord[i]=NULL;
	}
	ord[i1]=(tamaño-cantidad[niv3]);
	usado[ord[i1]]=true;
	niv3++;
	
	float n=1;
	while(i3<exp)
	{
		if(ord[i1]!=NULL&&(ord[i1]-cantidad[niv3])>=0&&!usado[ord[i1]-cantidad[niv3]])
		{
		
			ord[i2]=(ord[i1]-cantidad[niv3]);
			usado[ord[i2]]=true;
		
		}
		else
		usado[i2]=NULL;
		

		if(ord[i1]!=NULL&&(ord[i1]+cantidad[niv3])>=0&&!usado[ord[i1]+cantidad[niv3]])
		{
		
		ord[i3]=(ord[i1]+cantidad[niv3]);
		usado[ord[i3]]=true;
		}
		else
		ord[i3]=NULL;
		//ord[i3]=NULL;
		//orden[ord[i3]].usado=true;
		i1+=1;
		i2+=2;
		i3+=2;
		if(i1==pow(2,n)-1)
		{
			niv3++;
			n++;
			
		}
	}
	return ord;
}