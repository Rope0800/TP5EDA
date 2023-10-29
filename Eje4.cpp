/* En el programa trabajamos ahora con objetos de la clase Queue,
a. Dada una fila A, Invertirla. Mostrar ambas filas. (usar fila auxiliar si lo necesita)
b. Utilizando las operaciones de pila y de Fila, COPIE el contenido de una pila P, a una
Fila C, de tal manera que el primer elemento de la Fila será el elemento “F” que se
encuentra en el fondo de la pila, el segundo de la Fila el que está apilado sobre “F”,
y así siguiendo. De esta forma el elemento del tope de la pila quedará en el último
lugar de la Fila. (Para resolver este ejercicio, use pila auxiliar)
c. Ahora queremos buscar si el número entero X determinar está en la Fila A. La Fila A
deberá quedar en su estado original al finalizar el algoritmo.
d. Además de la Fila A cree la fila B, vacíe la fila A y cargue A y B con elementos
ordenados, realice un algoritmo que inserte los elementos de la fila A y B en otra
fila C de manera tal que queden ordenados.
e. Dada una fila C que contiene elementos repetidos consecutivos. Formar otra con
los elementos de la fila dada eliminando los repetidos. 
*/
#include <math.h>
#include <cstdlib>
#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX=3;
struct cola{
   
	int Fila[MAX];  
    int cantidad=0;
    int P=0;
    int U=-1;

   
  public:
  	
	bool ColaVacia (){  
		bool error;
		if (cantidad==0)
		error = true;
		else
		error = false;
		return error;
	}
	
	bool ColaLlena (){
		bool error;
		if (cantidad==MAX)
		error = true;
		else{
			error=false;
			}
			return error;
		}
		
	void Encolar(int dato){
			if (cantidad!=MAX){
				U = (U+1%MAX);
				Fila[U]=dato;
				cantidad++;
			} else
			cout<<"No se puede insertar"<<endl;
		}
	
	void Desencolar (){   
		if (cantidad!=0){
			P=(P+1%MAX);
			cantidad--;
		}else	
			cout<<"No se puede eliminar";
	}
	
	int verPrimero (){   // FRONT
	   return Fila[P];
		
	}

	int verUltimo (){    // BACK
		return Fila[U];
	}  
	
	int getCantidad(){ 
	    cout<< cantidad; return cantidad;}
	
	 

}
cola,colab,colac,colaaux;





	



void SubmenuA(int op,int dato){do{
		system("cls");
		cout<<"[Menu de opciones]"<<endl;
		cout<<"[1] -Insertar / Encolar"<<endl;
		cout<<"[2] -Suprimir / Desencolar"<<endl;
		cout<<"[3] -Ver el primero"<<endl;
		cout<<"[4] -Ver el ultimo"<<endl;
		cout<<"[5] -Cola Vacia?"<<endl;
		cout<<"[6] -Cola Llena?"<<endl;
		cout<<"[7] -Vaciar"<<endl;
		cout<<"[8] -Cuantos elementos hay??"<<endl;
		cout<<"[0] -VOLVER"<<endl;
		cin>>op;
		switch(op){
			case 0: cout<<"VOLVIENDO"<<endl; break;
			case 1: if (!cola.ColaLlena()){
				cout<<"Ingrese su numero"<<endl;
				cin>>dato;
				cola.Encolar(dato);
				cout<<"Elemento insertado."<<endl;}
				else cout<<"La cola esta llena"<<endl;
				break;
			case 2:
				if (!cola.ColaVacia()){
					cout<<"Elemento removido"<<cola.verPrimero()<<endl;
					cola.Desencolar();}
					else cout<<"No hay elementos"<<endl; break;
			case 3: cout<<"PRIMERO de la cola: "<<cola.verPrimero()<<endl; break;
			case 4:	cout<<"Ultimo de la cola: "<<cola.verUltimo()<<endl; break;
			case 5: if(cola.ColaVacia()) cout<<"Esta vacia"<<endl; else cout<<"No esta vacia"<<endl; break;
			case 6: if(cola.ColaLlena()) cout<<"Esta Llena"<<endl; else cout<<"No esta Llena"<<endl; break;	
			case 7: if(!cola.ColaVacia()){
				cout<<"Vaciando la fila"<<endl;
				for(int i=-1;i<=cola.getCantidad(); i++){
					cout<<" Elemento "<<i+1<<" era: "<<cola.verPrimero()<<endl;
					cola.Desencolar();
				}}else cout<<"No hay elementos"<<endl; break;
			case 8: cout<<"En la cola hay: "<<cola.getCantidad()<<" elementos."<<endl; break;	
				
			}	system("PAUSE");
	}while(op!=0); 
	}

