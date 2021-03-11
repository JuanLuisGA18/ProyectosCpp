#include "StdAfx.h"
#include "orden.h"
using namespace std;

orden::orden(void)
{
	total=0;
	linea=3;
}
void gotoxy(int x, int y);

void orden::ticket()
{
	system("cls");
	gotoxy(10,0);
	cout<<"La pizza fel\241z";
	gotoxy(10,1);
	cout<<"Ticket de compra";
	gotoxy(2,2);
	cout<<"Producto";
	gotoxy(25,2);
	cout<<"Canidad";
	gotoxy(37,2);
	cout<<"Precio unitario";
	gotoxy(58,2);
	cout<<"Total";
	calcular_total();

}

void orden::ordenar()
{
	ordenar_pizza();
	ordenar_bebida();
	ordenar_complemento();
	

}
//Inicio calcular total
void orden::calcular_total()
{
	
	int i,j,tam,tipo;
	int tipo1=0, tipo2=0, tipo3=0;
	for(i=0;i<num_piz;i++)
	{
		tam=tam_piz[i];
		switch(tam)
		{
		case 1:
			{
			tipo1++;
			total+=75;	
			break;
			}
		case 2:
			{
			tipo2++;
			total+=100;	
			break;
			}
		case 3:
			{
			tipo3++;
			total+=125;	
			break;
			}
		}
	}
	if(tipo1>0)
	{
		gotoxy(2,linea);
		cout<<"Pizza chica";
		gotoxy(25,linea);
		cout<<tipo1;
		gotoxy(37,linea);
		cout<<tipo1<<" * 75";
		gotoxy(58,linea);
		cout<<tipo1*75;
		linea++;
	}
	if(tipo2>0)
	{
		gotoxy(2,linea);
		cout<<"Pizza mediana";
		gotoxy(25,linea);
		cout<<tipo2;
		gotoxy(37,linea);
		cout<<tipo2<<" * 100";
		gotoxy(58,linea);
		cout<<tipo2*100;
		linea++;
	}
	if(tipo3>0)
	{
		gotoxy(2,linea);
		cout<<"Pizza grande";
		gotoxy(25,linea);
		cout<<tipo3;
		gotoxy(37,linea);
		cout<<tipo3<<" * 125";
		gotoxy(58,linea);
		cout<<tipo3*125;
		linea++;
	}
	tipo1=0;
	tipo2=0;
	tipo3=0;
	for(i=0;i<num_piz;i++)
		{//Inicio for i
			for(j=0;j<4;j++)
			{//Inicio for j
				tipo=pizza[i][j];
				switch(tipo)
					//Inicio switch ingredientes
				{
				case 0:
						{
							break;
						}
				case 1:
						{
							tipo1++;
							total+=15;
							break;
						}
				
				}	//Fin switch ingredientes
		
			}//fin for j
		}//Fin for i
	if(tipo1>0)
	{
		gotoxy(2,linea);
		cout<<"Ingrediente extra";
		gotoxy(25,linea);
		cout<<tipo1;
		gotoxy(37,linea);
		cout<<tipo1<<" * 15";
		gotoxy(58,linea);
		cout<<tipo1*15;
		linea++;
	}
	tipo1=0;
	tipo2=0;
	tipo3=0;
		for(i=0;i<num_beb;i++)
		{
			tipo=bebida[i];
			switch(tipo)
			{
			case 1:
				 {
					 tipo1++;
					total+=15;
					 break;
				 }
			case 2:
				 {
					tipo2++;
					 total+=10;
					 break;
				 }
			case 3:
				 {
					 tipo3++;
					 total+=12;
					 break;
				 }
			}
		}
	if(tipo1>0)
	{
		gotoxy(2,linea);
		cout<<"Soda";
		gotoxy(25,linea);
		cout<<tipo1;
		gotoxy(37,linea);
		cout<<tipo1<<" * 15";
		gotoxy(58,linea);
		cout<<tipo1*15;
		linea++;
	}
	if(tipo2>0)
	{
		gotoxy(2,linea);
		cout<<"Agua";
		gotoxy(25,linea);
		cout<<tipo2;
		gotoxy(37,linea);
		cout<<tipo2<<" * 10";
		gotoxy(58,linea);
		cout<<tipo2*10;
		linea++;
	}
	if(tipo3>0)
	{
		gotoxy(2,linea);
		cout<<"Jugo";
		gotoxy(25,linea);
		cout<<tipo3;
		gotoxy(37,linea);
		cout<<tipo3<<" * 12";
		gotoxy(58,linea);
		cout<<tipo3*12;
		linea++;
	}
	tipo1=0;
	tipo2=0;
	tipo3=0;
		for(i=0;i<num_comp;i++)
		{
			
			tipo=complemento[i];
			switch(tipo)
			{
			case 1:
				 {
					 tipo1++;
					total+=20;
					 break;
				 }
			case 2:
				 {
					 tipo2++;
					 total+=25;
					 break;
				 }
			case 3:
				{
					tipo3++;
					total+=30;
				
					 break;
				 }
			}
		}
if(tipo1>0)
	{
		gotoxy(2,linea);
		cout<<"Nachos";
		gotoxy(25,linea);
		cout<<tipo1;
		gotoxy(37,linea);
		cout<<tipo1<<" * 20";
		gotoxy(58,linea);
		cout<<tipo1*20;
		linea++;
	}
	if(tipo2>0)
	{
		gotoxy(2,linea);
		cout<<"Papas";
		gotoxy(25,linea);
		cout<<tipo2;
		gotoxy(37,linea);
		cout<<tipo2<<" * 25";
		gotoxy(58,linea);
		cout<<tipo2*25;
		linea++;
	}
	if(tipo3>0)
	{  
		gotoxy(2,linea);
		cout<<"Roles de canela";
		gotoxy(25,linea);
		cout<<tipo3;
		gotoxy(37,linea);
		cout<<tipo3<<" * 30";
		gotoxy(58,linea);
		cout<<tipo3*30;
		linea++;
	}
	tipo1=0;
	tipo2=0;
	tipo3=0;
	}//Fin calcular total
void orden::ordenar_pizza()
	//Inicio ordenar pizza
{
	int ing,tam,i,j=0;
	bool menu=true, ord=true;
	cout<<"\250Cuantas pizzas desea ordenar?"<<endl;
	cin>>num_piz;
	
		//inicio condición número positivo
	while(ord)
	{	
	if(num_piz>0)
		{
			tam_piz=new int [num_piz];
			pizza = new int*[num_piz];
			//Creación matriz pizza
			for(i=0;i<num_piz;i++)
			{
				pizza[i]=new int[4];
			}
			//fin creación matriz pizza
			i=0;
			//while pedir pizza
	
			while(i<num_piz)
			{
				system("cls");
				cout<<"\250De que tamaño desea la pizza no."<<i+1<<"?"<<endl;
				cout<<"1 chica, 2 mediana, 3 grande ";
				cin>>tam;
				//inicio condición tamaño pizza
				if(tam>0&&tam<4)
				{
					cout<<"La pizza no. "<<i+1<<" es de tamaño "<<tam<<endl;
					tam_piz[i]=tam;
						while(menu)
						{
							cout<<"\250Desea agregar jam\242n? 1=si, 0=no "<<endl;
							cin>>ing;
							if(ing==1)
							{
								cout<<"jam\242n agregado correctamente"<<endl;
								pizza[i][0]=ing;
								break;
							}
							if(ing==0)
							{
								cout<<"pizza sin jam\242n"<<endl;
								pizza[i][0]=ing;
								break;
							}
							else
							{
								cout<<"error opci\242n no valida"<<endl;

							}
						}
						while(menu)
						{
							cout<<"\250Desea agregar peperoni? 1=si, 0=no"<<endl;
							cin>>ing;
						if(ing==1)
							{
								cout<<"peperoni agregado correctamente"<<endl;
								pizza[i][0]=ing;
								break;
							}
							if(ing==0)
							{
								cout<<"pizza sin peperoni"<<endl;
								pizza[i][0]=ing;
								break;
							}
							else
							{
								cout<<"error opci\242n no valida"<<endl;
							}
						}

						while(menu)
						{
							cout<<"\250Desea agregar champiñones? 1=si, 0=no"<<endl;
							cin>>ing;
							if(ing==1)
							{
								cout<<"Champiñones agregados correctamente"<<endl;
								pizza[i][2]=ing;
								break;
							}
							if(ing==0)
							{
								cout<<"pizza sin champiñones"<<endl;
								pizza[i][2]=ing;
								break;
							}
							else
							{
								cout<<"error opci\242n no valida"<<endl;
							}
						}
						while(menu)
						{
							cout<<"\250Desea agregar rajas? 1=si, 0=no"<<endl;
							cin>>ing;
							if(ing==1)
							{
								cout<<"rajas agregadas correctamente"<<endl;
								pizza[i][3]=ing;
								break;
							}
							if(ing==0)
							{
								cout<<"pizza sin rajas"<<endl;
								pizza[i][3]=ing;
								break;
							}
						else
							{
								cout<<"error opci\242n no valida"<<endl;
								system("pause");
							}
							
						}
						i++;
				}
						//Fin condición tamaño
				
				//Fin while pedir pizza

			//Inicio condición error de tamaño de pizza
			else
			{
				cout<<"Error vuelva a capturar"<<endl;
				system("pause");
			}
				
			}
			//Fin error de tamaño de pizza
			
			}//Fin condición número positivo
			//Inicio condición si es negativo
		if(num_piz<0)
		{
			cout<<"No pude haber pizzas negativas"<<endl;
			system("pause");
		}
		//Fin condición si es negativo
		if(num_piz==0)
		{
			break;
		}
		if(i>=num_piz)
		{
			break;
		}
	}
}
	//fin ordenar pizza