void SubmenuB(int op,int dato){do{
		system("cls");
		cout<<"[Menu de opciones]"<<endl;
		cout<<"[1] -Insertar / Encolar"<<endl;
		cout<<"[2] -Suprimir / Desencolar"<<endl;
		cout<<"[3] -Ver el primero"<<endl;
		cout<<"[4] -Ver el ultimo"<<endl;
		cout<<"[5] -Cola Vacia?"<<endl;
		cout<<"[6] -Cola Llena?"<<endl;
		cout<<"[7] -Vaciar"<<endl;
		cout<<"[8] -Cuantos elementos hay??"<<endl;
		cout<<"[0] -VOLVER"<<endl;
		cin>>op;
		switch(op){
			case 0: cout<<"VOLVIENDO"<<endl; break;
			case 1: if (!colab.ColaLlena()){
				cout<<"Ingrese su numero"<<endl;
				cin>>dato;
				colab.Encolar(dato);
				cout<<"Elemento insertado."<<endl;}
				else cout<<"La cola esta llena"<<endl;
				break;
			case 2:
				if (!colab.ColaVacia()){
					cout<<"Elemento removido"<<colab.verPrimero()<<endl;
					colab.Desencolar();}
					else cout<<"No hay elementos"<<endl; break;
			case 3: cout<<"PRIMERO de la cola: "<<colab.verPrimero()<<endl; break;
			case 4:	cout<<"Ultimo de la cola: "<<colab.verUltimo()<<endl; break;
			case 5: if(colab.ColaVacia()) cout<<"Esta vacia"<<endl; else cout<<"No esta vacia"<<endl; break;
			case 6: if(colab.ColaLlena()) cout<<"Esta Llena"<<endl; else cout<<"No esta Llena"<<endl; break;	
			case 7: if(!colab.ColaVacia()){
				cout<<"Vaciando la fila"<<endl;
				for(int i=-1;i<=colab.getCantidad(); i++){
					cout<<" Elemento "<<i+1<<" era: "<<colab.verPrimero()<<endl;
					colab.Desencolar();
				}}else cout<<"No hay elementos"<<endl; break;
			case 8: cout<<"En la cola hay: "<<colab.getCantidad()<<" elementos."<<endl; break;	
				
			}	system("PAUSE");
	}while(op!=0); 
	}

void SubmenuC(int op,int dato){do{
		system("cls");
		cout<<"[Menu de opciones]"<<endl;
		cout<<"[1] -Insertar / Encolar"<<endl;
		cout<<"[2] -Suprimir / Desencolar"<<endl;
		cout<<"[3] -Ver el primero"<<endl;
		cout<<"[4] -Ver el ultimo"<<endl;
		cout<<"[5] -Cola Vacia?"<<endl;
		cout<<"[6] -Cola Llena?"<<endl;
		cout<<"[7] -Vaciar"<<endl;
		cout<<"[8] -Cuantos elementos hay??"<<endl;
		cout<<"[0] -VOLVER"<<endl;
		cin>>op;
		switch(op){
			case 0: cout<<"VOLVIENDO"<<endl; break;
			case 1: if (!colac.ColaLlena()){
				cout<<"Ingrese su numero"<<endl;
				cin>>dato;
				colac.Encolar(dato);
				cout<<"Elemento insertado."<<endl;}
				else cout<<"La cola esta llena"<<endl;
				break;
			case 2:
				if (!colac.ColaVacia()){
					cout<<"Elemento removido"<<colac.verPrimero()<<endl;
					colac.Desencolar();}
					else cout<<"No hay elementos"<<endl; break;
			case 3: cout<<"PRIMERO de la cola: "<<colac.verPrimero()<<endl; break;
			case 4:	cout<<"Ultimo de la cola: "<<colac.verUltimo()<<endl; break;
			case 5: if(colac.ColaVacia()) cout<<"Esta vacia"<<endl; else cout<<"No esta vacia"<<endl; break;
			case 6: if(colac.ColaLlena()) cout<<"Esta Llena"<<endl; else cout<<"No esta Llena"<<endl; break;	
			case 7: if(!colac.ColaVacia()){
				cout<<"Vaciando la fila"<<endl;
				for(int i=-1;i<=colac.getCantidad(); i++){
					cout<<" Elemento "<<i+1<<" era: "<<colac.verPrimero()<<endl;
					colac.Desencolar();
				}}else cout<<"No hay elementos"<<endl; break;
			case 8: cout<<"En la cola hay: "<<colac.getCantidad()<<" elementos."<<endl; break;	
				
			}	system("PAUSE");
	}while(op!=0); 
	}
	
	
	
int main(){

	int dato, op;
	
	do{
		system("cls");
		cout<<"[Menu de PRINCIPAL]"<<endl;
		cout<<"[1] -Opciones Fila A"<<endl;
		cout<<"[2] -Opciones Fila B"<<endl;
		cout<<"[3] -Opciones Fila C"<<endl;
		cout<<"[4] -Opciones Pila P"<<endl;
		cout<<"[5] -Ivertir y mostrar Fila A"<<endl;
		cout<<"[6] -Buscar un numero entero en la Fila A"<<endl;
		cout<<"[7] -Combinar la Fila A y B en Una Fila C"<<endl;
		cout<<"[8] -Eliminar elementos repetidos de la Fila C"<<endl;
		cout<<"[0] -SALIR"<<endl;
		cin>>op;
		switch(op){ 
		
		case 1: {SubmenuA(op, dato);
			break;}
		case 2:	{SubmenuB(op, dato);
			break;}
		case 3: {SubmenuC(op, dato);
			break;}	
		case 5: {	break;}
		
		
	}	
	}while(op!=0);
	
	
	
	
	
	
	
	
	

	
	
	
return 0;}