void orden::ordenar_complemento()
{
	int tipo, i=0;
	bool ord=true;
	system("cls");
	cout<<"\250Cuantos complementos desea ordenar? ";
	cin>>num_comp;
	while(ord)
	{
		if(num_comp>0)
		{
			complemento=new int [num_comp];
			while(i<num_comp)
			{
				cout<<"\250Que complemento es el no. "<<i+1<<"?"<<endl;
				cout<<"1 Nachos, 2 Papas o 3 roles de canela ";
				cin>>tipo;
		
				if(tipo<=3&&tipo>=1)
				{
					
					complemento[i]=tipo;
					i++;
				}
				else
				{
					cout<<"Opcio\242n no valida"<<endl;
					system("pause");
				}
				if(i==num_comp)
				{
				ord=false;
				break;
				}
			}
		}
		if(num_comp<0)
		{
			cout<<"Error no puede haber unidades negativas"<<endl;
			system("pause");
		}
		if(num_comp==0)
		{
			ord=false;
			break;
		}
		if(num_comp==i)
		{
			break;		}
	}
}
void orden::ordenar_bebida()
{
	int tipo, i=0;
	bool ord=true;
	system("cls");
	cout<<"\250Cuantas bebidas desea ordenar? ";
	cin>>num_beb;
	while(ord)
	{
		if(num_beb>0)
		{
			bebida=new int [num_beb];
			while(i<num_beb)
			{
				cout<<"\250Que bebida es la no. "<<i+1<<"?"<<endl;
				cout<<"1 soda, 2 agua o 3 jugo"<<endl;
				cin>>tipo;
		
				if(tipo<=3&&tipo>=1)
				{
					
					bebida[i]=tipo;
					i++;
				}
				else
				{
					cout<<"Opcio\242n no valida"<<endl;
					system("pause");
				}
				if(i==num_beb)
				{
				ord=false;
				break;
				}
			}
		}
		if(num_beb<0)
		{
			cout<<"Error no puede haber unidades negativas"<<endl;
			system("pause");
		}
		if(num_beb==0)
		{
			ord=false;
			break;
		}
		if(i==num_beb)
		{
			break;
		}
	}
}
orden::~orden(void)
{
}